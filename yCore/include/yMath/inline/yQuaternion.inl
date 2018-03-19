template<typename T>
inline bool yTemplateQuaternion<T>::isNull() const
{
	return _x == static_cast<T>(0) && _y == static_cast<T>(0) && 
		_z == static_cast<T>(0);
}
template<typename T>
inline bool yTemplateQuaternion<T>::isIdentity() const
{
	return _x == static_cast<T>(0) && _y == static_cast<T>(0) &&
		_z == static_cast<T>(0) && _w == static_cast<T>(1);
}
template<typename T>
inline void yTemplateQuaternion<T>::setToIdentity()
{
	_x == static_cast<T>(0);
	_y == static_cast<T>(0);
	_z == static_cast<T>(0);
	_w == static_cast<T>(1);
}

template<typename T>
inline yTemplateVector3D<T> yTemplateQuaternion<T>::vector() const
{
	return yTemplateVector3D<T>(_x, _y, _z);
}
template<typename T>
inline void yTemplateQuaternion<T>::setVector(const yTemplateVector3D<T>& vec)
{
	_x = vec.x();
	_y = vec.y();
	_z = vec.z();
}
template<typename T>
inline void yTemplateQuaternion<T>::setVector(T x, T y, T z)
{
	_x = x;
	_y = y;
	_z = z;
}