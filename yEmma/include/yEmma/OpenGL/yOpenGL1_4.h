#pragma once

#include <yEmma/OpenGL/yOpenGLCore.h>

#if defined(yUSE_OPENGL)

#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_COMPARE_R_TO_TEXTURE 0x884E

class yEMMA_API yOpenGL_1_4
{
public:
	typedef void (GLAPIENTRY * PFNGLBLENDCOLORPROC) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	typedef void (GLAPIENTRY * PFNGLBLENDEQUATIONPROC) (GLenum mode);
	typedef void (GLAPIENTRY * PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	typedef void (GLAPIENTRY * PFNGLFOGCOORDPOINTERPROC) (GLenum type, GLsizei stride, const void *pointer);
	typedef void (GLAPIENTRY * PFNGLFOGCOORDDPROC) (GLdouble coord);
	typedef void (GLAPIENTRY * PFNGLFOGCOORDDVPROC) (const GLdouble *coord);
	typedef void (GLAPIENTRY * PFNGLFOGCOORDFPROC) (GLfloat coord);
	typedef void (GLAPIENTRY * PFNGLFOGCOORDFVPROC) (const GLfloat *coord);
	typedef void (GLAPIENTRY * PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
	typedef void (GLAPIENTRY * PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei *count, GLenum type, const void *const* indices, GLsizei drawcount);
	typedef void (GLAPIENTRY * PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
	typedef void (GLAPIENTRY * PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat *params);
	typedef void (GLAPIENTRY * PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
	typedef void (GLAPIENTRY * PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint *params);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3BPROC) (GLbyte red, GLbyte green, GLbyte blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3DPROC) (GLdouble red, GLdouble green, GLdouble blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3FPROC) (GLfloat red, GLfloat green, GLfloat blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3IPROC) (GLint red, GLint green, GLint blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3IVPROC) (const GLint *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3SPROC) (GLshort red, GLshort green, GLshort blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3UBPROC) (GLubyte red, GLubyte green, GLubyte blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3UIPROC) (GLuint red, GLuint green, GLuint blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3USPROC) (GLushort red, GLushort green, GLushort blue);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLOR3USVPROC) (const GLushort *v);
	typedef void (GLAPIENTRY * PFNGLSECONDARYCOLORPOINTERPROC) (GLint size, GLenum type, GLsizei stride, const void *pointer);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2DPROC) (GLdouble x, GLdouble y);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2DVPROC) (const GLdouble *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2FPROC) (GLfloat x, GLfloat y);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2FVPROC) (const GLfloat *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2IPROC) (GLint x, GLint y);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2IVPROC) (const GLint *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2SPROC) (GLshort x, GLshort y);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS2SVPROC) (const GLshort *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3DPROC) (GLdouble x, GLdouble y, GLdouble z);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3DVPROC) (const GLdouble *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3FPROC) (GLfloat x, GLfloat y, GLfloat z);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3FVPROC) (const GLfloat *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3IPROC) (GLint x, GLint y, GLint z);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3IVPROC) (const GLint *p);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3SPROC) (GLshort x, GLshort y, GLshort z);
	typedef void (GLAPIENTRY * PFNGLWINDOWPOS3SVPROC) (const GLshort *p);

	static PFNGLBLENDCOLORPROC glBlendColor;
	static PFNGLBLENDEQUATIONPROC glBlendEquation;
	static PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
	static PFNGLFOGCOORDPOINTERPROC glFogCoordPointer;
	static PFNGLFOGCOORDDPROC glFogCoordd;
	static PFNGLFOGCOORDDVPROC glFogCoorddv;
	static PFNGLFOGCOORDFPROC glFogCoordf;
	static PFNGLFOGCOORDFVPROC glFogCoordfv;
	static PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
	static PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
	static PFNGLPOINTPARAMETERFPROC glPointParameterf;
	static PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
	static PFNGLPOINTPARAMETERIPROC glPointParameteri;
	static PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
	static PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b;
	static PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv;
	static PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d;
	static PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv;
	static PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f;
	static PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv;
	static PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i;
	static PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv;
	static PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s;
	static PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv;
	static PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub;
	static PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv;
	static PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui;
	static PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv;
	static PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us;
	static PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv;
	static PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer;
	static PFNGLWINDOWPOS2DPROC glWindowPos2d;
	static PFNGLWINDOWPOS2DVPROC glWindowPos2dv;
	static PFNGLWINDOWPOS2FPROC glWindowPos2f;
	static PFNGLWINDOWPOS2FVPROC glWindowPos2fv;
	static PFNGLWINDOWPOS2IPROC glWindowPos2i;
	static PFNGLWINDOWPOS2IVPROC glWindowPos2iv;
	static PFNGLWINDOWPOS2SPROC glWindowPos2s;
	static PFNGLWINDOWPOS2SVPROC glWindowPos2sv;
	static PFNGLWINDOWPOS3DPROC glWindowPos3d;
	static PFNGLWINDOWPOS3DVPROC glWindowPos3dv;
	static PFNGLWINDOWPOS3FPROC glWindowPos3f;
	static PFNGLWINDOWPOS3FVPROC glWindowPos3fv;
	static PFNGLWINDOWPOS3IPROC glWindowPos3i;
	static PFNGLWINDOWPOS3IVPROC glWindowPos3iv;
	static PFNGLWINDOWPOS3SPROC glWindowPos3s;
	static PFNGLWINDOWPOS3SVPROC glWindowPos3sv;

	static void init_opengl_functions_1_4();
};

#endif