#pragma once

#include <yMath/yMath.h>
#include <yMath/yVector4D.h>

template<typename T>
class yCORE_API yTemplateMatrix4x4
{
public:
	inline yTemplateMatrix4x4();
	inline yTemplateMatrix4x4(T m11, T m12, T m13, T m14,
							  T m21, T m22, T m23, T m24,
							  T m31, T m32, T m33, T m34,
							  T m41, T m42, T m43, T m44);
	inline yTemplateMatrix4x4(const T * values);
	template<typename U>
	inline yTemplateMatrix4x4(U m11, U m12, U m13, U m14,
							  U m21, U m22, U m23, U m24,
							  U m31, U m32, U m33, U m34,
							  U m41, U m42, U m43, U m44);
	template<typename U>
	inline yTemplateMatrix4x4(const U * values);
	template<typename U>
	inline yTemplateMatrix4x4(const yTemplateMatrix4x4<U> & mat);

	inline bool isIdentity() const;
	inline void setToIdentity();

	inline yTemplateVector4D<T> row(int index) const;
	inline void setRow(int index, const yTemplateVector4D<T> & vec);
	inline void setRow(int index, T x, T y, T z, T w);

	inline yTemplateVector4D<T> column(int index) const;
	inline void setColumn(int index, const yTemplateVector4D<T> & vec);
	inline void setColumn(int index, T x, T y, T z, T w);

	inline T & at(int row, int column);
	inline T at(int row, int column) const;
	inline T & operator()(int row, int column) { return at(row, column); }
	inline T operator()(int row, int column) const { return at(row, column); }

	inline T * data() const { return *_data; }
	inline const T * data() const { return *_data; }
	inline const T * constData() const { return *_data; }

	inline void fill(T value);

	inline T determinant() const;
	inline yTemplateMatrix4x4<T> inverse() const;
	inline yTemplateMatrix4x4<T> transpose() const;

	inline yTemplateMatrix4x4<T> & operator*=(const yTemplateMatrix4x4<T> & mat);
	inline yTemplateMatrix4x4<T> & operator*=(T scalar);
	inline yTemplateMatrix4x4<T> & operator/=(const yTemplateMatrix4x4<T> & mat);
	inline yTemplateMatrix4x4<T> & operator/=(T scalar);
	inline yTemplateMatrix4x4<T> & operator+=(const yTemplateMatrix4x4<T> & mat);
	inline yTemplateMatrix4x4<T> & operator+=(T scalar);
	inline yTemplateMatrix4x4<T> & operator-=(const yTemplateMatrix4x4<T> & mat);
	inline yTemplateMatrix4x4<T> & operator-=(T scalar);

private:
	T _data[4][4];
};

template<typename T>
inline yTemplateMatrix4x4<T> operator*(const yTemplateMatrix4x4<T> & left, const yTemplateMatrix4x4<T> & right);
template<typename T>
inline yTemplateMatrix4x4<T> operator*(const yTemplateMatrix4x4<T> & left, T right);
template<typename T>
inline yTemplateMatrix4x4<T> operator*(T left, const yTemplateMatrix4x4<T> & right);
template<typename T>
inline yTemplateMatrix4x4<T> operator/(const yTemplateMatrix4x4<T> & left, const yTemplateMatrix4x4<T> & right);
template<typename T>
inline yTemplateMatrix4x4<T> operator/(const yTemplateMatrix4x4<T> & left, T right);
template<typename T>
inline yTemplateMatrix4x4<T> operator+(const yTemplateMatrix4x4<T> & left, const yTemplateMatrix4x4<T> & right);
template<typename T>
inline yTemplateMatrix4x4<T> operator+(const yTemplateMatrix4x4<T> & left, T right);
template<typename T>
inline yTemplateMatrix4x4<T> operator-(const yTemplateMatrix4x4<T> & left, const yTemplateMatrix4x4<T> & right);
template<typename T>
inline yTemplateMatrix4x4<T> operator-(const yTemplateMatrix4x4<T> & left, T right);

// Implementation
#include <yMath/inline/yMatrix4x4.inl>

typedef yTemplateMatrix4x4<bool> yBoolMatrix4x4;
typedef yTemplateMatrix4x4<int> yIntMatrix4x4;
typedef yTemplateMatrix4x4<float> yFloatMatrix4x4;
typedef yTemplateMatrix4x4<double> yDoubleMatrix4x4;
typedef yTemplateMatrix4x4<yreal> yMatrix4x4;