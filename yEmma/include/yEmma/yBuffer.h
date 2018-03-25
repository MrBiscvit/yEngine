#pragma once

#include <yEmma/yEmma.h>

template<typename T>
class yEMMA_API yBuffer
{
public:

	void lock();
	void unlock();

private:
#if defined(yUSE_OPENGL)
	GLuint _id;
#elif defined(yUSE_DIRECT3D)
	T * _data;
#endif
};