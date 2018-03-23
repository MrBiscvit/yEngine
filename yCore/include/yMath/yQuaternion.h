#pragma once

#include <yMath/yMath.h>
#include <yMath/yMatrix4x4.h>
#include <yMath/yVector3D.h>
#include <yMath/yVector4D.h>

// TODO: Finish implementation of yTemplateQuaternion<T>

template<typename T>
class yCORE_API yTemplateQuaternion
{
public:

	inline bool isNull() const;
	inline bool isIdentity() const;
	inline void setToIdentity();

	inline T x() const { return _x; }
	inline void setX(T x) { _x = x; }

	inline T y() const { return _y; }
	inline void setY(T y) { _y = y; }

	inline T z() const { return _z; }
	inline void setZ(T z) { _z = z };

	inline yTemplateVector3D<T> vector() const;
	inline void setVector(const yTemplateVector3D<T> & vec);
	inline void setVector(T x, T y, T z);

	inline T scalar() const { return _w; }
	inline void setScalar(T w) { _w = w };



private:
	T _x, _y, _z, _w;
};

// Implementation
#include <yMath/inline/yQuaternion.inl>

typedef yTemplateQuaternion<bool> yBoolQuaternion;
typedef yTemplateQuaternion<int> yIntQuaternion;
typedef yTemplateQuaternion<float> yFloatQuaternion;
typedef yTemplateQuaternion<double> yDoubleQuaternion;
typedef yTemplateQuaternion<yreal> yQuaternion;