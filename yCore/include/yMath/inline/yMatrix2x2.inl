template<typename T>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2()
{
	setToIdentity();
}
template<typename T>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2(T m11, T m12, T m21, T m22)
{
	_data[0][0] = m11;
	_data[0][1] = m12;
	_data[1][0] = m21;
	_data[1][1] = m22;
}
template<typename T>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2(const T * values)
{
	_data = values;
}
template<typename T>
template<typename U>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2(U m11, U m12, U m21, U m22)
{
	_data[0][0] = static_cast<T>(m11);
	_data[0][1] = static_cast<T>(m12);
	_data[1][0] = static_cast<T>(m21);
	_data[1][1] = static_cast<T>(m22);
}
template<typename T>
template<typename U>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2(const U * values)
{
	_data = reinterpret_cast<const T*>(values);
}
template<typename T>
template<typename U>
inline yTemplateMatrix2x2<T>::yTemplateMatrix2x2(const yTemplateMatrix2x2<U>& mat)
{
	_data = reinterpret_cast<const T*>(mat.data());
}

template<typename T>
inline bool yTemplateMatrix2x2<T>::isIdentity() const
{
	return _data[0][0] == static_cast<T>(1) && _data[0][1] == static_cast<T>(0) &&
		_data[1][0] == static_cast<T>(0) && _data[1][1] == static_cast<T>(0);
}
template<typename T>
inline void yTemplateMatrix2x2<T>::setToIdentity()
{
	_data[0][0] = static_cast<T>(1);
	_data[0][1] = static_cast<T>(0);
	_data[1][0] = static_cast<T>(0);
	_data[1][1] = static_cast<T>(1);
}

template<typename T>
inline yTemplateVector2D<T> yTemplateMatrix2x2<T>::row(int index) const
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::row()", "out of range");

	return yTemplateVector2D<T>(_data[0][index], _data[1][index]);
}
template<typename T>
inline void yTemplateMatrix2x2<T>::setRow(int index, const yTemplateVector2D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::setRow()", "out of range");

	_data[0][index] = vec.x(); _data[1][index] = vec.y();
}
template<typename T>
inline void yTemplateMatrix2x2<T>::setRow(int index, T x, T y)
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::setRow()", "out of range");

	_data[0][index] = x; _data[1][index] = y;
}

template<typename T>
inline yTemplateVector2D<T> yTemplateMatrix2x2<T>::column(int index) const
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::column()", "out of range");

	return yTemplateVector2D<T>(_data[index][0], _data[index][1]);
}
template<typename T>
inline void yTemplateMatrix2x2<T>::setColumn(int index, const yTemplateVector2D<T>& vec)
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::setColumn()", "out of range");

	_data[index][0] = vec.x(); _data[index][1] = vec.y();
}
template<typename T>
inline void yTemplateMatrix2x2<T>::setColumn(int index, T x, T y)
{
	yASSERT_X(index >= 0 && index < 2, "yMatrix2x2::setColumn()", "out of range");

	_data[index][0] = x; _data[index][1] = y;
}

template<typename T>
inline T & yTemplateMatrix2x2<T>::at(int row, int column)
{
	yASSERT_X(column >= 0 && column < 2 && row >= 0 && row < 2, "yMatrix2x2::at()", "out of range");

	return _data[column][row];
}
template<typename T>
inline T yTemplateMatrix2x2<T>::at(int row, int column) const
{
	yASSERT_X(column >= 0 && column < 2 && row >= 0 && row < 2, "yMatrix2x2::at()", "out of range");

	return _data[column][row];
}

template<typename T>
inline void yTemplateMatrix2x2<T>::fill(T value)
{
	_data[0][0] = value;
	_data[0][1] = value;
	_data[1][0] = value;
	_data[1][1] = value;
}

template<typename T>
inline T yTemplateMatrix2x2<T>::determinant() const
{
	return _data[0][0] * _data[1][1] - _data[1][0] * _data[0][1];
}
template<typename T>
inline yTemplateMatrix2x2<T> yTemplateMatrix2x2<T>::inverse() const
{
	T d = static_cast<T>(1.f / determinant());
	return yTemplateMatrix2x2<T>(
		_data[0][0] * d, -_data[0][1] * d,
		-_data[1][0] * d, _data[1][1] * d
		);
}
template<typename T>
inline yTemplateMatrix2x2<T> yTemplateMatrix2x2<T>::transpose() const
{
	return yTemplateMatrix2x2<T>(
		_data[0][0], _data[1][0],
		_data[0][1], _data[1][1]
		);
}

template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator*=(const yTemplateMatrix2x2<T>& mat)
{
	_data[0][0] = _data[0][0] * mat._data[0][0] + _data[1][0] * mat._data[0][1];
	_data[1][0] = _data[0][1] * mat._data[0][0] + _data[1][1] * mat._data[0][1];
	_data[0][1] = _data[0][0] * mat._data[1][0] + _data[1][0] * mat._data[1][1];
	_data[1][1] = _data[0][1] * mat._data[1][0] + _data[1][1] * mat._data[1][1];

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator*=(T scalar)
{
	_data[0][0] *= scalar;
	_data[0][1] *= scalar;
	_data[1][0] *= scalar;
	_data[1][1] *= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator/=(const yTemplateMatrix2x2<T>& mat)
{
	*this *= mat.inverse();
	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator/=(T scalar)
{
	_data[0][0] /= scalar;
	_data[0][1] /= scalar;
	_data[1][0] /= scalar;
	_data[1][1] /= scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator+=(const yTemplateMatrix2x2<T>& mat)
{
	_data[0][0] += mat._data[0][0];
	_data[0][1] += mat._data[0][1];
	_data[1][0] += mat._data[1][0];
	_data[1][1] += mat._data[1][1];

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator+=(T scalar)
{
	_data[0][0] += scalar;
	_data[0][1] += scalar;
	_data[1][0] += scalar;
	_data[1][1] += scalar;

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator-=(const yTemplateMatrix2x2<T>& mat)
{
	_data[0][0] -= mat._data[0][0];
	_data[0][1] -= mat._data[0][1];
	_data[1][0] -= mat._data[1][0];
	_data[1][1] -= mat._data[1][1];

	return *this;
}
template<typename T>
inline yTemplateMatrix2x2<T>& yTemplateMatrix2x2<T>::operator-=(T scalar)
{
	_data[0][0] -= scalar;
	_data[0][1] -= scalar;
	_data[1][0] -= scalar;
	_data[1][1] -= scalar;

	return *this;
}

template<typename T>
inline yTemplateMatrix2x2<T> operator*(const yTemplateMatrix2x2<T>& left, const yTemplateMatrix2x2<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator*(const yTemplateMatrix2x2<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator*(T left, const yTemplateMatrix2x2<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator/(const yTemplateMatrix2x2<T>& left, const yTemplateMatrix2x2<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator/(const yTemplateMatrix2x2<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator+(const yTemplateMatrix2x2<T>& left, const yTemplateMatrix2x2<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator+(const yTemplateMatrix2x2<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator-(const yTemplateMatrix2x2<T>& left, const yTemplateMatrix2x2<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateMatrix2x2<T> operator-(const yTemplateMatrix2x2<T>& left, T right)
{
	return left -= right;
}