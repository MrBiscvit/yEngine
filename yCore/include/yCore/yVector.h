#pragma once

#include <yCore/yCore.h>
#include <initializer_list>
#include <vector>

template<typename T>
class yCORE_API yVector
{
public:
	yVector();
	yVector(int size);
	yVector(int size, const T & value);
	yVector(const T * values, int size);
	yVector(const std::vector<T> & vec);
	yVector(std::initializer_list<T> & list);
	template<typename InputIterator>
	yVector(InputIterator first, InputIterator last);
	virtual ~yVector();

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

	inline int size() const { return _size; }
	inline int length() const { return _size; }
	inline int count() const { return _size; }
	inline bool empty() const { return _size == 0; }
	inline bool isEmpty() const { return _size == 0; }

	inline T & front() { return at(0); }
	inline const T & front() const { return at(0); }
	inline T & first() { return front(); }
	inline const T & first() const { return front(); }
	inline const T & constFirst() const { return front(); }
	inline T & back() { return at(_size - 1); }
	inline const T & back() const { return at(_size - 1); }
	inline T & last() { return back(); }
	inline const T & last() const { return back(); }
	inline const T & constLast() const { return back(); }
	inline const T & at(int index) const { return _data[index]; }
	inline T & at(int index) { yASSERT(index >= 0 && index < _size); return _data[index]; }
	inline T value(int index, const T & defaultVal = T()) const { return (index >= 0 && index < _size) ? at(index) : defaultVal; }

	inline T * data() { return _data; }
	inline const T * data() const { return _data; }
	inline const T * constData() const { return _data; }

	void clear();
	void reserve(int size);
	void squeeze();
	inline void shrink_to_fit() { squeeze(); }
	inline int capacity() const { return _capacity; }
	void resize(int size, T fill = T());

	inline iterator begin() { return _data; }
	inline const_iterator begin() const { return _data; }
	inline const_iterator cbegin() const { return _data; }
	inline const_iterator constBegin() const { return _data; }
	inline iterator end() { return _data + _size; }
	inline const_iterator end() const { return _data + _size; }
	inline const_iterator cend() const { return _data + _size; }
	inline const_iterator constEnd() const { return _data + _size; }
	inline reverse_iterator rbegin() { return reverse_iterator(begin()); }
	inline const_reverse_iterator rbegin() const { return const_reverse_iterator(cbegin()); }
	inline const_reverse_iterator crbegin() const { return const_reverse_iterator(cbegin()); }
	inline reverse_iterator rend() { return reverse_iterator(end()); }
	inline const_reverse_iterator rend() const { return const_reverse_iterator(cend()); }
	inline const_reverse_iterator crend() const { return const_reverse_iterator(cend()); }

	yVector<T> & insert(int index, const T & value);
	yVector<T> & insert(int index, T && value);
	yVector<T> & insert(int index, const yVector<T> & vec);

	yVector<T> & append(const T & value);
	yVector<T> & append(T && value);
	yVector<T> & append(const yVector<T> & vec);
	inline yVector<T> & push_back(const T & value) { return append(value); }
	inline yVector<T> & push_back(T && value) { return append(value); }
	inline yVector<T> & push_back(const yVector<T> & vec) { return append(vec); }

	yVector<T> & prepend(const T & value);
	yVector<T> & prepend(T && value);
	yVector<T> & prepend(const yVector<T> & vec);
	inline yVector<T> & push_front(const T & value) { return prepend(value); }
	inline yVector<T> & push_front(T && value) { return prepend(value); }
	inline yVector<T> & push_front(const yVector<T> & vec) { return prepend(vec); }

	yVector<T> & remove(int index);
	yVector<T> & remove(int index, int length);
	yVector<T> & removeAll(const T & t);
	yVector<T> & removeOne(const T & t);
	inline yVector<T> & removeAt(int i) { return remove(i); }
	inline yVector<T> & removeFirst() { return remove(0); }
	inline yVector<T> & removeLast() { return remove(_size - 1); }
	inline yVector<T> & pop_front() { return removeFirst(); }
	inline yVector<T> & pop_back() { return removeLast(); }

	inline iterator erase(iterator position) { iterator t = position + 1; remove(int(position - begin())); }
	inline iterator erase(iterator first, iterator last) { iterator t = last + 1; remove(int(first - begin()), int(first - begin() + last - first)); }

	inline T takeAt(int index) { T t = at(index); remove(index); return index; }
	inline T takeFirst() { T t = first(); removeFirst(); return t; }
	inline T takeLast() { T t = last(); removeLast(); return t; }

	void replace(int index, const T & value);
		
	int count(const T & value) const;
	int indexOf(const T & value, int from = 0) const;
	int lastIndexOf(const T & value, int from = 0) const;
	inline bool contains(const T & value) const { return indexOf(value) != -1; }

	inline bool startsWith(const T & value) const { yASSERT(!isEmpty()); return _data[0] == value; }
	inline bool endsWith(const T & value) const { yASSERT(!isEmpty()); return _data[_size - 1] == value; }

	yVector<T> mid(int pos, int length = -1) const;
	inline yVector<T> left(int length) const { return mid(0, length); }
	inline yVector<T> right(int length) const { return mid(_size - 1 - length, length); }

private:
	int _size;
	int _capacity;
	T * _data;
};