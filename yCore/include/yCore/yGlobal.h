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

#ifndef _YON_GLOBAL_HEADER_
#define _YON_GLOBAL_HEADER_
#pragma once

#include <yCore/yConfig.h>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cstdalign>
#include <cmath>
#include <climits>

// Avoids useless warnings from certain compilers
#if defined(yCC_MVSC)
#  pragma warning(disable: 4251) // class 'type' needs to have dll-interface to be used by clients of class 'type2'
#  pragma warning(disable: 4244) // conversion from 'type1' to 'type2', possible loss of data
#  pragma warning(disable: 4275) // non - DLL-interface classkey 'identifier' used as base for DLL-interface classkey 'identifier'
#  pragma warning(disable: 4514) // unreferenced inline function has been removed
#  pragma warning(disable: 4800) // 'type' : forcing value to bool 'true' or 'false' (performance warning)
#  pragma warning(disable: 4097) // typedef-name 'identifier1' used as synonym for class-name 'identifier2'
#  pragma warning(disable: 4706) // assignment within conditional expression
#  pragma warning(disable: 4355) // 'this' : used in base member initializer list
#  pragma warning(disable: 4710) // function not inlined
#  pragma warning(disable: 4530) // C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc
#endif

// Macros for use name-space
#if defined(yUSE_NAMESPACE)
#  define yNAMESPACE Yon
#endif
#if defined(yNAMESPACE) && defined(__cplusplus)
#  define yNAMESPACE_BEGIN namespace yNAMESPACE {
#  define yNAMESPACE_END }
#  define yNAMESPACE_INCLUDE_BEGIN yNAMESPACE_END
#  define yNAMESPACE_INCLUDE_END yNAMESPACE_BEGIN
#  define yNAMESPACE_USING using namespace yNAMESPACE;
#else
#  define yNAMESPACE_BEGIN
#  define yNAMESPACE_END
#  define yNAMESPACE_INCLUDE_BEGIN yNAMESPACE_END
#  define yNAMESPACE_INCLUDE_END yNAMESPACE_BEGIN
#  define yNAMESPACE_USING
#endif

yNAMESPACE_BEGIN

// Typedefs for fixed size integers
typedef signed   char      yint8;	// Signed 8-bit integer
typedef signed   short     yint16;	// Signed 16-bit integer
typedef signed   int       yint32;	// Signed 32-bit integer
typedef unsigned char      yuint8;	// Unsigned 8-bit integer
typedef unsigned short     yuint16;	// Unsigned 16-bit integer
typedef unsigned int       yuint32;	// Unsigned 32-bit integer
#if defined(yCC_MVSC)
typedef signed   __int64   yint64;  // Signed 64-bit integer
typedef unsigned __int64   yuint64; // Unsigned 64-bit integer
#else
typedef signed   long long yint64;  // Signed 64-bit integer
typedef unsigned long long yuint64; // Unsigned 64-bit integer
#endif

// Typedefs for signed and unsigned primitive types
typedef yuint8 ybyte;
#if defined(__cplusplus)
typedef bool yboolean;
#else
typedef enum { false, true } yboolean;
#endif
typedef signed char ychar;
typedef unsigned char yuchar;
typedef signed short yshort;
typedef unsigned short yushort;
typedef signed int yint;
typedef unsigned int yuint;
typedef signed long ylong;
typedef unsigned long yulong;
typedef yint64 ylonglong;
typedef yuint64 yulonglong;

// Limits macros by type
#define yBYTE_MIN (0)
#define yBYTE_MAX (0xFF)
#define yCHAR_MIN (-128)
#define yCHAR_MAX (127)
#define yUCHAR_MIN (0)
#define yUCHAR_MAX (0xFF)
#define ySHORT_MIN (-32768)
#define ySHORT_MAX (32767)
#define yUSHORT_MIN (0)
#define yUSHORT_MAX (0xFFFF)
#define yINT_MIN (-2147483647 - 1)
#define yINT_MAX (2147483647)
#define yUINT_MIN (0)
#define yUINT_MAX (0xFFFFFFFF)
#define yLONG_MIN yINT_MIN
#define yLONG_MAX yINT_MAX
#define yULONG_MIN yUINT_MIN
#define yULONG_MAX yUINT_MAX
#define yLLONG_MIN (-9223372036854775807 - 1)
#define yLLONG_MAX (9223372036854775807)
#define yULLONG_MIN (0)
#define yULLONG_MAX (0xFFFFFFFFFFFFFFFF)

// Limits macros by size
#define yINT8_MIN yCHAR_MIN
#define yINT8_MAX yCHAR_MAX
#define yUINT8_MIN yUCHAR_MIN
#define yUINT8_MAX yUCHAR_MAX
#define yINT16_MIN ySHORT_MIN
#define yINT16_MAX ySHORT_MAX
#define yUINT16_MIN yUSHORT_MIN
#define yUINT16_MAX yUSHORT_MAX
#define yINT32_MIN yINT_MIN
#define yINT32_MAX yINT_MAX
#define yUINT32_MIN yUINT_MIN
#define yUINT32_MAX yUINT_MAX
#define yINT64_MIN yLLONG_MIN
#define yINT64_MAX yLLONG_MAX
#define yUINT64_MIN yULLONG_MIN
#define yUINT64_MAX yULLONG_MAX

