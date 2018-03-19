template<typename T>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3()
{
	setToIdentity();
}
template<typename T>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3(T m11, T m12, T m13, 
												 T m21, T m22, T m23, 
												 T m31, T m32, T m33)
{
	_data[0][0] = m11;
	_data[0][1] = m12;
	_data[0][2] = m13;
	_data[1][0] = m21;
	_data[1][1] = m22;
	_data[1][2] = m23;
	_data[2][0] = m31;
	_data[2][1] = m32;
	_data[2][2] = m33;
}
template<typename T>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3(const T * values)
{
	_data = values;
}
template<typename T>
template<typename U>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3(U m11, U m12, U m13, 
												 U m21, U m22, U m23, 
												 U m31, U m32, U m33)
{
	_data[0][0] = static_cast<T>(m11);
	_data[0][1] = static_cast<T>(m12);
	_data[0][2] = static_cast<T>(m13);
	_data[1][0] = static_cast<T>(m21);
	_data[1][1] = static_cast<T>(m22);
	_data[1][2] = static_cast<T>(m23);
	_data[2][0] = static_cast<T>(m31);
	_data[2][1] = static_cast<T>(m32);
	_data[2][2] = static_cast<T>(m33);
}
template<typename T>
template<typename U>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3(const U * values)
{
	_data = reinterpret_cast<const T*>(values);
}
template<typename T>
template<typename U>
inline yTemplateMatrix3x3<T>::yTemplateMatrix3x3(const yTemplateMatrix3x3<U>& mat)
{
	_data = reinterpret_cast<const T*>(mat.data());
}

template<typename T>
inline bool yTemplateMatrix3x3<T>::isIdentity() const
{
	return _data[0][0] == static_cast<T>(1) && _data[0][1] == static_cast<T>(0) && _data[0][2] == static_cast<T>(0) &&
		_data[1][0] == static_cast<T>(0) && _data[1][1] == static_cast<T>(1) && _data[1][2] == static_cast<T>(0) &&
		_data[2][0] == static_cast<T>(0) && _data[2][1] == static_cast<T>(0) && _data[2][2] == static_cast<T>(1);
}
template<typename T>
inline void yTemplateMatrix3x3<T>::setToIdentity()
{
	_data[0][0] == static_cast<T>(1);
	_data[0][1] == static_cast<T>(0);
	_data[0][2] == static_cast<T>(0);
	_data[1][0] == static_cast<T>(0);
	_data[1][1] == static_cast<T>(1);
	_data[1][2] == static_cast<T>(0);
	_data[2][0] == static_cast<T>(0);
	_data[2][1] == static_cast<T>(0);
	_data[2][2] == static_cast<T>(1);
}

template<typename T>
inline yTemplateVector3D<T> yTemplateMatrix3x3<T>::row(int index) const
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::row()", "out of range");

	return yTemplateVector3D<T>(_data[0][index], _data[1][index], _data[2][index]);
}
template<typename T>
inline void yTemplateMatrix3x3<T>::setRow(int index, const yTemplateVector3D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::row()", "out of range");

	_data[0][index] = vec.x();
	_data[1][index] = vec.y();
	_data[2][index] = vec.z();
}
template<typename T>
inline void yTemplateMatrix3x3<T>::setRow(int index, T x, T y, T z)
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::row()", "out of range");

	_data[0][index] = x;
	_data[1][index] = y;
	_data[2][index] = z;
}

template<typename T>
inline yTemplateVector3D<T> yTemplateMatrix3x3<T>::column(int index) const
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::column()", "out of range");

	return yTemplateVector3D<T>(_data[index][0], _data[index][1], _data[index][2]);
}
template<typename T>
inline void yTemplateMatrix3x3<T>::setColumn(int index, const yTemplateVector3D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::column()", "out of range");

	_data[index][0] = vec.x();
	_data[index][1] = vec.y();
	_data[index][2] = vec.z();
}
template<typename T>
inline void yTemplateMatrix3x3<T>::setColumn(int index, T x, T y, T z)
{
	yASSERT_X(index >= 0 && index < 3, "yMatrix3x3::column()", "out of range");

	_data[index][0] = x;
	_data[index][1] = y;
	_data[index][2] = z;
}

