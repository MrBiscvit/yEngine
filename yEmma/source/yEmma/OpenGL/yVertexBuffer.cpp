#include <yEmma/yVertexBuffer.h>
#if defined(yUSE_OPENGL)
#include <yEmma/OpenGL/yOpenGL.h>

class yVertexBuffer::Private
{
public:
	unsigned int _id;
};

yVertexBuffer::~yVertexBuffer()
{
	delete _p;
}

#endif