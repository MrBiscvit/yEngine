#include <yCore/yByteArray.h>

yByteArray::yByteArray()
{
	reserve(0);
	_size = 0;
	_capacity = 0;
}
yByteArray::yByteArray(int size)
{
	reserve(size);
	_size = size;
}
yByteArray::yByteArray(int size, const ybyte & byte)
{
	resize(size, byte);
}
yByteArray::yByteArray(int size, const char & byte)
{
	resize(size, byte);
}
yByteArray::yByteArray(const ybyte * bytes, int size)
{
	reserve(size);
	_size = size;
	for (int i(0); i < _size; ++i)
		_data[i] = bytes[i];
}
yByteArray::yByteArray(const char * bytes, int size)
{
	reserve(size);
	_size = size;
	for (int i(0); i < _size; ++i)
		_data[i] = (ybyte)bytes[i];
}
yByteArray::yByteArray(const char * string)
{
	_size = int(strlen(string));
	reserve(_size);
	for (int i(0); i < _size; ++i)
		_data[i] = (ybyte)string[i];
}
yByteArray::yByteArray(std::initializer_list<ybyte>& list)
{
	reserve(int(list.size()));
	_size = int(list.size());
	for (int i(0); i < _size; ++i)
		_data[i] = list.begin()[i];
}
template<typename InputIterator>
yByteArray::yByteArray(InputIterator first, InputIterator last)
{
	int size = last - first;
	reserve(size);
	_size = size;
	for (int i(0); i < size; ++i)
		_data[i] = first[i];
}
yByteArray::~yByteArray()
{
	clear();
}

void yByteArray::clear()
{
	if (_data)
		delete[ ] _data;

	_size = 0;
	_capacity = 0;
}
void yByteArray::reserve(int size)
{
	if (size <= _size + _capacity)
		return;

	if (_data) {
		ybyte * tmp = new ybyte[_size];
		memcpy(tmp, _data, _size);
		delete[ ] _data;
		_data = new ybyte[_size + _capacity + size];
		memmove(_data, tmp, _size);
		_capacity += size;
	} else {
		_data = new ybyte[size];
		_capacity = size;
		_size = 0;
	}
}
void yByteArray::squeeze()
{
	if (_capacity == 0 || !_data)
		return;

	ybyte * tmp = new ybyte[_size];
	memcpy(tmp, _data, _size);
	delete[ ] _data;
	_data = new ybyte[_size];
	memmove(_data, tmp, _size);
	_capacity = 0;
}
void yByteArray::resize(int size, ybyte fill)
{
	int preSize = _size;

	if (_data) {
		ybyte * tmp = new ybyte[_size];
		memcpy(tmp, _data, _size);
		delete[ ] _data;
		_data = new ybyte[size];
		memmove(_data, tmp, std::min(size, _size));
		_size = size;
		_capacity -= size;
		if (_capacity < 0)
			_capacity = 0;
	} else {
		_data = new ybyte[size];
		_capacity = 0;
		_size = size;
	}

	if (preSize <= size)
		return;

	for (int i(preSize); i < _size; ++i)
		_data[i] = fill;
}

yByteArray& yByteArray::insert(int index, const ybyte & byte)
{
	yASSERT(index >= 0 && index <= _size);

	if (_capacity <= 0)
		reserve(1);

	for (int i(_size); i >= index; --i)
		_data[i + 1] = _data[i];

	_data[index] = byte;

	return *this;
}
yByteArray& yByteArray::insert(int index, const yByteArray& vec)
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

yByteArray & yByteArray::append(const ybyte & value)
{
	if (_capacity <= 0)
		reserve(1);
	_data[_size - 1] = value;
	--_capacity;
	++_size;
	return *this;
}
yByteArray & yByteArray::append(const yByteArray& vec)
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

yByteArray& yByteArray::prepend(const ybyte & value)
{
	if (_capacity <= 0)
		reserve(1);

	for (int i(_size); i >= 0; --i)
		_data[i] = _data[i - 1];

	--_capacity;
	++_size;

	return *this;
}
yByteArray& yByteArray::prepend(const yByteArray& vec)
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

yByteArray & yByteArray::remove(int index)
{
	yASSERT(index >= 0 && index < _size);

	for (int i(_size); i >= index; --i)
		_data[i - 1] = _data[i];

	--_size;
	++_capacity;

	return *this;
}
yByteArray & yByteArray::remove(int index, int length)
{
	yASSERT(index >= 0 && index < _size);
	yASSERT(index + length < _size);

	for (int i(_size); i >= index; --i)
		_data[i - length] = _data[i];

	_size -= length;
	_capacity += length;

	return *this;
}
yByteArray& yByteArray::removeAll(const ybyte & t)
{
	int index(-1);
	while ((index = indexOf(t)) != -1) {
		remove(index);
	}

	return *this;
}
yByteArray& yByteArray::removeOne(const ybyte & t)
{
	int index = indexOf(t);
	if (index != -1)
		remove(index);

	return *this;
}

void yByteArray::replace(int index, const ybyte & value)
{
	yASSERT(index >= 0 && index < _size);

	_data[index] = value;
}

int yByteArray::count(const ybyte & value) const
{
	int c(0);
	for (const_iterator it(begin()); it != end(); ++it)
		if ((*it) == value)
			++c;
	return c;
}
int yByteArray::indexOf(const ybyte & value, int from) const
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
int yByteArray::lastIndexOf(const ybyte & value, int from) const
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

yByteArray yByteArray::mid(int pos, int length) const
{
	yASSERT(pos >= 0 && pos < _size);
	if (length < 0)
		length = _size - pos - 1;
	yASSERT(pos + length < _size);

	yByteArray vec;
	vec.reserve(length);

	for (int i(pos); i < length; ++i)
		vec._data[i - pos] = _data[i];

	return vec;
}