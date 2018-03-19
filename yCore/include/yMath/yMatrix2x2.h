#pragma once

#include <yMath/yMath.h>
#include <yMath/yVector2D.h>

template<typename T>
class yCORE_API yTemplateMatrix2x2
{
public:
	inline yTemplateMatrix2x2();
	inline yTemplateMatrix2x2(T m11, T m12, T m21, T m22);
	inline yTemplateMatrix2x2(const T * values);
	template<typename U>
	inline yTemplateMatrix2x2(U m11, U m12, U m21, U m22);
	template<typename U>
	inline yTemplateMatrix2x2(const U * values);
	template<typename U>
	inline yTemplateMatrix2x2(const yTemplateMatrix2x2<U> & mat);

	inline bool isIdentity() const;
	inline void setToIdentity();

	inline yTemplateVector2D<T> row(int index) const;
	inline void setRow(int index, const yTemplateVector2D<T> & vec);
	inline void setRow(int index, T x, T y);

	inline yTemplateVector2D<T> column(int index) const;
	inline void setColumn(int index, const yTemplateVector2D<T> & vec);
	inline void setColumn(int index, T x, T y);

	inline T & at(int row, int column);
	inline T at(int row, int column) const;
	inline T & operator()(int row, int column) { return at(row, column); }
	inline T operator()(int row, int column) const { return at(row, column); }

	inline T * data() const { return *_data; }
	inline const T * data() const { return *_data; }
	inline const T * constData() const { return *_data; }

	inline void fill(T value);

	inline T determinant() const;
	inline yTemplateMatrix2x2<T> inverse() const;
	inline yTemplateMatrix2x2<T> transpose() const;

	inline yTemplateMatrix2x2<T> & operator*=(const yTemplateMatrix2x2<T> & mat);
	inline yTemplateMatrix2x2<T> & operator*=(T scalar);
	inline yTemplateMatrix2x2<T> & operator/=(const yTemplateMatrix2x2<T> & mat);
	inline yTemplateMatrix2x2<T> & operator/=(T scalar);
	inline yTemplateMatrix2x2<T> & operator+=(const yTemplateMatrix2x2<T> & mat);
	inline yTemplateMatrix2x2<T> & operator+=(T scalar);
	inline yTemplateMatrix2x2<T> & operator-=(const yTemplateMatrix2x2<T> & mat);
	inline yTemplateMatrix2x2<T> & operator-=(T scalar);

private:
	T _data[2][2];
};

template<typename T>
inline yTemplateMatrix2x2<T> operator*(const yTemplateMatrix2x2<T> & left, const yTemplateMatrix2x2<T> & right);
template<typename T>
inline yTemplateMatrix2x2<T> operator*(const yTemplateMatrix2x2<T> & left, T right);
template<typename T>
inline yTemplateMatrix2x2<T> operator*(T left, const yTemplateMatrix2x2<T> & right);
template<typename T>
inline yTemplateMatrix2x2<T> operator/(const yTemplateMatrix2x2<T> & left, const yTemplateMatrix2x2<T> & right);
template<typename T>
inline yTemplateMatrix2x2<T> operator/(const yTemplateMatrix2x2<T> & left, T right);
template<typename T>
inline yTemplateMatrix2x2<T> operator+(const yTemplateMatrix2x2<T> & left, const yTemplateMatrix2x2<T> & right);
template<typename T>
inline yTemplateMatrix2x2<T> operator+(const yTemplateMatrix2x2<T> & left, T right);
template<typename T>
inline yTemplateMatrix2x2<T> operator-(const yTemplateMatrix2x2<T> & left, const yTemplateMatrix2x2<T> & right);
template<typename T>
inline yTemplateMatrix2x2<T> operator-(const yTemplateMatrix2x2<T> & left, T right);

// yTemplateMatrix2x2 inline implementation
#include <yMath/inline/yMatrix2x2.inl>

//
// Typedefs for yTemplateMatrix2x2:
//
//   - yBoolMatrix2x2   -> 2 x 2 boolean matrix
//   - yIntMatrix2x2    -> 2 x 2 integer matrix
//   - yFloatMatrix2x2  -> 2 x 2 float matrix
//   - yDoubleMatrix2x2 -> 2 x 2 double matrix
//   - yMatrix2x2       -> 2 x 2 real matrix
//

typedef yTemplateMatrix2x2<bool> yBoolMatrix2x2;
typedef yTemplateMatrix2x2<int> yIntMatrix2x2;
typedef yTemplateMatrix2x2<float> yFloatMatrix2x2;
typedef yTemplateMatrix2x2<double> yDoubleMatrix2x2;
typedef yTemplateMatrix2x2<yreal> yMatrix2x2;