#pragma once

#include <yCore/yCore.h>

// TODO: Finish implementation of yByteArray

class yCORE_API yByteArray
{
public:
	yByteArray();
	yByteArray(int size);
	yByteArray(int size, const ybyte & byte);
	yByteArray(int size, const char & byte);
	yByteArray(const ybyte * bytes, int size);
	yByteArray(const char * bytes, int size);
	yByteArray(const char * string);
	yByteArray(std::initializer_list<ybyte> & list);
	template<typename InputIterator>
	yByteArray(InputIterator first, InputIterator last);
	virtual ~yByteArray();

	typedef ybyte * iterator;
	typedef const ybyte * const_iterator;
	typedef iterator Iterator;
	typedef const_iterator ConstIterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef int size_type;
	typedef yint64 difference_type;
	typedef const ybyte & const_reference;
	typedef ybyte & reference;
	typedef const ybyte * const_pointer;
	typedef ybyte * pointer;
	typedef ybyte value_type;

	inline int size() const { return _size; }
	inline int length() const { return _size; }
	inline int count() const { return _size; }
	inline bool empty() const { return _size == 0; }
	inline bool isEmpty() const { return _size == 0; }

	inline ybyte & front() { return at(0); }
	inline const ybyte & front() const { return at(0); }
	inline ybyte & first() { return front(); }
	inline const ybyte & first() const { return front(); }
	inline const ybyte & constFirst() const { return front(); }
	inline ybyte & back() { return at(_size - 1); }
	inline const ybyte & back() const { return at(_size - 1); }
	inline ybyte & last() { return back(); }
	inline const ybyte & last() const { return back(); }
	inline const ybyte & constLast() const { return back(); }
	inline const ybyte & at(int index) const { return _data[index]; }
	inline ybyte & at(int index) { yASSERT(index >= 0 && index < _size); return _data[index]; }
	inline ybyte value(int index, const ybyte & defaultVal = (ybyte)'\0') const { return (index >= 0 && index < _size) ? at(index) : defaultVal; }
	inline ybyte value(int index, const char & defaultVal = '\0') const { return value(index, (ybyte)defaultVal); }

	inline ybyte * data() { return _data; }
	inline const ybyte * data() const { return _data; }
	inline const ybyte * constData() const { return _data; }

	void clear();
	void reserve(int size);
	void squeeze();
	inline void shrink_to_fit() { squeeze(); }
	inline int capacity() const { return _capacity; }
	void resize(int size, ybyte fill = (ybyte)'\0');
	inline void resize(int size, char fill = '\0') { resize(size, (ybyte)fill); }

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

	yByteArray & insert(int index, const ybyte & byte);
	inline yByteArray & insert(int index, const char & byte) { return insert(index, (ybyte)byte); }
	inline yByteArray & insert(int index, const ybyte * bytes, int length) { return insert(index, yByteArray(bytes, length)); }
	inline yByteArray & insert(int index, const char * bytes, int length) { return insert(index, yByteArray(bytes, length)); }
	inline yByteArray & insert(int index, const char * string) { return insert(index, yByteArray(string)); }
	inline yByteArray & insert(int index, int count, const ybyte & byte) { return insert(index, yByteArray(count, byte)); }
	inline yByteArray & insert(int index, int count, const char & byte) { return insert(index, yByteArray(count, byte)); }
	yByteArray & insert(int index, const yByteArray & vec);

	yByteArray & append(const ybyte & value);
	inline yByteArray & append(const char & byte) { return append((ybyte)byte); }
	inline yByteArray & append(const ybyte * bytes, int length) { return append(yByteArray(bytes, length)); }
	inline yByteArray & append(const char * bytes, int length) { return append(yByteArray(bytes, length)); }
	inline yByteArray & append(const char * string) { return append(yByteArray(string)); }
	inline yByteArray & append(int count, const ybyte & byte) { return append(yByteArray(count, byte)); }
	inline yByteArray & append(int count, const char & byte) { return append(yByteArray(count, byte)); }
	yByteArray & append(const yByteArray & array);
	inline yByteArray & push_back(const ybyte & value) { return append(value); }
	inline yByteArray & push_back(const yByteArray & array) { return append(array); }

	yByteArray & prepend(const ybyte & value);
	inline yByteArray & prepend(const char & byte) { return prepend((ybyte)byte); }
	inline yByteArray & prepend(const ybyte * bytes, int length) { return prepend(yByteArray(bytes, length)); }
	inline yByteArray & prepend(const char * bytes, int length) { return prepend(yByteArray(bytes, length)); }
	inline yByteArray & prepend(const char * string) { return prepend(yByteArray(string)); }
	inline yByteArray & prepend(int count, const ybyte & byte) { return prepend(yByteArray(count, byte)); }
	inline yByteArray & prepend(int count, const char & byte) { return prepend(yByteArray(count, byte)); }
	yByteArray & prepend(const yByteArray & array);
	inline yByteArray & push_front(const ybyte & value) { return prepend(value); }
	inline yByteArray & push_front(const yByteArray& array) { return prepend(array); }

	yByteArray & remove(int index);
	yByteArray & remove(int index, int length);
	yByteArray & removeAll(const ybyte & t);
	yByteArray & removeOne(const ybyte & t);
	inline yByteArray & removeAt(int i) { return remove(i); }
	inline yByteArray & removeFirst() { return remove(0); }
	inline yByteArray & removeLast() { return remove(_size - 1); }
	inline yByteArray & pop_front() { return removeFirst(); }
	inline yByteArray & pop_back() { return removeLast(); }

	inline iterator erase(iterator position) { iterator t = position + 1; remove(int(position - begin())); return t; }
	inline iterator erase(iterator first, iterator last) { iterator t = last + 1; remove(int(first - begin()), int(first - begin() + last - first)); return t; }

	inline ybyte takeAt(int index) { ybyte t = at(index); remove(index); return index; }
	inline ybyte takeFirst() { ybyte t = first(); removeFirst(); return t; }
	inline ybyte takeLast() { ybyte t = last(); removeLast(); return t; }

	void replace(int index, const ybyte & value);

	int count(const ybyte & value) const;
	int indexOf(const ybyte & value, int from = 0) const;
	int lastIndexOf(const ybyte & value, int from = 0) const;
	inline bool contains(const ybyte & value) const { return indexOf(value) != -1; }

	inline bool startsWith(const ybyte & value) const { yASSERT(!isEmpty()); return _data[0] == value; }
	inline bool endsWith(const ybyte & value) const { yASSERT(!isEmpty()); return _data[_size - 1] == value; }

	yByteArray mid(int pos, int length = -1) const;
	inline yByteArray left(int length) const { return mid(0, length); }
	inline yByteArray right(int length) const { return mid(_size - 1 - length, length); }

private:
	int _size;
	int _capacity;
	ybyte * _data;
};
