#include <yCore/yVector.h>

template<typename T>
yVector<T>::yVector()
{
	reserve(0);
	_size = 0;
	_capacity = 0;
}
template<typename T>
yVector<T>::yVector(int size)
{
	reserve(size);
	_size = size;
}
template<typename T>
yVector<T>::yVector(int size, const T & value)
{
	resize(size, value);
}
template<typename T>
yVector<T>::yVector(const T * values, int size)
{
	reserve(size);
	_size = size;
	for (int i(0); i < _size; ++i)
		_data[i] = values[i];
}
template<typename T>
yVector<T>::yVector(const std::vector<T>& vec)
{
	reserve(vec.size());
	_size = vec.size();
	for (int i(0); i < _size; ++i)
		_data[i] = vec[i];
}
template<typename T>
yVector<T>::yVector(std::initializer_list<T>& list)
{
	reserve(list.size());
	_size = list.size();
	for (int i(0); i < _size; ++i)
		_data[i] = list.begin()[i];
}
template<typename T>
template<typename InputIterator>
inline yVector<T>::yVector(InputIterator first, InputIterator last)
{
	int size = last - first;
	reserve(size);
	_size = size;
	for (int i(0); i < size; ++i)
		_data[i] = first[i];
}
template<typename T>
yVector<T>::~yVector()
{
	clear();
}

template<typename T>
void yVector<T>::clear()
{
	if (_data)
		delete[] _data;

	_size = 0;
	_capacity = 0;
}
template<typename T>
void yVector<T>::reserve(int size)
{
	if (size <= _size + _capacity)
		return;

	if (_data) {
		T * tmp = new T[_size];
		memcpy(tmp, _data, _size);
		delete[] _data;
		_data = new T[_size + _capacity + size];
		memmove(_data, tmp, _size);
		_capacity += size;
	} else {
		_data = new T[size];
		_capacity = size;
		_size = 0;
	}
}
template<typename T>
void yVector<T>::squeeze()
{
	if (_capacity == 0 || !_data)
		return;

	T * tmp = new T[_size];
	memcpy(tmp, _data, _size);
	delete[] _data;
	_data = new T[_size];
	memmove(_data, tmp, _size);
	_capacity = 0;
}
template<typename T>
void yVector<T>::resize(int size, T fill)
{
	int preSize = _size;

	if (_data) {
		T * tmp = new T[_size];
		memcpy(tmp, _data, _size);
		delete[] _data;
		_data = new T[size];
		memmove(_data, tmp, std::min(size, _size));
		_size = size;
		_capacity -= size;
		if (_capacity < 0)
			_capacity = 0;
	} else {
		_data = new T[size];
		_capacity = 0;
		_size = size;
	}

	if (preSize <= size)
		return;

	for (int i(preSize); i < _size; ++i)
		_data[i] = fill;
}

template<typename T>
yVector<T>& yVector<T>::insert(int index, const T & value)
{
	yASSERT(index >= 0 && index <= _size);

	if (_capacity <= 0)
		reserve(1);

	for (int i(_size); i >= index; --i)
		_data[i + 1] = _data[i];

	_data[index] = value;

	return *this;
}
template<typename T>
yVector<T>& yVector<T>::insert(int index, T && value)
{
	insert(index, value);
	value = T();
	return *this;
}
template<typename T>
yVector<T>& yVector<T>::insert(int index, const yVector<T>& vec)
{
	yASSERT(index >= 0 && index <= _size);

	int remainingCapacity = _capacity - vec._size;
	if (remainingCapacity <= 0)
		reserve(std::abs(remainingCapacity));

	for (int i(_size + vec._size); i >= index; --i)
		_data[i + vec._size] = _data[i];

	for (int i(0); i < vec._size; ++i)
		_data[i + index] = vec._data[i];

	return *this;
}

