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

#ifndef _YON_ARRAY_HEADER_H
#define _YON_ARRAY_HEADER_H
#pragma once

#include <yCore/yCore.h>
#include <yCore/yAlgorithm.h>
#include <yCore/yException.h>
#include <initializer_list>

template<typename T, int Size>
class yCORE_API yArray
{
public:
	inline yArray() { }
	inline yArray(std::initializer_list<T> & il) { yMove(il.begin(), il.end(), _data); }

	// STL compatibility
	typedef T value_type;
	typedef T & reference;
	typedef const T & const_reference;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef int size_type;
	typedef int difference_type;

	typedef T * iterator;
	typedef const T * const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef iterator Iterator;
	typedef const_iterator ConstIterator;
	typedef reverse_iterator ReverseIterator;
	typedef const_reverse_iterator ConstReverseIterator;

	inline int size() const { return Size; }
	inline int length() const { return Size; }
	inline int count() const { return Size; }

	inline iterator begin() { return _data; }
	inline const_iterator begin() const { return _data; }
	inline const_iterator cbegin() const { return _data; }
	inline const_iterator constBegin() const { return _data; }
	inline iterator end() { return _data + Size; }
	inline const_iterator end() const { return _data + Size; }
	inline const_iterator cend() const { return _data + Size; }
	inline const_iterator constEnd() const { return _data + Size; }
	inline reverse_iterator rbegin() { return std::make_reverse_iterator(begin()); }
	inline const_reverse_iterator rbegin() const { return std::make_reverse_iterator(begin()); }
	inline const_reverse_iterator crbegin() const { return std::make_reverse_iterator(begin()); }
	inline const_reverse_iterator reverseConstBegin() const { return std::make_reverse_iterator(begin()); }
	inline reverse_iterator rend() { return std::make_reverse_iterator(end()); }
	inline const_reverse_iterator rend() const { return std::make_reverse_iterator(end()); }
	inline const_reverse_iterator crend() const { return std::make_reverse_iterator(end()); }
	inline const_reverse_iterator reverseConstEnd() const { return std::make_reverse_iterator(end()); }

	inline T & at(int i) { if (i < 0 || i >= Size) { yThrow(yOutOfRange); } return *(begin() + i); }
	inline const T & at(int i) const { if (i < 0 || i >= Size) { yThrow(yOutOfRange); } return *(begin() + i); }
	inline T value(int i, const T & defaultValue = T()) const { if (i < 0 || i >= Size) return defaultValue; return *(begin() + i); }

	inline T & first() { return (*begin()); }
	inline const T & first() const { return (*begin()); }
	inline T & last() { return (*(begin() + (Size - 1))); }
	inline const T & last() const { return (*(begin() + (Size - 1))); }

	// STL compatibility
	inline T & front() { return first(); }
	inline const T & front() const { return first(); }
	inline T & back() { return last(); }
	inline const T & back() const { return last(); }

	inline void fill(const T & value) { yFill(begin(), end(), value); }

	inline int indexOf(const T & value) const { const_iterator it = yFind(begin(), end(), value); if (it == cend()) return -1; else return std::distance(begin(), it); }
	inline int lastIndexOf(const T & value) const { const_reverse_iterator it = yFind(rbegin(), rend(), value); if (it == crend()) return -1; else return std::distance(rbegin(), it); }
	inline int count(const T & value) const { return yCount(begin(), end(), value); }
	inline bool contains(const T & value) const { return indexOf(value) >= 0; }

	inline T & operator[](int i) { return at(i); }
	inline const T & operator[](int i) const { return at(i); }

private:
	T _data[Size];
};

#endif // !_YON_ARRAY_HEADER_H