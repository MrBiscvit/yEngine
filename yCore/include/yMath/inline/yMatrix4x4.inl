template<typename T>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4()
{
	setToIdentity();
}
template<typename T>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4(T m11, T m12, T m13, T m14, 
												 T m21, T m22, T m23, T m24, 
												 T m31, T m32, T m33, T m34, 
												 T m41, T m42, T m43, T m44)
{
	_data[0][0] = m11;
	_data[0][1] = m12;
	_data[0][2] = m13;
	_data[0][3] = m14;
	_data[1][0] = m21;
	_data[1][1] = m22;
	_data[1][2] = m23;
	_data[1][3] = m24;
	_data[2][0] = m31;
	_data[2][1] = m32;
	_data[2][2] = m33;
	_data[2][3] = m34;
	_data[3][0] = m31;
	_data[3][1] = m32;
	_data[3][2] = m33;
	_data[3][3] = m34;
}
template<typename T>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4(const T * values)
{
	_data = values;
}
template<typename T>
template<typename U>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4(U m11, U m12, U m13, U m14, 
												 U m21, U m22, U m23, U m24, 
												 U m31, U m32, U m33, U m34, 
												 U m41, U m42, U m43, U m44)
{
	_data[0][0] = static_cast<T>(m11);
	_data[0][1] = static_cast<T>(m12);
	_data[0][2] = static_cast<T>(m13);
	_data[0][3] = static_cast<T>(m14);
	_data[1][0] = static_cast<T>(m21);
	_data[1][1] = static_cast<T>(m22);
	_data[1][2] = static_cast<T>(m23);
	_data[1][3] = static_cast<T>(m24);
	_data[2][0] = static_cast<T>(m31);
	_data[2][1] = static_cast<T>(m32);
	_data[2][2] = static_cast<T>(m33);
	_data[2][3] = static_cast<T>(m34);
	_data[3][0] = static_cast<T>(m31);
	_data[3][1] = static_cast<T>(m32);
	_data[3][2] = static_cast<T>(m33);
	_data[3][3] = static_cast<T>(m34);
}
template<typename T>
template<typename U>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4(const U * values)
{
	_data = reinterpret_cast<const T*>(values);
}
template<typename T>
template<typename U>
inline yTemplateMatrix4x4<T>::yTemplateMatrix4x4(const yTemplateMatrix4x4<U>& mat)
{
	_data = reinterpret_cast<const T*>(mat.data());
}

template<typename T>
inline bool yTemplateMatrix4x4<T>::isIdentity() const
{
	return _data[0][0] == static_cast<T>(1) && _data[0][1] == static_cast<T>(0) &&
		_data[0][2] == static_cast<T>(0) && _data[0][3] == static_cast<T>(0) &&
		_data[1][0] == static_cast<T>(0) && _data[1][1] == static_cast<T>(1) &&
		_data[1][2] == static_cast<T>(0) && _data[1][3] == static_cast<T>(0) &&
		_data[2][0] == static_cast<T>(0) && _data[2][1] == static_cast<T>(0) &&
		_data[2][2] == static_cast<T>(1) && _data[2][3] == static_cast<T>(0) &&
		_data[3][0] == static_cast<T>(0) && _data[3][1] == static_cast<T>(0) &&
		_data[3][2] == static_cast<T>(0) && _data[3][3] == static_cast<T>(1);
}
template<typename T>
inline void yTemplateMatrix4x4<T>::setToIdentity()
{
	_data[0][0] = static_cast<T>(1);
	_data[0][1] = static_cast<T>(0);
	_data[0][2] = static_cast<T>(0);
	_data[0][3] = static_cast<T>(0);
	_data[1][0] = static_cast<T>(0);
	_data[1][1] = static_cast<T>(1);
	_data[1][2] = static_cast<T>(0);
	_data[1][3] = static_cast<T>(0);
	_data[2][0] = static_cast<T>(0);
	_data[2][1] = static_cast<T>(0);
	_data[2][2] = static_cast<T>(1);
	_data[2][3] = static_cast<T>(0);
	_data[3][0] = static_cast<T>(0);
	_data[3][1] = static_cast<T>(0);
	_data[3][2] = static_cast<T>(0);
	_data[3][3] = static_cast<T>(1);
}

