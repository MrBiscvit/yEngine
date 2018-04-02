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
class yList;

template<typename T>
class yCORE_API yListNode
{
public:
	// STL typedefs
	typedef T value_type;
	typedef T * pointer;
	typedef T & reference;

	// Data
	T value;
	yListNode<T> * next;
	yListNode<T> * previous;
};

template<typename T>
class yCORE_API yListIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	inline yListIterator() : _node(nullptr) { }
	inline yListIterator(yListNode<T> * node) : _node(node) { }

	// STL typedefs
	typedef T value_type;
	typedef T * pointer;
	typedef T & reference;
	typedef yListNode<value_type> * node_type;
	typedef ptrdiff_t difference_type;
	typedef std::random_access_iterator_tag iterator_category;

	// Java typedefs
	typedef node_type Node;

	// STL-style
	inline yListIterator<T> & operator++() { _node = _node->next; return *this; }
	inline yListIterator<T> operator++(int) { return ++(*this); }
	inline yListIterator<T> & operator--() { _node = _node->previous; return *this; }
	inline yListIterator<T> operator--(int) { return --(*this); }
	inline yListIterator<T> & operator+=(difference_type diff)
	{
		for (; diff > 0; --diff) _node = _node->next;
		return *this;
	}
	inline yListIterator<T> & operator+(difference_type diff) const { return (*this) += diff; }
	inline yListIterator<T> & operator-=(difference_type diff)
	{
		for (; diff > 0; --diff) _node = _node->previous;
		return *this;
	}
	inline yListIterator<T> & operator-(difference_type diff) const { return (*this) -= diff; }
	inline yListIterator<T> & operator[](difference_type diff) const { return (*this) += diff; }
	inline T & operator*() { return _node->value; }
	inline T * operator->() { return &_node->value; }
	inline bool operator==(const yListIterator<T> & other) const { return _node == other._node; }
	inline bool operator!=(const yListIterator<T> & other) const { return _node != other._node; }

	// Java-style
	inline bool hasNext() const { return _node->next != nullptr; }
	inline bool hasPrevious() const { return _node->previous != nullptr; }
	inline T & next() { _node = _node->next; return _node->value; }
	inline T & peekNext() { return _node->next->value; }
	inline T & previous() { _node = _node->previous; return _node->value; }
	inline T & peekPrevious() { return _node->previous->value; }

private:
	yListNode<T> * _node;
	friend class yList<T>;
};

template<typename T>
class yCORE_API yListConstIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	inline yListConstIterator() : _node(nullptr) { }
	inline yListConstIterator(yListNode<T> * node) : _node(node) { }

	// STL typedefs
	typedef const T value_type;
	typedef const T * pointer;
	typedef const T & reference;
	typedef const yListNode<value_type> * node_type;
	typedef ptrdiff_t difference_type;
	typedef std::random_access_iterator_tag iterator_category;

	// Java typedefs
	typedef node_type Node;

	// STL-style
	inline yListIterator<T> & operator++() { _node = _node->next; return *this; }
	inline yListIterator<T> operator++(int) { return ++(*this); }
	inline yListIterator<T> & operator--() { _node = _node->previous; return *this; }
	inline yListIterator<T> operator--(int) { return --(*this); }
	inline yListIterator<T> & operator+=(difference_type diff)
	{
		for (; diff > 0; --diff) _node = _node->next;
		return *this;
	}
	inline yListIterator<T> & operator+(difference_type diff) const { return (*this) += diff; }
	inline yListIterator<T> & operator-=(difference_type diff)
	{
		for (; diff > 0; --diff) _node = _node->previous;
		return *this;
	}
	inline yListIterator<T> & operator-(difference_type diff) const { return (*this) -= diff; }
	inline yListIterator<T> & operator[](difference_type diff) const { return (*this) += diff; }
	inline const T & operator*() { return _node->value; }
	inline const T * operator->() { return &_node->value; }
	inline bool operator==(const yListIterator<T> & other) const { return _node == other._node; }
	inline bool operator!=(const yListIterator<T> & other) const { return _node != other._node; }

	// Java-style
	inline bool hasNext() const { return _node->next != nullptr; }
	inline bool hasPrevious() const { return _node->previous != nullptr; }
	inline const T & next() { _node = _node->next; return _node->value; }
	inline const T & peekNext() { return _node->next->value; }
	inline const T & previous() { _node = _node->previous; return _node->value; }
	inline const T & peekPrevious() { return _node->previous->value; }

