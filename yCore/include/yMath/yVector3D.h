#pragma once

#include <yMath/yMath.h>

template<typename T>
class yCORE_API yTemplateVector3D
{
public:
	inline yTemplateVector3D();
	inline yTemplateVector3D(T scalar);
	inline yTemplateVector3D(T x, T y, T z);
	template<typename U>
	inline yTemplateVector3D(U x, U y, U z);
	template<typename U>
	inline yTemplateVector3D(const yTemplateVector3D<U> & vec);

	inline bool isNull() const;

	inline T x() const { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline void setY(T y) { _y = y; }

	inline T z() const { return _z; }
	inline void setZ(T z) { _z = z };

	inline yTemplateVector3D<T> normalize() const;
	inline T length() const;
	inline T distance(const yTemplateVector3D<T> & vec) const;
	inline T dot(const yTemplateVector3D<T> & vec);
	inline yTemplateVector3D<T> cross(const yTemplateVector3D<T> & vec);

	inline yTemplateVector3D<T> & operator*=(const yTemplateVector3D<T> & vec);
	inline yTemplateVector3D<T> & operator*=(T scalar);
	inline yTemplateVector3D<T> & operator/=(const yTemplateVector3D<T> & vec);
	inline yTemplateVector3D<T> & operator/=(T scalar);
	inline yTemplateVector3D<T> & operator+=(const yTemplateVector3D<T> & vec);
	inline yTemplateVector3D<T> & operator+=(T scalar);
	inline yTemplateVector3D<T> & operator-=(const yTemplateVector3D<T> & vec);
	inline yTemplateVector3D<T> & operator-=(T scalar);
	inline yTemplateVector3D<T> & operator++();
	inline yTemplateVector3D<T> & operator--();

private:
	T _x, _y, _z;
};

template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T> & vec);
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T> & vec);
template<typename T>
inline yTemplateVector3D<T> operator++(const yTemplateVector3D<T> & vec, int);
template<typename T>
inline yTemplateVector3D<T> operator--(const yTemplateVector3D<T> & vec, int);

template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T> & left, const yTemplateVector3D<T> & right);
template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T> & left, T right);
template<typename T>
inline yTemplateVector3D<T> operator*(T left, const yTemplateVector3D<T> & right);
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T> & left, const yTemplateVector3D<T> & right);
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T> & left, T right);
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T> & left, const yTemplateVector3D<T> & right);
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T> & left, T right);
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T> & left, const yTemplateVector3D<T> & right);
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T> & left, T right);

// Implementation
#include <yMath/inline/yVector3D.inl>

typedef yTemplateVector3D<bool> yBoolVector3D;
typedef yTemplateVector3D<int> yIntVector3D;
typedef yTemplateVector3D<float> yFloatVector3D;
typedef yTemplateVector3D<double> yDoubleVector3D;
typedef yTemplateVector3D<yreal> yVector3D;