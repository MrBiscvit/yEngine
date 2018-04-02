// 
// MIT License
// 
// Copyright(c) 2018 Hubert Gruniaux
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 

#pragma once

#include <yCore/yCore.h>
#include <initializer_list>
#include <iterator>
#include <algorithm>

template<typename T>
class yCORE_API yVector
{
public:
	// STL typedefs
	typedef T value_type;
	typedef T & reference;
	typedef const T & const_reference;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	// Forward declaration
	class const_iterator;

	// Iterator
	class iterator
	{
	private:
		T * _p;
		friend class yVector<T>;

	public:
		inline iterator() : _p(nullptr) { }
		inline iterator(T * p) : _p(p) { }
		inline iterator(const yVector<T> & vec) : _p(vec._data) { }

		// STL-style iterator
		inline iterator & operator++() { ++_p; return *this; }
		inline iterator operator++(int) const { iterator t(*this); ++_p; return t; }
		inline iterator & operator--() { --_p; return *this; }
		inline iterator operator--(int) const { iterator t(*this); --_p; return t; }
		inline iterator & operator+=(difference_type diff) { _p += diff; return *this; }
		inline iterator operator+(difference_type diff) const { iterator t(*this); t += diff; return t; }
		inline iterator & operator-=(difference_type diff) { _p -= diff; return *this; }
		inline iterator operator-(difference_type diff) const { iterator t(*this); t -= diff; return t; }
		inline iterator operator[](difference_type diff) const { return operator+(diff); }
		inline T & operator*() { return (*_p); }
		inline T * operator->() { return _p; }
		inline bool operator<(const iterator & other) const { return _p < other._p; }
		inline bool operator<=(const iterator & other) const { return _p <= other._p; }
		inline bool operator>(const iterator & other) const { return _p > other._p; }
		inline bool operator>=(const iterator & other) const { return _p >= other._p; }
		inline bool operator==(const iterator & other) const { return _p == other._p; }
		inline bool operator!=(const iterator & other) const { return _p != other._p; }

		// Java-style iterator
		inline bool hasNext() const { return (_p++) != nullptr; }
		inline bool hasPrevious() const { return (_p--) != nullptr; }
		inline T & next() { ++_p; return (*_p); }
		inline T & peekNext() { return (*(_p++)); }
		inline T & previous() { --_p; return (*_p); }
		inline T & peekPrevious() { return (*(_p--)); }
	};

	// Constant iterator
	class const_iterator
	{
	private:
		const T * _p;
		friend class yVector<T>;

	public:
		inline const_iterator() : _p(nullptr) { }
		inline const_iterator(T * p) : _p(p) { }
		inline const_iterator(const iterator & it) : _p(it._p) { }
		inline const_iterator(const yVector<T> & vec) : _p(vec._data) { }

		// STL-style iterator
		inline iterator & operator++() { ++_p; return *this; }
		inline iterator operator++(int) const { iterator t(*this); ++_p; return t; }
		inline iterator & operator--() { --_p; return *this; }
		inline iterator operator--(int) const { iterator t(*this); --_p; return t; }
		inline iterator & operator+=(difference_type diff) { _p += diff; return *this; }
		inline iterator operator+(difference_type diff) const { iterator t(*this); t += diff; return t; }
		inline iterator & operator-=(difference_type diff) { _p -= diff; return *this; }
		inline iterator operator-(difference_type diff) const { iterator t(*this); t -= diff; return t; }
		inline iterator operator[](difference_type diff) const { return operator+(diff); }
		inline const T & operator*() { return (*_p); }
		inline const T * operator->() { return _p; }
		inline bool operator<(const iterator & other) const { return _p < other._p; }
		inline bool operator<=(const iterator & other) const { return _p <= other._p; }
		inline bool operator>(const iterator & other) const { return _p > other._p; }
		inline bool operator>=(const iterator & other) const { return _p >= other._p; }
		inline bool operator==(const iterator & other) const { return _p == other._p; }
		inline bool operator!=(const iterator & other) const { return _p != other._p; }

		// Java-style iterator
		inline bool hasNext() const { return (_p++) != nullptr; }
		inline bool hasPrevious() const { return (_p--) != nullptr; }
		inline const T & next() { ++_p; return (*_p); }
		inline const T & peekNext() { return (*(_p++)); }
		inline const T & previous() { --_p; return (*_p); }
		inline const T & peekPrevious() { return (*(_p--)); }
	};

	friend class iterator;
	friend class const_iterator;

	// Reverse iterators
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	// Java typedefs
	typedef iterator Iterator;
	typedef reverse_iterator ReverseIterator;
	typedef const_iterator ConstIterator;
	typedef const_reverse_iterator ConstReverseIterator;

	inline size_type size() const { return _size; }
	inline size_type length() const { return _size; }
	inline size_type count() const { return _size; }
	inline bool empty() const { return !_size; }
	inline bool isEmpty() const { return !_size; }

	void reserve(size_type size);
	void resize(size_type size, const T & value = T());
	void clear();
	void squeeze();
	inline void shrink_to_fit() { squeeze(); }
	inline size_type capacity() const { return _capacity; }



private:
	size_type _size;
	size_type _capacity;
	T * _data;
};