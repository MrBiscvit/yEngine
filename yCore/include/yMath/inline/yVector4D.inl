template<typename T>
inline yTemplateVector4D<T>::yTemplateVector4D() :
	_x(static_cast<T>(0)), _y(static_cast<T>(0)),
	_z(static_cast<T>(0)), _w(static_cast<T>(0))
{
}
template<typename T>
inline yTemplateVector4D<T>::yTemplateVector4D(T scalar) :
	_x(scalar), _y(scalar), _z(scalar), _w(scalar)
{
}
template<typename T>
inline yTemplateVector4D<T>::yTemplateVector4D(T x, T y, T z, T w) :
	_x(x), _y(y), _z(z), _w(w)
{
}
template<typename T>
template<typename U>
inline yTemplateVector4D<T>::yTemplateVector4D(U x, U y, U z, U w) :
	_x(static_cast<T>(x)), _y(static_cast<T>(y)),
	_z(static_cast<T>(z)), _w(static_cast<T>(w))
{
}
template<typename T>
template<typename U>
inline yTemplateVector4D<T>::yTemplateVector4D(const yTemplateVector4D<U>& vec) :
	_x(static_cast<T>(vec.x())), _y(static_cast<T>(vec.y())),
	_z(static_cast<T>(vec.z())), _w(static_cast<T>(vec.w()))
{
}

template<typename T>
inline bool yTemplateVector4D<T>::isNull() const
{
	return _x == static_cast<T>(0) && _y == static_cast<T>(0)
		_z == static_cast<T>(0) && _w == static_cast<T>(0);
}

template<typename T>
inline yTemplateVector4D<T> yTemplateVector4D<T>::normalize() const
{
	T l = yAbs(length());
	return yTemplateVector4D<T>(_x / l, _y / l, _z / l, _w / l);
}
template<typename T>
inline T yTemplateVector4D<T>::length() const
{
	return ySqrt(_x * _x + _y * _y + _z * _z + _w * _w);
}
template<typename T>
inline T yTemplateVector4D<T>::distance(const yTemplateVector4D<T>& vec) const
{
	return ySqrt(yPow(vec._x - _x, 2) + yPow(vec._y - _y, 2) +
				 yPow(vec._z - _z, 2) + yPow(vec._w - _w, 2));
}
template<typename T>
inline T yTemplateVector4D<T>::dot(const yTemplateVector4D<T>& vec)
{
	return _x * _x + _y * _y + _z * _z + _w * _w;
}

template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator*=(const yTemplateVector4D<T>& vec)
{
	_x *= vec._x; 
	_y *= vec._y; 
	_z *= vec._z; 
	_w *= vec._w;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator*=(T scalar)
{
	_x *= scalar; 
	_y *= scalar;
	_z *= scalar;
	_w *= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator/=(const yTemplateVector4D<T>& vec)
{
	_x /= vec._x; 
	_y /= vec._y; 
	_z /= vec._z; 
	_w /= vec._w;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator/=(T scalar)
{
	_x /= scalar; 
	_y /= scalar; 
	_z /= scalar; 
	_w /= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator+=(const yTemplateVector4D<T>& vec)
{
	_x += vec._x;
	_y += vec._y;
	_z += vec._z;
	_w += vec._w;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator+=(T scalar)
{
	_x += scalar;
	_y += scalar;
	_z += scalar;
	_w += scalar;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator-=(const yTemplateVector4D<T>& vec)
{
	_x -= vec._x;
	_y -= vec._y;
	_z -= vec._z;
	_w -= vec._w;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator-=(T scalar)
{
	_x -= scalar;
	_y -= scalar;
	_z -= scalar;
	_w -= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator++()
{
	++_x;
	++_y;
	++_z;
	++_w;
	return *this;
}
template<typename T>
inline yTemplateVector4D<T>& yTemplateVector4D<T>::operator--()
{
	--_x;
	--_y;
	--_z;
	--_w;
	return *this;
}

template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T>& vec)
{
	return yTemplateVector4D<T>(+vec.x(), +vec.y(), +vec.z(), +vec.w());
}
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T>& vec)
{
	return yTemplateVector4D<T>(-vec.x(), -vec.y(), -vec.z(), -vec.w());
}
template<typename T>
inline yTemplateVector4D<T> operator++(const yTemplateVector4D<T> & vec, int)
{
	return (++yTemplateVector4D<T>(vec));
}
template<typename T>
inline yTemplateVector4D<T> operator--(const yTemplateVector4D<T> & vec, int)
{
	return (--yTemplateVector4D<T>(vec));
}

template<typename T>
inline yTemplateVector4D<T> operator*(const yTemplateVector4D<T>& left, const yTemplateVector4D<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector4D<T> operator*(const yTemplateVector4D<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector4D<T> operator*(T left, const yTemplateVector4D<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateVector4D<T> operator/(const yTemplateVector4D<T>& left, const yTemplateVector4D<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector4D<T> operator/(const yTemplateVector4D<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T>& left, const yTemplateVector4D<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector4D<T> operator+(const yTemplateVector4D<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T>& left, const yTemplateVector4D<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateVector4D<T> operator-(const yTemplateVector4D<T>& left, T right)
{
	return left -= right;
}