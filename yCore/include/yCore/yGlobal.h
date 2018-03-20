#pragma once

#include <yCore/yConfig.h>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>

#define yVERSION(Major, Minor, Patch) ((Major << 16) + (Minor << 8) + (Patch))

// 
// Typedefs for integer and real types:
//
//   - yint8   or yuint8   -> 8-bit   signed/unsigned integer (native type)
//   - yint16  or yuint16  -> 16-bit  signed/unsigned integer (native type)
//   - yint32  or yuint32  -> 32-bit  signed/unsigned integer (native type)
//   - yint64  or yuint64  -> 64-bit  signed/unsigned integer (native type)
//
//   - ybyte                   -> 8-bit  unsigned integer (native type)
//   - ychar     or yuchar     -> 8-bit  signed/unsigned integer (native type)
//   - yshort    or yushort    -> 16-bit signed/unsigned integer (native type)
//   - yint      or yuint      -> 32-bit signed/unsigned integer (native type)
//   - ylonglong or yulonglong -> 64-bit signed/unsigned integer (native type)
//
//   - yreal -> typedefs for yREAL_TYPE macro, and if not defined for float
// 

#if defined(yCC_MSVC)
typedef signed __int8    yint8;
typedef signed __int16   yint16;
typedef signed __int32   yint32;
typedef signed __int64   yint64;
#else
typedef signed char      yint8;
typedef signed short     yint16;
typedef signed int       yint32;
typedef signed long long yint64;
#endif

#if defined(yCC_MSVC)
typedef unsigned __int8    yuint8;
typedef unsigned __int16   yuint16;
typedef unsigned __int32   yuint32;
typedef unsigned __int64   yuint64;
#else
typedef unsigned char      yuint8;
typedef unsigned short     yuint16;
typedef unsigned int       yuint32;
typedef unsigned long long yuint64;
#endif

typedef yuint8 ybyte;
typedef yint8 ychar;
typedef yuint8 yuchar;
typedef yint16 yshort;
typedef yuint16 yushort;
typedef yint32 yint;
typedef yuint32 yuint;
typedef yint64 ylonglong;
typedef yuint64 yulonglong;

#if defined(yREAL_TYPE)
typedef yREAL_TYPE yreal;
#else
typedef float yreal;
#endif

typedef void * yHandle;
typedef void(*yFunction)();

//
// Assertion macro:
//
//   - yASSERT   -> If condition is false, abort the program and print error message with the file and line.
//   - yASSERT_X -> If condition is false, abort the program and print error message with your where 
//                  and what message with the file and the line.
//

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

//
// No copy macro:
//
//   Put it at start of class implementation with the exact class name in argument.
//   For example:
//
//     class HelloWorld {
//         yDECL_NO_COPY(HelloWorld)
//     public:
//       ....
//     };
//
//

#define yDECL_NO_COPY(Class) \
Class(const Class &) = delete; \
Class& operator=(const Class&) = delete;