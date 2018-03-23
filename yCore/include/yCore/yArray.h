#pragma once

#include <yCore/yCore.h>
#include <initializer_list>
#include <array>

template<typename T, yuint N>
class yCORE_API yArray
{
public:
	yArray();
	yArray(const T * values, int size);
	yArray(T values[N]);
	yArray(const std::array<T, N> & array);
	yArray(std::initializer_list<T> & list);
	template<typename InputIterator>
	yArray(InputIterator first, InputIterator last);

	typedef T * iterator;
	typedef const T * const_iterator;
	typedef iterator Iterator;
	typedef const_iterator ConstIterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef int size_type;
	typedef yint64 difference_type;
	typedef const T & const_reference;
	typedef T & reference;
	typedef const T * const_pointer;
	typedef T * pointer;
	typedef T value_type;

	inline int size() const { return N; }
	inline int length() const { return N; }
	inline int count() const { return N; }
	inline bool empty() const { return N == 0; }
	inline bool isEmpty() const { return N == 0; }

	inline T & front() { return at(0); }
	inline const T & front() const { return at(0); }
	inline T & first() { return front(); }
	inline const T & first() const { return front(); }
	inline const T & constFirst() const { return front(); }
	inline T & back() { return at(N - 1); }
	inline const T & back() const { return at(N - 1); }
	inline T & last() { return back(); }
	inline const T & last() const { return back(); }
	inline const T & constLast() const { return back(); }
	inline const T & at(int index) const { return _data[index]; }
	inline T & at(int index) { yASSERT(index >= 0 && index < N); return _data[index]; }
	inline T value(int index, const T & defaultVal = T()) const { return (index >= 0 && index < N) ? at(index) : defaultVal; }

	inline T * data() { return _data; }
	inline const T * data() const { return _data; }
	inline const T * constData() const { return _data; }

	inline iterator begin() { return _data; }
	inline const_iterator begin() const { return _data; }
	inline const_iterator cbegin() const { return _data; }
	inline const_iterator constBegin() const { return _data; }
	inline iterator end() { return _data + N; }
	inline const_iterator end() const { return _data + N; }
	inline const_iterator cend() const { return _data + N; }
	inline const_iterator constEnd() const { return _data + N; }
	inline reverse_iterator rbegin() { return reverse_iterator(begin()); }
	inline const_reverse_iterator rbegin() const { return const_reverse_iterator(cbegin()); }
	inline const_reverse_iterator crbegin() const { return const_reverse_iterator(cbegin()); }
	inline reverse_iterator rend() { return reverse_iterator(end()); }
	inline const_reverse_iterator rend() const { return const_reverse_iterator(cend()); }
	inline const_reverse_iterator crend() const { return const_reverse_iterator(cend()); }

	void replace(int index, const T & value);

	int count(const T & value) const;
	int indexOf(const T & value, int from = 0) const;
	int lastIndexOf(const T & value, int from = 0) const;
	inline bool contains(const T & value) const { return indexOf(value) != -1; }

	inline bool startsWith(const T & value) const { yASSERT(!isEmpty()); return _data[0] == value; }
	inline bool endsWith(const T & value) const { yASSERT(!isEmpty()); return _data[N - 1] == value; }

	yArray<T, N> mid(int pos, int length = -1) const;
	inline yArray<T, N> left(int length) const { return mid(0, length); }
	inline yArray<T, N> right(int length) const { return mid(_size - 1 - length, length); }

private:
	T _data[N];
};