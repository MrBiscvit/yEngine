#pragma once

#include <yEmma/OpenGL/yOpenGLCore.h>
#include <yEmma/OpenGL/yOpenGL1_1.h>
#include <yEmma/OpenGL/yOpenGL1_2.h>
#include <yEmma/OpenGL/yOpenGL1_3.h>
#include <yEmma/OpenGL/yOpenGL1_4.h>

#if defined(yUSE_OPENGL)

class yEMMA_API yOpenGL : 
	public yOpenGL_1_1, public yOpenGL_1_2, public yOpenGL_1_3,
	public yOpenGL_1_4
{
public:
	void init();
};
#endif