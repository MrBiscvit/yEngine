#pragma once

#include <yCore/yGlobal.h>
#include <limits>

#define yINT8_MIN  (-128)
#define yINT8_MAX  (127)
#define yUINT8_MIN (0x00u)
#define yUINT8_MAX (0xFFu)

#define yINT16_MIN  (-32768)
#define yINT16_MAX  (32767)
#define yUINT16_MIN (0x0000)
#define yUINT16_MAX (0xFFFFu)

#define yINT32_MIN  (-2147483647 - 1)
#define yINT32_MAX  (2147483647)
#define yUINT32_MIN (0x00000000u)
#define yUINT32_MAX (0xFFFFFFFFu)

#define yINT64_MIN  (-9223372036854775807 - 1)
#define yINT64_MAX  (9223372036854775807)
#define yUINT64_MIN (0x0000000000000000u)
#define yUINT64_MAX (0xFFFFFFFFFFFFFFFFu)

#define yCHAR_MIN yINT8_MIN
#define yCHAR_MAX yINT8_MAX
#define yUCHAR_MIN yUINT8_MIN
#define yUCHAR_MAX yUINT8_MAX

#define ySHORT_MIN yINT16_MIN
#define ySHORT_MAX yINT16_MAX
#define yUSHORT_MIN yUINT16_MIN
#define yUSHORT_MAX yUINT16_MAX

#define yINT_MIN yINT32_MIN
#define yINT_MAX yINT32_MAX
#define yUINT_MIN yUINT32_MIN
#define yUINT_MAX yUINT32_MAX

#define yLONG_MIN yINT32_MIN
#define yLONG_MAX yINT32_MAX
#define yULONG_MIN yUINT32_MIN
#define yULONG_MAX yUINT32_MAX

#define yLLONG_MIN yINT64_MIN
#define yLLONG_MAX yINT64_MAX
#define yULLONG_MIN yUINT64_MIN
#define yULLONG_MAX yUINT64_MAX

#define yFLOAT_MIN (1.175494351e-38F)
#define yFLOAT_MAX (3.402823466e+38F)

#define yDOUBLE_MIN	(2.2250738585072014e-308)
#define yDOUBLE_MAX	(1.7976931348623158e+308)

template<typename T>
struct yLimits
{
	static constexpr T min() noexcept { return T(); }
	static constexpr T max() noexcept { return T(); }
};

template<typename T> 
struct yLimits<const T> { };
template<typename T>
struct yLimits<volatile T> { };
template<typename T>
struct yLimits<const volatile T> { };

template<> struct yLimits<bool>
{
	static constexpr bool min() noexcept { return false; }
	static constexpr bool max() noexcept { return true; }
};
template<> struct yLimits<signed char>
{
	static constexpr signed char min() noexcept { return yCHAR_MIN; }
	static constexpr signed char max() noexcept { return yCHAR_MAX; }
};
template<> struct yLimits<unsigned char>
{
	static constexpr unsigned char min() noexcept { return yUCHAR_MIN; }
	static constexpr unsigned char max() noexcept { return yUCHAR_MAX; }
};
template<> struct yLimits<signed short>
{
	static constexpr signed short min() noexcept { return ySHORT_MIN; }
	static constexpr signed short max() noexcept { return ySHORT_MAX; }
};
template<> struct yLimits<unsigned short>
{
	static constexpr unsigned short min() noexcept { return yUSHORT_MIN; }
	static constexpr unsigned short max() noexcept { return yUSHORT_MAX; }
};
template<> struct yLimits<signed int>
{
	static constexpr signed int min() noexcept { return yINT_MIN; }
	static constexpr signed int max() noexcept { return yINT_MAX; }
};
template<> struct yLimits<unsigned int>
{
	static constexpr unsigned int min() noexcept { return yUINT_MIN; }
	static constexpr unsigned int max() noexcept { return yUINT_MAX; }
};
template<> struct yLimits<signed long>
{
	static constexpr signed long min() noexcept { return yLONG_MIN; }
	static constexpr signed long max() noexcept { return yLONG_MAX; }
};
template<> struct yLimits<unsigned long>
{
	static constexpr unsigned long min() noexcept { return yULONG_MIN; }
	static constexpr unsigned long max() noexcept { return yULONG_MAX; }
};
template<> struct yLimits<signed long long>
{
	static constexpr signed long long min() noexcept { return yLLONG_MIN; }
	static constexpr signed long long max() noexcept { return yLLONG_MAX; }
};
template<> struct yLimits<unsigned long long>
{
	static constexpr unsigned long long min() noexcept { return yULLONG_MIN; }
	static constexpr unsigned long long max() noexcept { return yULLONG_MAX; }
};
template<> struct yLimits<char16_t>
{
	static constexpr char16_t min() noexcept { return yUSHORT_MIN; }
	static constexpr char16_t max() noexcept { return yUSHORT_MAX; }
};
template<> struct yLimits<char32_t>
{
	static constexpr char32_t min() noexcept { return yUINT_MIN; }
	static constexpr char32_t max() noexcept { return yUINT_MAX; }
};
template<> struct yLimits<float>
{
	static constexpr float min() noexcept { return yFLOAT_MIN; }
	static constexpr float max() noexcept { return yFLOAT_MAX; }
};
template<> struct yLimits<double>
{
	static constexpr double min() noexcept { return yDOUBLE_MIN; }
	static constexpr double max() noexcept { return yDOUBLE_MAX; }
};