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

#ifndef _YON_SHARED_POINTER_HEADER_
#define _YON_SHARED_POINTER_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <yCore/yMemory.h>

template<typename T>
class yCORE_API ySharedPointerDeleter
{
public:
	static void destroy(T * ptr) { delete ptr; }
};

template<typename T>
class yCORE_API ySharedPointerArrayDeleter
{
public:
	static void destroy(T * ptr) { delete[ ] ptr; }
};

template<typename T>
class yCORE_API ySharedPointerFreeDeleter
{
public:
	static void destroy(T * ptr) { yFree(ptr); }
};

template<typename T, class Deleter = yConditional<std::is_array_v<T>, ySharedPointerArrayDeleter<T>, ySharedPointerDeleter<T>>::type>
class yCORE_API ySharedPointer
{
public:
	inline ySharedPointer(T * ptr) { _count = int(0); ref(); }
	inline ySharedPointer(const ySharedPointer & other) { if (other._ptr != nullptr) { deref(); _ptr = other._ptr; _count = other._count; ref(); } }


	inline bool isNull() const { return !yCHECK_PTR(_ptr); }
	inline operator bool() const { return yCHECK_PTR(_ptr); }
	inline bool operator!() const { return isNull(); }

	inline void clear() { reset(yNullptr); }
	inline void reset(T * other = yNULLPTR) { deref(); _ptr = other; }
	inline T * data() const { return _ptr; }

	inline T & operator*() const { return *_ptr; }
	inline T * operator->() const { return _ptr; }

private:
	void deref() { --_count; if (_count <= 0 && !isNull()) Deleter::destroy(_ptr); }
	void ref() { ++_count; }

private:
	T * _ptr;
	int & _count;
};

#endif // !_YON_SHARED_POINTER_HEADER_