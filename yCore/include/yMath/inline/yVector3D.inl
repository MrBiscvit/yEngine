template<typename T>
inline yTemplateVector3D<T>::yTemplateVector3D() :
	_x(static_cast<T>(0)), _y(static_cast<T>(0)), 
	_z(static_cast<T>(0))
{
}
template<typename T>
inline yTemplateVector3D<T>::yTemplateVector3D(T scalar) :
	_x(scalar), _y(scalar), _z(scalar)
{
}
template<typename T>
inline yTemplateVector3D<T>::yTemplateVector3D(T x, T y, T z) :
	_x(x), _y(y), _z(z)
{
}
template<typename T>
template<typename U>
inline yTemplateVector3D<T>::yTemplateVector3D(U x, U y, U z) :
	_x(static_cast<T>(x)), _y(static_cast<T>(y)),
	_z(static_cast<T>(z))
{
}
template<typename T>
template<typename U>
inline yTemplateVector3D<T>::yTemplateVector3D(const yTemplateVector3D<U>& vec) :
	_x(static_cast<T>(vec.x())), _y(static_cast<T>(vec.y())),
	_z(static_cast<T>(vec.z()))
{
}

template<typename T>
inline bool yTemplateVector3D<T>::isNull() const
{
	return _x == static_cast<T>(0) && _y == static_cast<T>(0) &&
		_z == static_cast<T>(0);
}

template<typename T>
inline yTemplateVector3D<T> yTemplateVector3D<T>::normalize() const
{
	T l = yAbs(length());
	return yTemplateVector3D<T>(_x / l, _y / l, _z / l);
}
template<typename T>
inline T yTemplateVector3D<T>::length() const
{
	return ySqrt(_x * _x + _y * _y + _z * _z);
}
template<typename T>
inline T yTemplateVector3D<T>::distance(const yTemplateVector3D<T>& vec) const
{
	return ySqrt(yPow(vec._x - _x, 2) + yPow(vec._y - _y, 2) + 
				 yPow(vec._z - _z, 2));
}
template<typename T>
inline T yTemplateVector3D<T>::dot(const yTemplateVector3D<T>& vec)
{
	return _x * _x + _y * _y + _z * _z;
}
template<typename T>
inline yTemplateVector3D<T> yTemplateVector3D<T>::cross(const yTemplateVector3D<T>& vec)
{
	return yTemplateVector3D<T>(_y * _z - _z * _y,
								_z * _x - _x * _z,
								_x * _z - _z * _x);
}

template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator*=(const yTemplateVector3D<T>& vec)
{
	_x *= vec._x;
	_y *= vec._y;
	_z *= vec._z;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator*=(T scalar)
{
	_x *= scalar;
	_y *= scalar;
	_z *= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator/=(const yTemplateVector3D<T>& vec)
{
	_x /= vec._x;
	_y /= vec._y;
	_z /= vec._z;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator/=(T scalar)
{
	_x /= scalar;
	_y /= scalar;
	_z /= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator+=(const yTemplateVector3D<T>& vec)
{
	_x += vec._x;
	_y += vec._y;
	_z += vec._z;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator+=(T scalar)
{
	_x += scalar;
	_y += scalar;
	_z += scalar;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator-=(const yTemplateVector3D<T>& vec)
{
	_x -= vec._x;
	_y -= vec._y;
	_z -= vec._z;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator-=(T scalar)
{
	_x -= scalar;
	_y -= scalar;
	_z -= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator++()
{
	++_x;
	++_y;
	++_z;
	return *this;
}
template<typename T>
inline yTemplateVector3D<T>& yTemplateVector3D<T>::operator--()
{
	--_x;
	--_y;
	--_z;
	return *this;
}

template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T>& vec)
{
	return yTemplateVector3D<T>(+vec.x(), +vec.y(), +vec.z());
}
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T>& vec)
{
	return yTemplateVector3D<T>(-vec.x(), -vec.y(), -vec.z());
}
template<typename T>
inline yTemplateVector3D<T> operator++(const yTemplateVector3D<T> & vec, int)
{
	return (++yTemplateVector3D<T>(vec));
}
template<typename T>
inline yTemplateVector3D<T> operator--(const yTemplateVector3D<T> & vec, int)
{
	return (--yTemplateVector3D<T>(vec));
}

template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T>& left, const yTemplateVector3D<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector3D<T> operator*(const yTemplateVector3D<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector3D<T> operator*(T left, const yTemplateVector3D<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T>& left, const yTemplateVector3D<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector3D<T> operator/(const yTemplateVector3D<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T>& left, const yTemplateVector3D<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector3D<T> operator+(const yTemplateVector3D<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T>& left, const yTemplateVector3D<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateVector3D<T> operator-(const yTemplateVector3D<T>& left, T right)
{
	return left -= right;
}