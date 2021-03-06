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

#ifndef _YON_CONFIG_HEADER_
#define _YON_CONFIG_HEADER_
#pragma once

#if defined(_WIN32)
#  define yOS_WINDOWS
#elif defined(__APPLE__)
#  define yOS_APPLE
#  define yOS_UNIX
#  include "TargetConditionals.h"
#  if TARGET_IPHONE_SIMULATOR
#    define yOS_IOS
#    define yOS_IOS_SIMULATOR
#  elif TARGET_OS_IPHONE
#    define yOS_IOS
#  elif TARGET_OS_MAC
#    define yOS_MACOS
#    define yOS_DARWIN
#  else
#    error "Unknown Apple Platform, please contact support!"
#  endif
#elif defined(__linux__)
#  define yOS_LINUX
#  define yOS_UNIX
#elif defined(__unix__)
#  define yOS_UNIX
#else
#  pragma warning("Unknown OS, please contact support!")
#endif

#if defined(_MSC_VER)
// Microsoft Visual Studio Compiler
#  define yCC_MVSC _MSC_VER
#  define yDECL_EXPORT __declspec(dllexport)
#  define yDECL_IMPORT __declspec(dllimport)
#else
#  define yDECL_EXPORT
#  define yDECL_IMPORT
#  pragma warning("Unknown compiler, please contact support!")
#endif

#if defined(__cplusplus)
#  define yNULLPTR nullptr
#else
#  define yNULLPTR NULL
#endif

#endif // !_YON_CONFIG_HEADER_