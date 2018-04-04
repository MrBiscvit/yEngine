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

#ifndef _YON_MEMORY_HEADER_
#define _YON_MEMORY_HEADER_
#pragma once

#include <yCore/yCore.h>

yNAMESPACE_BEGIN

// C API

yCORE_API void * yon_malloc(ysizetype size) { return malloc(size); }
yCORE_API void * yon_calloc(ysizetype count, ysizetype size) { return calloc(count, size); }
yCORE_API void * yon_realloc(void * ptr, ysizetype size) { return realloc(ptr, size); }
yCORE_API void yon_free(void * ptr) { free(ptr); }

// C++ API

#if defined(__cplusplus)
template<typename T>
yCORE_API inline T * yMalloc(ysizetype size = sizeof(T))
{ return reinterpret_cast<T*>(malloc(size)); }
yCORE_API inline void * yMalloc(ysizetype size)
{ return malloc(size); }

template<typename T>
yCORE_API inline T * yCalloc(ysizetype count, ysizetype size = sizeof(T))
{ return reinterpret_cast<T*>(calloc(count, size)); }
yCORE_API inline void * yMalloc(ysizetype count, ysizetype size)
{ return calloc(count, size); }

yCORE_API inline void yFree(void * ptr)
{ return free(ptr); }

template<typename T>
yCORE_API inline T * yRealloc(T * ptr, ysizetype size = sizeof(T))
{ return reinterpret_cast<T*>(realloc(ptr, size)); }
yCORE_API inline void * yRealloc(void * ptr, ysizetype size)
{ return realloc(ptr, size); }

template<typename T, class Deleter>
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
#endif

yNAMESPACE_END

#endif // !_YON_MEMORY_HEADER_