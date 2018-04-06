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

yNAMESPACE_END

#endif // !_YON_MEMORY_HEADER_