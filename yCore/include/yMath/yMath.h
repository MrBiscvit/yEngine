#pragma once

#include <yCore/yCore.h>
#include <cmath>

template<typename T>
inline T yPi()
{
	return static_cast<T>(3.14159265358979323846264338327950);
}

template<typename T>
inline T yDegrees(T radians)
{
	return static_cast<T>(radians * (180 / yPi<yreal>()));
}
template<typename T>
inline T yRadians(T degrees)
{
	return static_cast<T>(degrees * (yPi<yreal>() / 180));
}

template<typename T>
inline T yMax(T x, T y)
{
	using std::fmax;
	return static_cast<T>(fmax(x, y));
}
template<typename T>
inline T yMin(T x, T y)
{
	using std::fmin;
	return static_cast<T>(fmin(x, y));
}

template<typename T>
inline T ySin(T value)
{
	using std::sin;
	return static_cast<T>(sin(value));
}
template<typename T>
inline T yCos(T value)
{
	using std::cos;
	return static_cast<T>(cos(value));
}
template<typename T>
inline T yTan(T value)
{
	using std::tan;
	return static_cast<T>(tan(value));
}
template<typename T>
inline T yAsin(T value)
{
	using std::asin;
	return static_cast<T>(asin(value));
}
template<typename T>
inline T yAcos(T value)
{
	using std::acos;
	return static_cast<T>(acos(value));
}
template<typename T>
inline T yAtan(T value)
{
	using std::atan;
	return static_cast<T>(atan(value));
}
template<typename T>
inline T yAtan(T x, T y)
{
	using std::atan2;
	return static_cast<T>(atan2(x, y));
}

template<typename T, typename U>
inline T yPow(T value, U exponent)
{
	using std::pow;
	return static_cast<T>(pow(value, exponent));
}
template<typename T>
inline T ySqrt(T value)
{  
	using std::sqrt;
	return static_cast<T>(sqrt(value));
}
template<typename T>
inline T yCbrt(T value)
{
	using std::cbrt;
	return static_cast<T>(cbrt(value));
}

template<typename T>
inline int yCeil(T value)
{
	using std::ceil;
	return static_cast<int>(ceil(value));
}
template<typename T>
inline int yFloor(T value)
{
	using std::floor;
	return static_cast<int>(floor(value));
}
template<typename T>
inline int yTrunc(T value)
{
	using std::trunc;
	return static_cast<int>(trunc(value));
}
template<typename T>
inline int yRound(T value)
{
	using std::round;
	return static_cast<int>(round(value));
}

template<typename T>
inline T yAbs(T value)
{
	using std::abs;
	return static_cast<T>(abs(value));
}