// Typedefs for STL compatibility
#if defined(__cplusplus)
// Helper class to get the integer type for a in bytes
template<int> struct yIntegerForSize;
template<>    struct yIntegerForSize<1> { typedef yint8 Signed; typedef yuint8 Unsigned; };
template<>    struct yIntegerForSize<2> { typedef yint16 Signed; typedef yuint16 Unsigned; };
template<>    struct yIntegerForSize<4> { typedef yint32 Signed; typedef yuint32 Unsigned; };
template<>    struct yIntegerForSize<8> { typedef yint64 Signed; typedef yuint64 Unsigned; };

typedef yIntegerForSize<sizeof(void*)>::Signed yintptr;
typedef yIntegerForSize<sizeof(void*)>::Unsigned yuintptr;
typedef yintptr yptrdiff;
typedef std::size_t ysizetype;
#else
typedef ptrdiff_t yptrdiff;
typedef ptrdiff_t ysizetype;
typedef ptrdiff_t yintptr;
typedef size_t yuintptr;
#endif

// Nothing function
inline void yon_noop() { }

// Some maths functions
template<typename T>
inline T yAbs(const T & v) { return v >= 0 ? v : -v; }
template<typename T, typename U>
inline U yRound(const T & v) { return v >= T(0.f) ? U(v + T(0.5f)) : U(v - T(U(v - 1)) + T(0.5f)) + U(v - 1); }
template<typename T>
inline T yMax(const T & x, const T & y) { return (x < y) ? x : y; }
template<typename T>
inline T yMin(const T & x, const T & y) { return (x < y) ? y : x; }
template<typename T>
inline T yBound(const T & min, const T & max, const T & v) { return yMax(min, yMin(max, v)); }

// Fuzzy operations functions
inline bool yFuzzyCompare(double v1, double v2) { return (yAbs(v1 - v2) * 1000000000000. <= yMin(yAbs(v1), yAbs(v2))); }
inline bool yFuzzyCompare(float v1, float v2) { return (yAbs(v1 - v2) * 100000.f <= yMin(yAbs(v1), yAbs(v2))); }
inline bool yFuzzyIsNull(double v) { return yAbs(v) <= 0.000000000001; }
inline bool yFuzzyIsNull(float v) { return yAbs(v) <= 0.00001f; }

// Adds const to non-const objects
#if defined(__cplusplus)
template<typename T>
struct yAddConst { typedef const T type; };
template<typename T>
yAddConst<T>::type & yAsConst(T & v) { return v; }
#endif

// Conditional type
#if defined(__cplusplus)
template<bool B, typename T, typename U> struct yConditional { typedef T type; };
template<typename T, typename U> struct yConditional<false, T, U> { typedef U type; };
#endif

// Multi-platform debug macro
#if defined(_DEBUG) && !defined(NDEBUG)
#  define yDEBUG
#  if defined(yNO_DEBUG)
#    undef yNO_DEBUG
#  endif
#else
#  define yNO_DEBUG
#  if defined(yDEBUG)
#    undef yDEBUG
#  endif
#endif

// Exceptions
#if !defined(__cplusplus) && !defined(yNO_EXCEPTIONS)
#  define yNO_EXCEPTIONS
#endif
#if defined(yNO_EXCEPTIONS)
#  define yTry if (true)
#  define yCatch(A) else
#  define yThrow(A) yon_noop()
#  define yRethrow yon_noop()

typedef struct yException_ { } yException;
#else
#  define yTry try
#  define yCatch(A) catch (A)
#  define yThrow(A) throw A
#  define yRethrow throw
#  include <exception>
class yException : public std::exception
{
public:
	inline yException() : std::exception(), _msg("unknown exception") { }
	inline yException(const char * message) : std::exception(), _msg(message) { }
	inline yException(const std::string & message) : std::exception(), _msg(message) { }

	virtual inline const char * what() const noexcept { return _msg.c_str(); }

private:
	const std::string _msg;
};
#endif

// Exit and Abort functions
inline void yExit(int exitCode = 0) { std::exit(exitCode); }
inline void yAbort() { std::abort(); }

// Assertions 
#if defined(yCC_MVSC)
_declspec(noreturn)
#endif
void yon_assert(const char * assertion, const char * file, int line) noexcept
{
	fprintf(stderr, "ASSERT: \"%s\" in file %s, line %i", assertion, file, line);
	yAbort();
}

#if defined(yCC_MVSC)
_declspec(noreturn)
#endif
void yon_assert_x(const char * where, const char * what, const char * file, int line) noexcept
{
	fprintf(stderr, "ASSERT at \"%s\": \"%s\" in file %s, line %i", where, what, file, line);
	yAbort();
}

#if defined(yDEBUG) || defined(yFORCE_ASSERTS)
#  define yASSERT(Cond) ((Cond) ? static_cast<void>(0) : yon_assert(#Cond, __FILE__, __LINE__))
#  define yASSERT_X(Cond, Where, What) ((cond) ? static_cast<void>(0) : yon_assert_x(#Cond, Where, What, __FILE__, __LINE__))
#else
#  define yASSERT(Cond) static_cast<void>(false && (Cond))
#  define yASSERT_X(Cond, Where, What) static_cast<void>(false && (Cond))
#endif

yNAMESPACE_END

#endif // !_YON_GLOBAL_HEADER_