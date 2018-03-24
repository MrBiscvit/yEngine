#pragma once

#include <yEmma/yEmma.h>

#if defined(yUSE_OPENGL)
#include <GL/glew.h>

#ifndef yBUFFER_OFFSET
#  define yBUFFER_OFFSET(Offset) ((char*))NULL+(Offset))
#endif
#endif