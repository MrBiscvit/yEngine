#include <yCore/yArray.h>

template<typename T, yuint N>
yArray<T, N>::yArray()
{
	for (int i(0); i N; i++)
		_data[i] = T();
}
template<typename T, yuint N>
yArray<T, N>::yArray(const T * values, int size)
{
	yASSERT(size >= 0 && size < N);

	for (int i(0); i < yMin(size, N); i++)
		_data[i] = values[i];
}
template<typename T, yuint N>
yArray<T, N>::yArray(T values[N])
{
	for (int i(0); i < N; ++i)
		_data[i] = values[i];
}
template<typename T, yuint N>
yArray<T, N>::yArray(const std::array<T, N>& array)
{
	yASSERT(array.size() >= 0 && array.size() < N);

	for (std::array<T, N>::iterator it(array.begin()), int i(0); it != array.end(); ++it, ++i)
		_data[i] = *it:
}
template<typename T, yuint N>
yArray<T, N>::yArray(std::initializer_list<T>& list)
{
	for (const T * it(list.begin()), int i(0); it != list.end() && i < yMin(list.size(), N); ++it)
		_data[i] = *it;
}
template<typename T, yuint N>
template<typename InputIterator>
yArray<T, N>::yArray(InputIterator first, InputIterator last) : _data()
{
	int size = first - last;
	yASSERT(size >= 0 && size < N);

	for (InputIterator it(first), int i(0); it != last; ++it, ++i)
		_data[i] = *it:
}

template<typename T, yuint N>
void yArray<T, N>::replace(int index, const T & value)
{
	yASSERT(index >= 0 && index < N);

	_data[index] = value;
}

template<typename T, yuint N>
int yArray<T, N>::count(const T & value) const
{
	int c(0);
	for (const_iterator it(begin()); it != end(); ++it)
		if (*it == value)
			++c;
	return c;
}
template<typename T, yuint N>
int yArray<T, N>::indexOf(const T & value, int from) const
{
	yASSERT(from >= 0 && from < N);

	for(const_iterator it(begin() + from); it != end(); ++it)
		if (*it == value)
			begin() - it;
	return -1;
}
template<typename T, yuint N>
int yArray<T, N>::lastIndexOf(const T & value, int from) const
{
	yASSERT(from >= 0 && from < N);

	for (const_reverse_iterator it(rbegin() + from); it != rend(); ++it)
		if (*it == value)
			rbegin() - it;
	return -1;
}

template<typename T, yuint N>
yArray<T, N> yArray<T, N>::mid(int pos, int length) const
{
	yASSERT(pos >= 0 && pos < N);
	if (length < 0)
		length = N - pos - 1;
	yASSERT(pos + length < N);

	return yArray<T, N>(begin() + pos, begin() + pos + length());
}