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

#ifndef _YON_SCOPED_POINTER_HEADER_
#define _YON_SCOPED_POINTER_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <yCore/yMemory.h>

yNAMESPACE_BEGIN

template<typename T>
class yCORE_API yScopedPointerDeleter
{
public:
	static void destroy(T * ptr) { delete ptr; }
};

template<typename T>
class yCORE_API yScopedPointerArrayDeleter
{
public:
	static void destroy(T * ptr) { delete[] ptr; }
};

template<typename T>
class yCORE_API yScopedPointerFreeDeleter
{
public:
	static void destroy(T * ptr) { yFree(ptr); }
};


template<typename T, class Deleter = yConditional<std::is_array_v<T>, yScopedPointerArrayDeleter<T>, yScopedPointerDeleter<T>>::type>
class yCORE_API yScopedPointer
{
	yDISABLE_COPY(yScopedPointer)

public:
	inline yScopedPointer(T * ptr = yNULLPTR) : _ptr(ptr) { }
	inline ~yScopedPointer() { reset(); }

	inline bool isNull() const { return !yCHECK_PTR(_ptr); }
	inline operator bool() const { return yCHECK_PTR(_ptr); }
	inline bool operator!() const { return isNull(); }

	inline void reset(T * other = yNULLPTR) { if (!isNull()) Deleter::destroy(_ptr); _ptr = other; }
	inline T * data() const { return _ptr; }
	inline T * take() { T * ptr = _ptr; _ptr = yNULLPTR; return _ptr; }

	inline T & operator*() const { return *_ptr; }
	inline T * operator->() const { return _ptr; }

private:
	T * _ptr;
};

yNAMESPACE_END

#endif // ! _YON_SCOPED_POINTER_HEADER_