#pragma once

#include <yEmma/yEmma.h>

#if defined(yUSE_OPENGL)
#if defined(yOS_WINDOWS)
#  ifdef APIENTRY
#    ifndef GLAPIENTRY
#      define GLAPIENTRY APIENTRY
#    endif
#  else
#    if defined(__MINGW32__) || defined(__CYGWIN__) || (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
#      define APIENTRY __stdcall
#      ifndef GLAPIENTRY
#        define GLAPIENTRY __stdcall
#      endif
#    else
#      define APIENTRY
#    endif
#  endif
#  ifndef CALLBACK
#    if defined(__MINGW32__) || defined(__CYGWIN__)
#      define CALLBACK __attribute__ ((__stdcall__))
#    elif (defined(_M_MRX000) || defined(_M_IX86) || defined(_M_ALPHA) || defined(_M_PPC)) && !defined(MIDL_PASS)
#      define CALLBACK __stdcall
#    else
#      define CALLBACK
#    endif
#  endif
#  ifndef WINGDIAPI
#    define WINGDIAPI __declspec(dllimport)
#  endif
#  ifndef GLAPI
#    if defined(__MINGW32__) || defined(__CYGWIN__)
#      define GLAPI extern
#    else
#      define GLAPI WINGDIAPI
#    endif
#  endif
#else
#  define APIENTRY
#  ifndef GLAPI
#    define GLAPI extern
#  endif
#endif

#ifndef GLAPIENTRY
#  define GLAPIENTRY
#endif

#if defined(yOS_WINDOWS)
#include <Windows.h>
#elif defined(yOS_MACOS)
#include <mach-o/dyld.h>
#endif

#if defined(yOS_MACOS)
#  include <OpenGL/OpenGL.h>
#  include <OpenGL/glu.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#endif

typedef yuint8 GLboolean;
typedef yint8 GLbyte;
typedef yuint8 GLubyte;
typedef yint16 GLshort;
typedef yuint16 GLushort;
typedef yint32 GLint;
typedef yuint32 GLuint;
typedef GLint GLlong;
typedef GLuint GLulong;
typedef yint64 GLint64;
typedef yuint64 GLuint64;
typedef GLint64 GLint64EXT;
typedef GLuint64 GLuint64EXT;

typedef GLuint GLenum;
typedef GLuint GLbitfield;
typedef GLint GLsizei;

typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;

typedef void GLvoid;

typedef struct __GLsync * GLsync;

inline static void * yon_load_opengl_function(const char * name)
{
#if defined(yOS_WINDOWS)
	return (void*)wglGetProcAddress(name);
#elif defined(yOS_MACOS)
	// Copied from the apple developer documentation
	NSSymbol symbol;
	char *symbolName;
	symbolName = malloc(strlen(name) + 2);
	strcpy(symbolName + 1, name);
	symbolName[0] = '_';
	symbol = NULL;
	if (NSIsSymbolNameDefined(symbolName))
		symbol = NSLookupAndBindSymbol(symbolName);
	free(symbolName);
	return symbol ? NSAddressOfSymbol(symbol) : NULL;
#else
	return (void*)glXGetProcAddress((const GLubyte *)name);
#endif
}
template<typename T>
inline static T glGetProcAddress(const char * name)
{
	return reinterpret_cast<T>(yon_load_opengl_function(name));
}
#endif