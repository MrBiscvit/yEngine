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

#ifndef _YON_VECTOR_2D_HEADER_
#define _YON_VECTOR_2D_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <yCore/yMath.h>
#include <yCore/yException.h>

yNAMESPACE_BEGIN

template<typename T>
class yTemplateVector3D;
template<typename T>
class yTemplateVector4D;

template<typename T>
class yCORE_API yTemplateVector2D
{
public:
	inline yTemplateVector2D() : _x(T(0)), _y(T(0)) { }
	inline yTemplateVector2D(T scalar) : _x(scalar), _y(scalar) { }
	inline yTemplateVector2D(T x, T y) : _x(x), _y(y) { }
	yTemplateVector2D(const yTemplateVector3D<T> & other);
	yTemplateVector2D(const yTemplateVector4D<T> & other);

	yTemplateVector2D<T> & operator=(const yTemplateVector3D<T> & other);
	yTemplateVector2D<T> & operator=(const yTemplateVector4D<T> & other);
	yTemplateVector3D<T> toVector3D() const;
	yTemplateVector4D<T> toVector4D() const;

	inline bool isNull() const { return _x == T(0) && _y == T(0); }

	inline T x() const { return _x; }
	inline T & rx() { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline T & ry() { return _y; }
	inline void setY(T y) { _y = y; }

	inline T length() const { return yHypot(_x, _y); }
	inline T lengthSqared() const { return (_x * _x) + (_y * _y); }
	inline T dot(const yTemplateVector2D<T> & other) const { return (_x * other._x) + (_y * other._y); }
	inline yTemplateVector2D normalize() const { T l = length(); return yTemplateVector2D<T>(_x / l, _y / l); }

	inline T & operator[](int i) { if (i < 0 || i >= 2) { yThrow(yOutOfRange); } return (!i) ? _x : _y; }
	inline T  operator[](int i) const { if (i < 0 || i >= 2) { yThrow(yOutOfRange); } return (!i) ? _x : _y; }

	inline yTemplateVector2D<T> & operator*=(const yTemplateVector2D<T> & other) { _x *= other._x; _y *= other._y; return *this; }
	inline yTemplateVector2D<T> & operator*=(T scalar) { _x *= scalar; _y *= scalar; return *this; }
	inline yTemplateVector2D<T> & operator/=(const yTemplateVector2D<T> & other) { _x /= other._x; _y /= other._y; return *this; }
	inline yTemplateVector2D<T> & operator/=(T scalar) { _x /= scalar; _y /= scalar; return *this; }
	inline yTemplateVector2D<T> & operator+=(const yTemplateVector2D<T> & other) { _x += other._x; _y += other._y; return *this; }
	inline yTemplateVector2D<T> & operator+=(T scalar) { _x += scalar; _y += scalar; return *this; }
	inline yTemplateVector2D<T> & operator-=(const yTemplateVector2D<T> & other) { _x -= other._x; _y -= other._y; return *this; }
	inline yTemplateVector2D<T> & operator-=(T scalar) { _x -= scalar; _y -= scalar; return *this; }

private:
	T _x, _y;
};

template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T> & v1, const yTemplateVector2D<T> & v2) { return yTemplateVector2D<T>(v1.x() * v2.x(), v1.y() * v2.y()); }
template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T> & v1, T v2) { return yTemplateVector2D<T>(v1.x() * v2, v1.y() * v2); }
template<typename T>
inline yTemplateVector2D<T> operator*(T v1, const yTemplateVector2D<T> & v2) { return yTemplateVector2D<T>(v1 * v2.x(), v1 * v2.y()); }
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T> & v1, const yTemplateVector2D<T> & v2) { return yTemplateVector2D<T>(v1.x() / v2.x(), v1.y() / v2.y()); }
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T> & v1, T v2) { return yTemplateVector2D<T>(v1.x() / v2, v1.y() / v2); }
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T> & v1, const yTemplateVector2D<T> & v2) { return yTemplateVector2D<T>(v1.x() + v2.x(), v1.y() + v2.y()); }
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T> & v1, T v2) { return yTemplateVector2D<T>(v1.x() + v2, v1.y() + v2); }
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T> & v1, const yTemplateVector2D<T> & v2) { return yTemplateVector2D<T>(v1.x() - v2.x(), v1.y() - v2.y()); }
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T> & v1, T v2) { return yTemplateVector2D<T>(v1.x() - v2, v1.y() - v2); }

// Useful Typedefs
typedef yTemplateVector2D<int> yIntVector2D;
typedef yTemplateVector2D<unsigned> yUnsignedVector2D;
typedef yTemplateVector2D<bool> yBoolVector2D;
typedef yTemplateVector2D<float> yFloatVector2D;
typedef yTemplateVector2D<double> yDoubleVector2D;
typedef yTemplateVector2D<yreal> yVector2D;

yNAMESPACE_END

#endif // _YON_VECTOR_2D_HEADER_