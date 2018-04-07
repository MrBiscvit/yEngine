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

#ifndef _YON_VECTOR_3D_HEADER_
#define _YON_VECTOR_3D_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <yCore/yMath.h>
#include <yCore/yException.h>

yNAMESPACE_BEGIN

template<typename T>
class yTemplateVector2D;
template<typename T>
class yTemplateVector4D;

template<typename T>
class yCORE_API yTemplateVector3D
{
public:
	inline yTemplateVector3D() : _x(T(0)), _y(T(0)), _z(T(0)) { }
	inline yTemplateVector3D(T scalar) : _x(scalar), _y(scalar), _z(scalar) { }
	inline yTemplateVector3D(T x, T y, T z) : _x(x), _y(y), _z(z) { }
	yTemplateVector3D(const yTemplateVector2D<T> & other);
	yTemplateVector3D(const yTemplateVector4D<T> & other);

	yTemplateVector3D<T> & operator=(const yTemplateVector2D<T> & other);
	yTemplateVector3D<T> & operator=(const yTemplateVector4D<T> & other);
	yTemplateVector2D<T> toVector2D() const;
	yTemplateVector4D<T> toVector4D() const;

	inline bool isNull() const { return _x == T(0) && _y == T(0) && _z == T(0); }

	inline T x() const { return _x; }
	inline T & rx() { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline T & ry() { return _y; }
	inline void setY(T y) { _y = y; }

	inline T z() const { return _z; }
	inline T & rz() { return _z; }
	inline void setZ(T z) { _z = z; }

	inline T length() const { return yHypot(_x, _y, _z); }
	inline T lengthSqared() const { return (_x * _x) + (_y * _y) + (_z * _z); }
	inline T dot(const yTemplateVector3D<T> & other) const { return (_x * other._x) + (_y * other._y) + (_z * other._z); }
	inline yTemplateVector3D normalize() const { T l = length(); return yTemplateVector3D<T>(_x / l, _y / l, _z / l); }

	inline T & operator[](int i) { if (i < 0 || i >= 4) { yThrow(yOutOfRange); } return (!i) ? _x : (i) ? _y : _z; }
	inline T  operator[](int i) const { if (i < 0 || i >= 4) { yThrow(yOutOfRange); } return (!i) ? _x : (i) ? _y : _z; }

	inline yTemplateVector3D<T> & operator*=(const yTemplateVector3D<T> & other) { _x *= other._x; _y *= other._y; _z *= other._z; return *this; }
	inline yTemplateVector3D<T> & operator*=(T scalar) { _x *= scalar; _y *= scalar; _z *= scalar; return *this; }
	inline yTemplateVector3D<T> & operator/=(const yTemplateVector3D<T> & other) { _x /= other._x; _y /= other._y; _z /= other._z; return *this; }
	inline yTemplateVector3D<T> & operator/=(T scalar) { _x /= scalar; _y /= scalar; _z /= scalar; return *this; }
	inline yTemplateVector3D<T> & operator+=(const yTemplateVector3D<T> & other) { _x += other._x; _y += other._y; _z += other._z; return *this; }
	inline yTemplateVector3D<T> & operator+=(T scalar) { _x += scalar; _y += scalar; _z += scalar; return *this; }
	inline yTemplateVector3D<T> & operator-=(const yTemplateVector3D<T> & other) { _x -= other._x; _y -= other._y; _z -= other._z; return *this; }
	inline yTemplateVector3D<T> & operator-=(T scalar) { _x -= scalar; _y -= scalar; _z -= scalar; return *this; }

private:
	T _x, _y, _z;
};

template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T> & v1, const yTemplateVector3D<T> & v2) { return yTemplateVector3D<T>(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z()); }
template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T> & v1, T v2) { return yTemplateVector3D<T>(v1.x() * v2, v1.y() * v2, v1.z() * v2); }
template<typename T>
inline yTemplateVector3D<T> operator*(T v1, const yTemplateVector3D<T> & v2) { return yTemplateVector3D<T>(v1 * v2.x(), v1 * v2.y(), v1 * v2.z()); }
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T> & v1, const yTemplateVector3D<T> & v2) { return yTemplateVector3D<T>(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z()); }
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T> & v1, T v2) { return yTemplateVector3D<T>(v1.x() / v2, v1.y() / v2, v1.z() / v2); }
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T> & v1, const yTemplateVector3D<T> & v2) { return yTemplateVector3D<T>(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z()); }
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T> & v1, T v2) { return yTemplateVector3D<T>(v1.x() + v2, v1.y() + v2, v1.z() + v2); }
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T> & v1, const yTemplateVector3D<T> & v2) { return yTemplateVector3D<T>(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z()); }
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T> & v1, T v2) { return yTemplateVector3D<T>(v1.x() - v2, v1.y() - v2, v1.z() - v2); }

// Useful Typedefs
typedef yTemplateVector3D<int> yIntVector3D;
typedef yTemplateVector3D<unsigned> yUnsignedVector3D;
typedef yTemplateVector3D<bool> yBoolVector3D;
typedef yTemplateVector3D<float> yFloatVector3D;
typedef yTemplateVector3D<double> yDoubleVector3D;
typedef yTemplateVector3D<yreal> yVector3D;

yNAMESPACE_END

#endif // _YON_VECTOR_3D_HEADER_