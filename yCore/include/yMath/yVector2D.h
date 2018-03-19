#pragma once

#include <yMath/yMath.h>

template<typename T>
class yCORE_API yTemplateVector2D
{
public:
	inline yTemplateVector2D();
	inline yTemplateVector2D(T scalar);
	inline yTemplateVector2D(T x, T y);
	template<typename U>
	inline yTemplateVector2D(U x, U y);
	template<typename U>
	inline yTemplateVector2D(const yTemplateVector2D<U> & vec);

	inline bool isNull() const;

	inline T x() const { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline void setY(T y) { _y = y; }

	inline yTemplateVector2D<T> normalize() const;
	inline T length() const;
	inline T distance(const yTemplateVector2D<T> & vec) const;
	inline T dot(const yTemplateVector2D<T> & vec);

	inline yTemplateVector2D<T> & operator*=(const yTemplateVector2D<T> & vec);
	inline yTemplateVector2D<T> & operator*=(T scalar);
	inline yTemplateVector2D<T> & operator/=(const yTemplateVector2D<T> & vec);
	inline yTemplateVector2D<T> & operator/=(T scalar);
	inline yTemplateVector2D<T> & operator+=(const yTemplateVector2D<T> & vec);
	inline yTemplateVector2D<T> & operator+=(T scalar);
	inline yTemplateVector2D<T> & operator-=(const yTemplateVector2D<T> & vec);
	inline yTemplateVector2D<T> & operator-=(T scalar);
	inline yTemplateVector2D<T> & operator++();
	inline yTemplateVector2D<T> & operator--();

private:
	T _x, _y;
};

template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T> & vec);
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T> & vec);
template<typename T>
inline yTemplateVector2D<T> operator++(const yTemplateVector2D<T> & vec, int);
template<typename T>
inline yTemplateVector2D<T> operator--(const yTemplateVector2D<T> & vec, int);

template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T> & left, const yTemplateVector2D<T> & right);
template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T> & left, T right);
template<typename T>
inline yTemplateVector2D<T> operator*(T left, const yTemplateVector2D<T> & right);
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T> & left, const yTemplateVector2D<T> & right);
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T> & left, T right);
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T> & left, const yTemplateVector2D<T> & right);
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T> & left, T right);
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T> & left, const yTemplateVector2D<T> & right);
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T> & left, T right);

// yTemplateVector2D inline implementation
#include <yMath/inline/yVector2D.inl>

//
// Typedefs for yTemplateVector2D:
//
//   - yBoolVector2D   -> 2D boolean vector
//   - yIntVector2D    -> 2D integer vector
//   - yFloatVector2D  -> 2D float vector
//   - yDoubleVector2D -> 2D double vector
//   - yVector2D       -> 2D real vector
//

typedef yTemplateVector2D<bool> yBoolVector2D;
typedef yTemplateVector2D<int> yIntVector2D;
typedef yTemplateVector2D<float> yFloatVector2D;
typedef yTemplateVector2D<double> yDoubleVector2D;
typedef yTemplateVector2D<yreal> yVector2D;