template<typename T>
inline yTemplateVector4D<T> yTemplateMatrix4x4<T>::row(int index) const
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::row()", "out of range");

	return yTemplateVector4D<T>(_data[0][index], _data[1][index], 
								_data[2][index], _data[3][index]);
}
template<typename T>
inline void yTemplateMatrix4x4<T>::setRow(int index, const yTemplateVector4D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::setRow()", "out of range");

	_data[0][index] = vec.x();
	_data[1][index]	= vec.y();
	_data[2][index]	= vec.z();
	_data[3][index]	= vec.w();
}
template<typename T>
inline void yTemplateMatrix4x4<T>::setRow(int index, T x, T y, T z, T w)
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::setRow()", "out of range");

	_data[0][index] = x;
	_data[1][index] = y;
	_data[2][index] = z;
	_data[3][index] = w;
}

template<typename T>
inline yTemplateVector4D<T> yTemplateMatrix4x4<T>::column(int index) const
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::column()", "out of range");

	return yTemplateVector4D<T>(_data[index][0], _data[index][1],
								_data[index][2], _data[index][3]);
}
template<typename T>
inline void yTemplateMatrix4x4<T>::setColumn(int index, const yTemplateVector4D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::setColumn()", "out of range");

	_data[index][0] = vec.x();
	_data[index][1] = vec.y();
	_data[index][2] = vec.z();
	_data[index][3] = vec.w();
}
template<typename T>
inline void yTemplateMatrix4x4<T>::setColumn(int index, T x, T y, T z, T w)
{
	yASSERT_X(index >= 0 && index < 4, "yMatrix4x4::setColumn()", "out of range");

	_data[index][0] = x;
	_data[index][1] = y;
	_data[index][2] = z;
	_data[index][3] = w;
}

template<typename T>
inline T & yTemplateMatrix4x4<T>::at(int row, int column)
{
	yASSERT_X(column >= 0 && column < 4 && row >= 0 && row < 4, "yMatrix4x4::at()", "out of range");

	return _data[column][row];
}
template<typename T>
inline T yTemplateMatrix4x4<T>::at(int row, int column) const
{
	yASSERT_X(column >= 0 && column < 4 && row >= 0 && row < 4, "yMatrix4x4::at()", "out of range");

	return _data[column][row];
}

template<typename T>
inline void yTemplateMatrix4x4<T>::fill(T value)
{
	_data[0][0] = value;
	_data[0][1] = value;
	_data[0][2] = value;
	_data[0][3] = value;
	_data[1][0] = value;
	_data[1][1] = value;
	_data[1][2] = value;
	_data[1][3] = value;
	_data[2][0] = value;
	_data[2][1] = value;
	_data[2][2] = value;
	_data[2][3] = value;
	_data[3][0] = value;
	_data[3][1] = value;
	_data[3][2] = value;
	_data[3][3] = value;
}