template<typename T>
yVector<T> & yVector<T>::append(const T & value)
{
	if (_capacity <= 0)
		reserve(1);
	_data[_size - 1] = value;
	--_capacity;
	++_size;
	return *this;
}
template<typename T>
yVector<T> & yVector<T>::append(T && value)
{
	append(value);
	value = T();
	return *this;
}
template<typename T>
yVector<T> & yVector<T>::append(const yVector<T>& vec)
{
	int remainingCapacity = _capacity - vec._size;
	if (remainingCapacity <= 0)
		reserve(std::abs(remainingCapacity));

	for (int i(_size); i < vec._size; ++i)
		_data[i] = vec._data[i - _size];

	_capacity -= vec._size;
	_size += vec._size;

	return *this;
}

template<typename T>
yVector<T>& yVector<T>::prepend(const T & value)
{
	if (_capacity <= 0)
		reserve(1);

	for (int i(_size); i >= 0; --i)
		_data[i] = _data[i - 1];

	--_capacity;
	++_size;

	return *this;
}
template<typename T>
yVector<T>& yVector<T>::prepend(T && value)
{
	prepend(value);
	value = T();
	return *this;
}
template<typename T>
yVector<T>& yVector<T>::prepend(const yVector<T>& vec)
{
	int remainingCapacity = _capacity - vec._size;
	if (remainingCapacity <= 0)
		reserve(std::abs(remainingCapacity));

	for (int i(_size + vec._size); i >= 0; --i)
		_data[i + vec._size] = _data[i];

	for (int i(0); i < vec._size; ++i)
		_data[i] = vec._data[i];

	_capacity -= vec._size;
	_size += vec._size;

	return *this;
}

template<typename T>
yVector<T> & yVector<T>::remove(int index)
{
	yASSERT(index >= 0 && index < _size);

	for (int i(_size); i >= index; --i)
		_data[i - 1] = _data[i];

	--_size;
	++_capacity;

	return *this;
}
template<typename T>
yVector<T> & yVector<T>::remove(int index, int length)
{
	yASSERT(index >= 0 && index < _size);
	yASSERT(index + length < _size);

	for (int i(_size); i >= index; --i)
		_data[i - length] = _data[i];

	_size -= length;
	_capacity += length;

	return *this;
}
template<typename T>
yVector<T>& yVector<T>::removeAll(const T & t)
{
	int index(-1);
	while ((index = indexOf(t)) != -1) {
		remove(index);
	}

	return *this;
}
template<typename T>
yVector<T>& yVector<T>::removeOne(const T & t)
{
	int index = indexOf(t);
	if (index != -1)
		remove(index);
		
	return *this;
}

template<typename T>
void yVector<T>::replace(int index, const T & value)
{
	yASSERT(index >= 0 && index < _size);

	_data[index] = value;
}

template<typename T>
int yVector<T>::count(const T & value) const
{
	int c(0);
	for (const_iterator it(begin()); it != end(); ++it)
		if ((*it) == value)
			++c;
	return c;
}
template<typename T>
int yVector<T>::indexOf(const T & value, int from) const
{
	if (from >= _size)
		return -1;
	if (from < 0)
		from = 0;

	for (const_iterator it(begin() + from); it != end(); ++it)
		if ((*it) == value)
			return int(it - begin());

	return -1;
}
template<typename T>
int yVector<T>::lastIndexOf(const T & value, int from) const
{
	if (from >= _size)
		return -1;
	if (from < 0)
		from = 0;

	for (const_reverse_iterator it(rbegin() + from); it != rend(); ++it)
		if ((*it) == value)
			return int(it - rbegin());

	return -1;
}

template<typename T>
yVector<T> yVector<T>::mid(int pos, int length) const
{
	yASSERT(pos >= 0 && pos < _size);
	if (length < 0)
		length = _size - pos - 1;
	yASSERT(pos + length < _size);

	yVector<T> vec;
	vec.reserve(length);

	for (int i(pos); i < length; ++i)
		vec._data[i - pos] = _data[i];

	return vec;
}