private:
	yListNode<T> * _node;
	friend class yList<T>;
};

template<typename T>
class yCORE_API yList
{
public:
	// STL typedefs
	typedef T value_type;
	typedef T & reference;
	typedef const T & const_reference;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef yListIterator<T> iterator;
	typedef yListConstIterator<T> const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef yListNode<value_type> * node_type;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	// Java typedefs
	typedef iterator Iterator;
	typedef const_iterator ConstIterator;
	typedef reverse_iterator ReverseIterator;
	typedef const_reverse_iterator ConstReverseIterator;
	typedef node_type Node;

	inline size_type size() const { return _size; }
	inline size_type length() const { return _size; }
	inline size_type count() const { return _size; }
	inline bool empty() const { return !_size; }
	inline bool isEmpty() const { return !_size; }

	// Iterators functions
	inline iterator begin() { return iterator(_head); }
	inline const_iterator begin() const { return const_iterator(_head); }
	inline const_iterator cbegin() const { return const_iterator(_head); }
	inline const_iterator constBegin() const { return const_iterator(_head); }
	inline iterator end() { return iterator(nullptr); }
	inline const_iterator end() const { return const_iterator(nullptr); }
	inline const_iterator cend() const { return const_iterator(nullptr); }
	inline const_iterator constEnd() const { return const_iterator(nullptr); }
	inline reverse_iterator rbegin() { return std::make_reverse_iterator(begin()); }
	inline const_reverse_iterator rbegin() const { return std::make_reverse_iterator(begin()); }
	inline const_reverse_iterator crbegin() const { return std::make_reverse_iterator(cbegin()); }
	inline const_reverse_iterator constReverseBegin() const { return std::make_reverse_iterator(constBegin()); }
	inline reverse_iterator rend() { return std::make_reverse_iterator(end()); }
	inline const_reverse_iterator rend() const { return std::make_reverse_iterator(end()); }
	inline const_reverse_iterator crend() const { return std::make_reverse_iterator(cend()); }
	inline const_reverse_iterator constReverseEnd() const { return std::make_reverse_iterator(constEnd()); }

	// Insert at position or after iterator
	iterator insert(const_iterator before, const T & value);
	iterator insert(const_iterator before, size_type count, const T & value);
	iterator insert(const_iterator before, T && value);
	iterator insert(const_iterator before, std::initializer_list<T> il);
	template<class InputIterator>
	iterator insert(const_iterator before, InputIterator first, InputIterator last);
	inline void insert(difference_type position, const T & value) { insert(begin() + position, value); }
	inline void insert(difference_type position, size_type count, const T & value) { insert(begin() + position, count, value); }
	inline void insert(difference_type position, T && value) { insert(begin() + position, value); }
	inline void insert(difference_type position, std::initializer_list<T> il) { insert(begin() + position, il); }
	template<class InputIterator>
	inline void insert(difference_type position, InputIterator first, InputIterator last) { insert(begin() + position, first, last); }

	// Append and prepend
	inline void append(const T & value);
	inline void append(T && value);
	inline void append(const yList<T> & list);
	inline void push_back(const T & value) { append(value); }
	inline void push_back(T && value) { append(value); }
	inline void push_back(const yList<T> & list) { append(list); }
	void prepend(const T & value);
	void prepend(T && value);
	void prepend(const yList<T> & list);
	inline void push_front(const T & value) { prepend(value); }
	inline void push_front(T && value) { prepend(value); }
	inline void push_front(const yList<T> & list) { prepend(list); }
		
private:
	size_type _size;
	yListNode<T> * _head;
	yListNode<T> * _tail;
};