template<typename T>
inline T yTemplateMatrix4x4<T>::determinant() const
{
	T det1 = _data[1][1] * ((_data[2][2] * _data[3][3]) - (_data[3][2] * _data[2][3])) -
		_data[2][1] * ((_data[1][2] * _data[3][3]) - (_data[3][2] * _data[1][3])) +
		_data[3][1] * ((_data[1][2] * _data[2][3]) - (_data[2][2] * _data[1][3]));

	T det2 = _data[0][1] * ((_data[2][2] * _data[3][3]) - (_data[3][2] * _data[2][3])) -
		_data[2][1] * ((_data[0][2] * _data[3][3]) - (_data[3][2] * _data[0][3])) +
		_data[3][1] * ((_data[0][2] * _data[2][3]) - (_data[2][2] * _data[0][3]));

	T det3 = _data[0][1] * ((_data[1][2] * _data[3][3]) - (_data[3][2] * _data[1][3])) -
		_data[1][1] * ((_data[0][2] * _data[3][3]) - (_data[3][2] * _data[0][3])) +
		_data[3][1] * ((_data[0][2] * _data[1][3]) - (_data[1][2] * _data[0][3]));

	T det4 = _data[0][1] * ((_data[1][2] * _data[2][3]) - (_data[2][2] * _data[1][3])) -
		_data[1][1] * ((_data[0][2] * _data[2][3]) - (_data[2][2] * _data[0][3])) +
		_data[2][1] * ((_data[0][2] * _data[1][3]) - (_data[1][2] * _data[0][3]));

	return _data[0][0] * det1 - _data[1][0] * det2 + _data[2][0] * det3 - _data[3][2] * det4;
}
template<typename T>
inline yTemplateMatrix4x4<T> yTemplateMatrix4x4<T>::inverse() const
{
	T coef00 = _data[2][2] * _data[3][3] - _data[3][2] * _data[2][3];
	T coef02 = _data[1][2] * _data[3][3] - _data[3][2] * _data[1][3];
	T coef03 = _data[1][2] * _data[2][3] - _data[2][2] * _data[1][3];

	T coef04 = _data[2][1] * _data[3][3] - _data[3][1] * _data[2][3];
	T coef06 = _data[1][1] * _data[3][3] - _data[3][1] * _data[1][3];
	T coef07 = _data[1][1] * _data[2][3] - _data[2][1] * _data[1][3];

	T coef08 = _data[2][1] * _data[3][2] - _data[3][1] * _data[2][2];
	T coef10 = _data[1][1] * _data[3][2] - _data[3][1] * _data[1][2];
	T coef11 = _data[1][1] * _data[2][2] - _data[2][1] * _data[1][2];

	T coef12 = _data[2][0] * _data[3][3] - _data[3][0] * _data[2][3];
	T coef14 = _data[1][0] * _data[3][3] - _data[3][0] * _data[1][3];
	T coef15 = _data[1][0] * _data[2][3] - _data[2][0] * _data[1][3];

	T coef16 = _data[2][0] * _data[3][2] - _data[3][0] * _data[2][2];
	T coef18 = _data[1][0] * _data[3][2] - _data[3][0] * _data[1][2];
	T coef19 = _data[1][0] * _data[2][2] - _data[2][0] * _data[1][2];

	T coef20 = _data[2][0] * _data[3][1] - _data[3][0] * _data[2][1];
	T coef22 = _data[1][0] * _data[3][1] - _data[3][0] * _data[1][1];
	T coef23 = _data[1][0] * _data[2][1] - _data[2][0] * _data[1][1];

	yTemplateVector4D<T> fac0(coef00, coef00, coef02, coef03);
	yTemplateVector4D<T> fac1(coef04, coef04, coef06, coef07);
	yTemplateVector4D<T> fac2(coef08, coef08, coef10, coef11);
	yTemplateVector4D<T> fac3(coef12, coef12, coef14, coef15);
	yTemplateVector4D<T> fac4(coef16, coef16, coef18, coef19);
	yTemplateVector4D<T> fac5(coef20, coef20, coef22, coef23);

	yTemplateVector4D<T> vec0(_data[1][0], _data[0][0], _data[0][0], _data[0][0]);
	yTemplateVector4D<T> vec1(_data[1][1], _data[0][1], _data[0][1], _data[0][1]);
	yTemplateVector4D<T> vec2(_data[1][2], _data[0][2], _data[0][2], _data[0][2]);
	yTemplateVector4D<T> vec3(_data[1][3], _data[0][3], _data[0][3], _data[0][3]);

	yTemplateVector4D<T> inv0(Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
	yTemplateVector4D<T> inv1(Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
	yTemplateVector4D<T> inv2(Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
	yTemplateVector4D<T> inv3(Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

	yTemplateVector4D<T> signA(+1, -1, +1, -1);
	yTemplateVector4D<T> signB(-1, +1, -1, +1);
	yTemplateMatrix4x4<T> inverse(inv0 * signA, inv1 * signB, inv2 * signA, inv3 * signB);

	yTemplateVector4D<T> row0(inverse._data[0][0], inverse._data[1][0], inverse._data[2][0], inverse._data[3][0]);

	yTemplateVector4D<T> dot0(m[0] * row0);
	T dot1 = (dot0.x + dot0.y) + (dot0.z + dot0.w);

	T oneOverDeterminant = static_cast<T>(1) / dot1;

	return inverse * oneOverDeterminant;
}
template<typename T>
inline yTemplateMatrix4x4<T> yTemplateMatrix4x4<T>::transpose() const
{
	return yTemplateMatrix4x4<T>(
		_data[0][0], _data[0][1], _data[0][2], _data[0][3],
		_data[1][0], _data[1][1], _data[1][2], _data[1][3],
		_data[2][0], _data[2][1], _data[2][2], _data[2][3],
		_data[3][0], _data[3][1], _data[3][2], _data[3][3]
		);
}

template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator*=(const yTemplateMatrix4x4<T>& mat)
{
	typename yTemplateVector4D<T> const srcA0 = column(0);
	typename yTemplateVector4D<T> const srcA1 = column(1);
	typename yTemplateVector4D<T> const srcA2 = column(2);
	typename yTemplateVector4D<T> const srcA3 = column(3);

	typename yTemplateVector4D<T> const srcB0 = mat.column(0);
	typename yTemplateVector4D<T> const srcB1 = mat.column(1);
	typename yTemplateVector4D<T> const srcB2 = mat.column(2);
	typename yTemplateVector4D<T> const srcB3 = mat.column(3);

	setColumn(0) = srcA0 * srcB0[0] + srcA1 * srcB0[1] + srcA2 * srcB0[2] + srcA3 * srcB0[3];
	setColumn(1) = srcA0 * srcB1[0] + srcA1 * srcB1[1] + srcA2 * srcB1[2] + srcA3 * srcB1[3];
	setColumn(2) = srcA0 * srcB2[0] + srcA1 * srcB2[1] + srcA2 * srcB2[2] + srcA3 * srcB2[3];
	setColumn(3) = srcA0 * srcB3[0] + srcA1 * srcB3[1] + srcA2 * srcB3[2] + srcA3 * srcB3[3];

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator*=(T scalar)
{
	_data[0][0] *= scalar;
	_data[0][1] *= scalar;
	_data[0][2] *= scalar;
	_data[0][3] *= scalar;
	_data[1][0] *= scalar;
	_data[1][1] *= scalar;
	_data[1][2] *= scalar;
	_data[1][3] *= scalar;
	_data[2][0] *= scalar;
	_data[2][1] *= scalar;
	_data[2][2] *= scalar;
	_data[2][3] *= scalar;
	_data[3][0] *= scalar;
	_data[3][1] *= scalar;
	_data[3][2] *= scalar;
	_data[3][3] *= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator/=(const yTemplateMatrix4x4<T>& mat)
{
	*this *= mat.inverse();
	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator/=(T scalar)
{
	_data[0][0] /= scalar;
	_data[0][1] /= scalar;
	_data[0][2] /= scalar;
	_data[0][3] /= scalar;
	_data[1][0] /= scalar;
	_data[1][1] /= scalar;
	_data[1][2] /= scalar;
	_data[1][3] /= scalar;
	_data[2][0] /= scalar;
	_data[2][1] /= scalar;
	_data[2][2] /= scalar;
	_data[2][3] /= scalar;
	_data[3][0] /= scalar;
	_data[3][1] /= scalar;
	_data[3][2] /= scalar;
	_data[3][3] /= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator+=(const yTemplateMatrix4x4<T>& mat)
{
	_data[0][0] += mat._data[0][0];
	_data[0][1] += mat._data[0][1];
	_data[0][2] += mat._data[0][2];
	_data[0][3] += mat._data[0][3];
	_data[1][0] += mat._data[1][0];
	_data[1][1] += mat._data[1][1];
	_data[1][2] += mat._data[1][2];
	_data[1][3] += mat._data[1][3];
	_data[2][0] += mat._data[2][0];
	_data[2][1] += mat._data[2][1];
	_data[2][2] += mat._data[2][2];
	_data[2][3] += mat._data[2][3];
	_data[3][0] += mat._data[3][0];
	_data[3][1] += mat._data[3][1];
	_data[3][2] += mat._data[3][2];
	_data[3][3] += mat._data[3][3];

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator+=(T scalar)
{
	_data[0][0] += scalar;
	_data[0][1] += scalar;
	_data[0][2] += scalar;
	_data[0][3] += scalar;
	_data[1][0] += scalar;
	_data[1][1] += scalar;
	_data[1][2] += scalar;
	_data[1][3] += scalar;
	_data[2][0] += scalar;
	_data[2][1] += scalar;
	_data[2][2] += scalar;
	_data[2][3] += scalar;
	_data[3][0] += scalar;
	_data[3][1] += scalar;
	_data[3][2] += scalar;
	_data[3][3] += scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator-=(const yTemplateMatrix4x4<T>& mat)
{
	_data[0][0] -= mat._data[0][0];
	_data[0][1] -= mat._data[0][1];
	_data[0][2] -= mat._data[0][2];
	_data[0][3] -= mat._data[0][3];
	_data[1][0] -= mat._data[1][0];
	_data[1][1] -= mat._data[1][1];
	_data[1][2] -= mat._data[1][2];
	_data[1][3] -= mat._data[1][3];
	_data[2][0] -= mat._data[2][0];
	_data[2][1] -= mat._data[2][1];
	_data[2][2] -= mat._data[2][2];
	_data[2][3] -= mat._data[2][3];
	_data[3][0] -= mat._data[3][0];
	_data[3][1] -= mat._data[3][1];
	_data[3][2] -= mat._data[3][2];
	_data[3][3] -= mat._data[3][3];

	return *this;
}
template<typename T>
inline yTemplateMatrix4x4<T>& yTemplateMatrix4x4<T>::operator-=(T scalar)
{
	_data[0][0] -= scalar;
	_data[0][1] -= scalar;
	_data[0][2] -= scalar;
	_data[0][3] -= scalar;
	_data[1][0] -= scalar;
	_data[1][1] -= scalar;
	_data[1][2] -= scalar;
	_data[1][3] -= scalar;
	_data[2][0] -= scalar;
	_data[2][1] -= scalar;
	_data[2][2] -= scalar;
	_data[2][3] -= scalar;
	_data[3][0] -= scalar;
	_data[3][1] -= scalar;
	_data[3][2] -= scalar;
	_data[3][3] -= scalar;

	return *this;
}

template<typename T>
inline yTemplateMatrix4x4<T> operator*(const yTemplateMatrix4x4<T>& left, const yTemplateMatrix4x4<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator*(const yTemplateMatrix4x4<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator*(T left, const yTemplateMatrix4x4<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator/(const yTemplateMatrix4x4<T>& left, const yTemplateMatrix4x4<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator/(const yTemplateMatrix4x4<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator+(const yTemplateMatrix4x4<T>& left, const yTemplateMatrix4x4<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator+(const yTemplateMatrix4x4<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator-(const yTemplateMatrix4x4<T>& left, const yTemplateMatrix4x4<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateMatrix4x4<T> operator-(const yTemplateMatrix4x4<T>& left, T right)
{
	return left -= right;
}