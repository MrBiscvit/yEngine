template<typename T>
inline yTemplateVector2D<T>::yTemplateVector2D() :
	_x(static_cast<T>(0)), _y(static_cast<T>(0))
{
}
template<typename T>
inline yTemplateVector2D<T>::yTemplateVector2D(T scalar) :
	_x(scalar), _y(scalar)
{
}
template<typename T>
inline yTemplateVector2D<T>::yTemplateVector2D(T x, T y) :
	_x(x), _y(y)
{
}
template<typename T>
template<typename U>
inline yTemplateVector2D<T>::yTemplateVector2D(U x, U y) :
	_x(static_cast<T>(x)), _y(static_cast<T>(y))
{
}
template<typename T>
template<typename U>
inline yTemplateVector2D<T>::yTemplateVector2D(const yTemplateVector2D<U>& vec) :
	_x(static_cast<T>(vec.x())), _y(static_cast<T>(vec.y()))
{
}

template<typename T>
inline bool yTemplateVector2D<T>::isNull() const
{
	return _x == static_cast<T>(0) && _y == static_cast<T>(0);
}

template<typename T>
inline yTemplateVector2D<T> yTemplateVector2D<T>::normalize() const
{
	T l = yAbs(length());
	return yTemplateVector2D<T>(_x / l, _y / l);
}
template<typename T>
inline T yTemplateVector2D<T>::length() const
{
	return ySqrt(_x * _x + _y * _y);
}
template<typename T>
inline T yTemplateVector2D<T>::distance(const yTemplateVector2D<T>& vec) const
{
	return ySqrt(yPow((vec._x - _x), 2) + yPow((vec._y - _y), 2));
}
template<typename T>
inline T yTemplateVector2D<T>::dot(const yTemplateVector2D<T>& vec)
{
	return _x * _x + _y * _y;
}

template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator*=(const yTemplateVector2D<T>& vec)
{
	_x *= vec._x;
	_y *= vec._y;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator*=(T scalar)
{
	_x *= scalar;
	_y *= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator/=(const yTemplateVector2D<T>& vec)
{
	_x /= vec._x;
	_y /= vec._y;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator/=(T scalar)
{
	_x /= scalar;
	_y /= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator+=(const yTemplateVector2D<T>& vec)
{
	_x += vec._x;
	_y += vec._y;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator+=(T scalar)
{
	_x += scalar;
	_y += scalar;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator-=(const yTemplateVector2D<T>& vec)
{
	_x -= vec._x;
	_y -= vec._y;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator-=(T scalar)
{
	_x -= scalar;
	_y -= scalar;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator++()
{
	++_x;
	++_y;
	return *this;
}
template<typename T>
inline yTemplateVector2D<T>& yTemplateVector2D<T>::operator--()
{
	--_x;
	--_y;
	return *this;
}

template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T>& vec)
{
	return yTemplateVector2D<T>(+vec.x(), +vec.y());
}
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T>& vec)
{
	return yTemplateVector2D<T>(-vec.x(), -vec.y());
}
template<typename T>
inline yTemplateVector2D<T> operator++(const yTemplateVector2D<T> & vec, int)
{
	return (++yTemplateVector2D<T>(vec));
}
template<typename T>
inline yTemplateVector2D<T> operator--(const yTemplateVector2D<T> & vec, int)
{
	return (--yTemplateVector2D<T>(vec));
}

template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T>& left, const yTemplateVector2D<T>& right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector2D<T> operator*(const yTemplateVector2D<T>& left, T right)
{
	return left *= right;
}
template<typename T>
inline yTemplateVector2D<T> operator*(T left, const yTemplateVector2D<T>& right)
{
	return right *= left;
}
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T>& left, const yTemplateVector2D<T>& right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector2D<T> operator/(const yTemplateVector2D<T>& left, T right)
{
	return left /= right;
}
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T>& left, const yTemplateVector2D<T>& right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector2D<T> operator+(const yTemplateVector2D<T>& left, T right)
{
	return left += right;
}
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T>& left, const yTemplateVector2D<T>& right)
{
	return left -= right;
}
template<typename T>
inline yTemplateVector2D<T> operator-(const yTemplateVector2D<T>& left, T right)
{
	return left -= right;
}