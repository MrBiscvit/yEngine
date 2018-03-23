#pragma once

#include <yMath/yMath.h>

template<typename T>
class yCORE_API yTemplateVector4D
{
public:
	inline yTemplateVector4D();
	inline yTemplateVector4D(T scalar);
	inline yTemplateVector4D(T x, T y, T z, T w);
	template<typename U>
	inline yTemplateVector4D(U x, U y, U z, U w);
	template<typename U>
	inline yTemplateVector4D(const yTemplateVector4D<U> & vec);

	inline bool isNull() const;

	inline T x() const { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline void setY(T y) { _y = y; }

	inline T z() const { return _z; }
	inline void setZ(T z) { _z = z };

	inline T w() const { return _w; }
	inline void setW(T w) { _w = w; }

	inline yTemplateVector4D<T> normalize() const;
	inline T length() const;
	inline T distance(const yTemplateVector4D<T> & vec) const;
	inline T dot(const yTemplateVector4D<T> & vec);

	inline yTemplateVector4D<T> & operator*=(const yTemplateVector4D<T> & vec);
	inline yTemplateVector4D<T> & operator*=(T scalar);
	inline yTemplateVector4D<T> & operator/=(const yTemplateVector4D<T> & vec);
	inline yTemplateVector4D<T> & operator/=(T scalar);
	inline yTemplateVector4D<T> & operator+=(const yTemplateVector4D<T> & vec);
	inline yTemplateVector4D<T> & operator+=(T scalar);
	inline yTemplateVector4D<T> & operator-=(const yTemplateVector4D<T> & vec);
	inline yTemplateVector4D<T> & operator-=(T scalar);
	inline yTemplateVector4D<T> & operator++();
	inline yTemplateVector4D<T> & operator--();

private:
	T _x, _y, _z, _w;
};

template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T> & vec);
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T> & vec);
template<typename T>
inline yTemplateVector4D<T> operator++(const yTemplateVector4D<T> & vec, int);
template<typename T>
inline yTemplateVector4D<T> operator--(const yTemplateVector4D<T> & vec, int);

template<typename T>
inline yTemplateVector4D<T> operator*(const yTemplateVector4D<T> & left, const yTemplateVector4D<T> & right);
template<typename T>
inline yTemplateVector4D<T> operator*(const yTemplateVector4D<T> & left, T right);
template<typename T>
inline yTemplateVector4D<T> operator*(T left, const yTemplateVector4D<T> & right);
template<typename T>
inline yTemplateVector4D<T> operator/(const yTemplateVector4D<T> & left, const yTemplateVector4D<T> & right);
template<typename T>
inline yTemplateVector4D<T> operator/(const yTemplateVector4D<T> & left, T right);
template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T> & left, const yTemplateVector4D<T> & right);
template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T> & left, T right);
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T> & left, const yTemplateVector4D<T> & right);
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T> & left, T right);

// Implementation
#include <yMath/inline/yVector4D.inl>

typedef yTemplateVector4D<bool> yBoolVector4D;
typedef yTemplateVector4D<int> yIntVector4D;
typedef yTemplateVector4D<float> yFloatVector4D;
typedef yTemplateVector4D<double> yDoubleVector4D;
typedef yTemplateVector4D<yreal> yVector4D;