template<typename T>
inline T & yTemplateMatrix3x3<T>::at(int row, int column)
{
	yASSERT_X(column >= 0 && column < 3 && row >= 0 && row < 3, "yMatrix3x3::at()", "out of range");

	return _data[column][row];
}
template<typename T>
inline T yTemplateMatrix3x3<T>::at(int row, int column) const
{
	yASSERT_X(column >= 0 && column < 3 && row >= 0 && row < 3, "yMatrix3x3::at()", "out of range");

	return _data[column][row];
}

template<typename T>
inline void yTemplateMatrix3x3<T>::fill(T value)
{
	_data[0][0] == value;
	_data[0][1] == value;
	_data[0][2] == value;
	_data[1][0] == value;
	_data[1][1] == value;
	_data[1][2] == value;
	_data[2][0] == value;
	_data[2][1] == value;
	_data[2][2] == value;
}

template<typename T>
inline T yTemplateMatrix3x3<T>::determinant() const
{
	return _data[0][0] * ((_data[1][1] * _data[2][2]) - (_data[2][1] * _data[1][2])) -
		_data[1][0] * ((_data[0][1] * _data[2][2]) - (_data[2][1] * _data[0][2])) +
		_data[2][0] * ((_data[0][1] * _data[1][2]) - (_data[1][1] * _data[0][2]));
}
template<typename T>
inline yTemplateMatrix3x3<T> yTemplateMatrix3x3<T>::inverse() const
{
	T det = static_cast<T>(1) / determinant();

	yTemplateMatrix3x3<T> result;
	result._data[0][0] = +(_data[1][1] * _data[2][2] - _data[2][1] * _data[1][2]) * det;
	result._data[1][0] = -(_data[1][0] * _data[2][2] - _data[2][0] * _data[1][2]) * det;
	result._data[2][0] = +(_data[1][0] * _data[2][1] - _data[2][0] * _data[1][1]) * det;
	result._data[0][1] = -(_data[0][1] * _data[2][2] - _data[2][1] * _data[0][2]) * det;
	result._data[1][1] = +(_data[0][0] * _data[2][2] - _data[2][0] * _data[0][2]) * det;
	result._data[2][1] = -(_data[0][0] * _data[2][1] - _data[2][0] * _data[0][1]) * det;
	result._data[0][2] = +(_data[0][1] * _data[1][2] - _data[1][1] * _data[0][2]) * det;
	result._data[1][2] = -(_data[0][0] * _data[1][2] - _data[1][0] * _data[0][2]) * det;
	result._data[2][2] = +(_data[0][0] * _data[1][1] - _data[1][0] * _data[0][1]) * det;

	return result;
}
template<typename T>
inline yTemplateMatrix3x3<T> yTemplateMatrix3x3<T>::transpose() const
{
	return yTemplateMatrix3x3<T>(
		_data[0][0], _data[0][1], _data[0][2],
		_data[1][0], _data[1][1], _data[1][2],
		_data[2][0], _data[2][1], _data[2][2],
		);
}

