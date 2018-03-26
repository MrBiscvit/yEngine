#pragma once

#include <yCore/yConfig.h>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>

// Version macro
#define yVERSION(Major, Minor, Patch) ((Major << 16) + (Minor << 8) + (Patch))

// Useless compiler-generated warnings
#if defined(yCC_MSVC)
#pragma warning(disable: 4251) // Incorrect DLL-interface
#endif

// Useful typedefs

#if defined(yCC_MSVC)
typedef signed __int8    yint8;	 // 8-bit signed integer
typedef signed __int16   yint16; // 16-bit signed integer
typedef signed __int32   yint32; // 32-bit signed integer
typedef signed __int64   yint64; // 64-bit signed integer
#else
typedef signed char      yint8;	 // 8-bit signed integer
typedef signed short     yint16; // 16-bit signed integer
typedef signed int       yint32; // 32-bit signed integer
typedef signed long long yint64; // 64-bit signed integer
#endif

#if defined(yCC_MSVC)
typedef unsigned __int8    yuint8;	// 8-bit unsigned integer
typedef unsigned __int16   yuint16;	// 16-bit unsigned integer
typedef unsigned __int32   yuint32;	// 32-bit unsigned integer
typedef unsigned __int64   yuint64;	// 64-bit unsigned integer
#else
typedef unsigned char      yuint8;	// 8-bit unsigned integer
typedef unsigned short     yuint16;	// 16-bit unsigned integer
typedef unsigned int       yuint32;	// 32-bit unsigned integer
typedef unsigned long long yuint64;	// 64-bit unsigned integer
#endif

typedef yuint8 ybyte;  // unsigned byte
typedef yuint32 yuint; // unsigned integer
typedef yint64 ylonglong;   // signed long long integer
typedef yuint64 yulonglong; // unsigned long long integer

#if defined(yREAL_TYPE)
typedef yREAL_TYPE yreal; // real number
#else
typedef float yreal;      // real number
#endif

typedef void * yHandle; // OS-independent handle
typedef void(*yFunction)(); // function pointer

// Assert macros and functions

#if defined(yCC_MSVC)
__declspec(noreturn)
#endif
void _yon_assert(const char * assertion, const char * file, int line) throw();

#if defined(yCC_MSVC)
__declspec(noreturn)
#endif
void _yon_assert_x(const char * where, const char * what, const char * file, int line) throw();

#if defined(yDEBUG) || defined(yFORCE_ASSERTS)
#  define yASSERT(Cond) ((Cond) ? static_cast<void>(0) : _yon_assert(#Cond, __FILE__, __LINE__))
#  define yASSERT_X(Cond, Where, What) ((Cond) ? static_cast<void>(0) : _yon_assert_x(Where, What, __FILE__, __LINE__))
#else
#  define yASSERT(Cond) static_cast<void>(false && (Cond))
#  define yASSERT_X(Cond, Where, What) static_cast<void>(false && (Cond))
#endif

// Declare a class no copyable
#define yDECL_NO_COPY(Class) \
Class(const Class &) = delete; \
Class& operator=(const Class&) = delete;

// Declare variable unused, avoid some warnings for compilers
#define yUNUSED(X) (void)X

// Stringify macro
#define _ySTRINGIFY(X) #X
#define ySTRINGIFY(X) _ySTRINGIFY(X)