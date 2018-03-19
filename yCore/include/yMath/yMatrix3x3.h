#pragma once

#include <yMath/yMath.h>
#include <yMath/yVector3D.h>

template<typename T>
class yCORE_API yTemplateMatrix3x3
{
public:
	inline yTemplateMatrix3x3();
	inline yTemplateMatrix3x3(T m11, T m12, T m13, 
							  T m21, T m22, T m23,
							  T m31, T m32, T m33);
	inline yTemplateMatrix3x3(const T * values);
	template<typename U>
	inline yTemplateMatrix3x3(U m11, U m12, U m13,
							  U m21, U m22, U m23,
							  U m31, U m32, U m33);
	template<typename U>
	inline yTemplateMatrix3x3(const U * values);
	template<typename U>
	inline yTemplateMatrix3x3(const yTemplateMatrix3x3<U> & mat);

	inline bool isIdentity() const;
	inline void setToIdentity();

	inline yTemplateVector3D<T> row(int index) const;
	inline void setRow(int index, const yTemplateVector3D<T> & vec);
	inline void setRow(int index, T x, T y, T z);

	inline yTemplateVector3D<T> column(int index) const;
	inline void setColumn(int index, const yTemplateVector3D<T> & vec);
	inline void setColumn(int index, T x, T y, T z);

	inline T & at(int row, int column);
	inline T at(int row, int column) const;
	inline T & operator()(int row, int column) { return at(row, column); }
	inline T operator()(int row, int column) const { return at(row, column); }

	inline T * data() const { return *_data; }
	inline const T * data() const { return *_data; }
	inline const T * constData() const { return *_data; }

	inline void fill(T value);

	inline T determinant() const;
	inline yTemplateMatrix3x3<T> inverse() const;
	inline yTemplateMatrix3x3<T> transpose() const;

	inline yTemplateMatrix3x3<T> & operator*=(const yTemplateMatrix3x3<T> & mat);
	inline yTemplateMatrix3x3<T> & operator*=(T scalar);
	inline yTemplateMatrix3x3<T> & operator/=(const yTemplateMatrix3x3<T> & mat);
	inline yTemplateMatrix3x3<T> & operator/=(T scalar);
	inline yTemplateMatrix3x3<T> & operator+=(const yTemplateMatrix3x3<T> & mat);
	inline yTemplateMatrix3x3<T> & operator+=(T scalar);
	inline yTemplateMatrix3x3<T> & operator-=(const yTemplateMatrix3x3<T> & mat);
	inline yTemplateMatrix3x3<T> & operator-=(T scalar);

private:
	T _data[3][3];
};

template<typename T>
inline yTemplateMatrix3x3<T> operator*(const yTemplateMatrix3x3<T> & left, const yTemplateMatrix3x3<T> & right);
template<typename T>
inline yTemplateMatrix3x3<T> operator*(const yTemplateMatrix3x3<T> & left, T right);
template<typename T>
inline yTemplateMatrix3x3<T> operator*(T left, const yTemplateMatrix3x3<T> & right);
template<typename T>
inline yTemplateMatrix3x3<T> operator/(const yTemplateMatrix3x3<T> & left, const yTemplateMatrix3x3<T> & right);
template<typename T>
inline yTemplateMatrix3x3<T> operator/(const yTemplateMatrix3x3<T> & left, T right);
template<typename T>
inline yTemplateMatrix3x3<T> operator+(const yTemplateMatrix3x3<T> & left, const yTemplateMatrix3x3<T> & right);
template<typename T>
inline yTemplateMatrix3x3<T> operator+(const yTemplateMatrix3x3<T> & left, T right);
template<typename T>
inline yTemplateMatrix3x3<T> operator-(const yTemplateMatrix3x3<T> & left, const yTemplateMatrix3x3<T> & right);
template<typename T>
inline yTemplateMatrix3x3<T> operator-(const yTemplateMatrix3x3<T> & left, T right);

// yTemplateMatrix3x3 inline implementation
#include <yMath/inline/yMatrix3x3.inl>

//
// Typedefs for yTemplateMatrix3x3:
//
//   - yBoolMatrix3x3   -> 3 x 3 boolean matrix
//   - yIntMatrix3x3    -> 3 x 3 integer matrix
//   - yFloatMatrix3x3  -> 3 x 3 float matrix
//   - yDoubleMatrix3x3 -> 3 x 3 double matrix
//   - yMatrix3x3       -> 3 x 3 real matrix
//

typedef yTemplateMatrix3x3<bool> yBoolMatrix3x3;
typedef yTemplateMatrix3x3<int> yIntMatrix3x3;
typedef yTemplateMatrix3x3<float> yFloatMatrix3x3;
typedef yTemplateMatrix3x3<double> yDoubleMatrix3x3;
typedef yTemplateMatrix3x3<yreal> yMatrix3x3;