template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator*=(const yTemplateMatrix3x3<T>& mat)
{
	const T srcA00 = _data[0][0];
	const T srcA01 = _data[0][1];
	const T srcA02 = _data[0][2];
	const T srcA10 = _data[1][0];
	const T srcA11 = _data[1][1];
	const T srcA12 = _data[1][2];
	const T srcA20 = _data[2][0];
	const T srcA21 = _data[2][1];
	const T srcA22 = _data[2][2];

	const T srcB00 = mat._data[0][0];
	const T srcB01 = mat._data[0][1];
	const T srcB02 = mat._data[0][2];
	const T srcB10 = mat._data[1][0];
	const T srcB11 = mat._data[1][1];
	const T srcB12 = mat._data[1][2];
	const T srcB20 = mat._data[2][0];
	const T srcB21 = mat._data[2][1];
	const T srcB22 = mat._data[2][2];

	_data[0][0] = srcA00 * srcB00 + srcA10 * srcB01 + srcA20 * srcB02;
	_data[0][1] = srcA01 * srcB00 + srcA11 * srcB01 + srcA21 * srcB02;
	_data[0][2] = srcA02 * srcB00 + srcA12 * srcB01 + srcA22 * srcB02;
	_data[1][0] = srcA00 * srcB10 + srcA10 * srcB11 + srcA20 * srcB12;
	_data[1][1] = srcA01 * srcB10 + srcA11 * srcB11 + srcA21 * srcB12;
	_data[1][2] = srcA02 * srcB10 + srcA12 * srcB11 + srcA22 * srcB12;
	_data[2][0] = srcA00 * srcB20 + srcA10 * srcB21 + srcA20 * srcB22;
	_data[2][1] = srcA01 * srcB20 + srcA11 * srcB21 + srcA21 * srcB22;
	_data[2][2] = srcA02 * srcB20 + srcA12 * srcB21 + srcA22 * srcB22;

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator*=(T scalar)
{
	_data[0][0] *= scalar;
	_data[0][1] *= scalar;
	_data[0][2] *= scalar;
	_data[1][0] *= scalar;
	_data[1][1] *= scalar;
	_data[1][2] *= scalar;
	_data[2][0] *= scalar;
	_data[2][1] *= scalar;
	_data[2][2] *= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator/=(const yTemplateMatrix3x3<T>& mat)
{
	*this *= mat.inverse();
	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator/=(T scalar)
{
	_data[0][0] /= scalar;
	_data[0][1] /= scalar;
	_data[0][2] /= scalar;
	_data[1][0] /= scalar;
	_data[1][1] /= scalar;
	_data[1][2] /= scalar;
	_data[2][0] /= scalar;
	_data[2][1] /= scalar;
	_data[2][2] /= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator+=(const yTemplateMatrix3x3<T>& mat)
{
	_data[0][0] += mat._data[0][0];
	_data[0][1] += mat._data[0][1];
	_data[0][2] += mat._data[0][2];
	_data[1][0] += mat._data[1][0];
	_data[1][1] += mat._data[1][1];
	_data[1][2] += mat._data[1][2];
	_data[2][0] += mat._data[2][0];
	_data[2][1] += mat._data[2][1];
	_data[2][2] += mat._data[2][2];

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator+=(T scalar)
{
	_data[0][0] += scalar;
	_data[0][1] += scalar;
	_data[0][2] += scalar;
	_data[1][0] += scalar;
	_data[1][1] += scalar;
	_data[1][2] += scalar;
	_data[2][0] += scalar;
	_data[2][1] += scalar;
	_data[2][2] += scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator-=(const yTemplateMatrix3x3<T>& mat)
{
	_data[0][0] -= mat._data[0][0];
	_data[0][1] -= mat._data[0][1];
	_data[0][2] -= mat._data[0][2];
	_data[1][0] -= mat._data[1][0];
	_data[1][1] -= mat._data[1][1];
	_data[1][2] -= mat._data[1][2];
	_data[2][0] -= mat._data[2][0];
	_data[2][1] -= mat._data[2][1];
	_data[2][2] -= mat._data[2][2];

	return *this;
}
template<typename T>
inline yTemplateMatrix3x3<T>& yTemplateMatrix3x3<T>::operator-=(T scalar)
{
	_data[0][0] -= scalar;
	_data[0][1] -= scalar;
	_data[0][2] -= scalar;
	_data[1][0] -= scalar;
	_data[1][1] -= scalar;
	_data[1][2] -= scalar;
	_data[2][0] -= scalar;
	_data[2][1] -= scalar;
	_data[2][2] -= scalar;

	return *this;
}

template<typename T>
inline yTemplateMatrix3x3<T> operator*(const yTemplateMatrix3x3<T>& left, const yTemplateMatrix3x3<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator*(const yTemplateMatrix3x3<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator*(T left, const yTemplateMatrix3x3<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator/(const yTemplateMatrix3x3<T>& left, const yTemplateMatrix3x3<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator/(const yTemplateMatrix3x3<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator+(const yTemplateMatrix3x3<T>& left, const yTemplateMatrix3x3<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator+(const yTemplateMatrix3x3<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator-(const yTemplateMatrix3x3<T>& left, const yTemplateMatrix3x3<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateMatrix3x3<T> operator-(const yTemplateMatrix3x3<T>& left, T right)
{
	return left -= right;
}