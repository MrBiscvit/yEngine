#pragma once

#include <yEmma/OpenGL/yOpenGLCore.h>

#if defined(yUSE_OPENGL)

#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_CLAMP_TO_BORDER 0x812D
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_SUBTRACT 0x84E7
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
#define GL_MULTISAMPLE_BIT 0x20000000

class yEMMA_API yOpenGL_1_3
{
public:
	typedef void (GLAPIENTRY * PFNGLACTIVETEXTUREPROC) (GLenum texture);
	typedef void (GLAPIENTRY * PFNGLCLIENTACTIVETEXTUREPROC) (GLenum texture);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
	typedef void (GLAPIENTRY * PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, void *img);
	typedef void (GLAPIENTRY * PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble m[16]);
	typedef void (GLAPIENTRY * PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat m[16]);
	typedef void (GLAPIENTRY * PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble m[16]);
	typedef void (GLAPIENTRY * PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat m[16]);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1DPROC) (GLenum target, GLdouble s);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1DVPROC) (GLenum target, const GLdouble *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1FPROC) (GLenum target, GLfloat s);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1FVPROC) (GLenum target, const GLfloat *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1IPROC) (GLenum target, GLint s);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1IVPROC) (GLenum target, const GLint *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1SPROC) (GLenum target, GLshort s);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD1SVPROC) (GLenum target, const GLshort *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2DPROC) (GLenum target, GLdouble s, GLdouble t);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2DVPROC) (GLenum target, const GLdouble *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2FPROC) (GLenum target, GLfloat s, GLfloat t);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2FVPROC) (GLenum target, const GLfloat *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2IPROC) (GLenum target, GLint s, GLint t);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2IVPROC) (GLenum target, const GLint *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2SPROC) (GLenum target, GLshort s, GLshort t);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD2SVPROC) (GLenum target, const GLshort *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3DVPROC) (GLenum target, const GLdouble *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3FVPROC) (GLenum target, const GLfloat *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3IPROC) (GLenum target, GLint s, GLint t, GLint r);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3IVPROC) (GLenum target, const GLint *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3SPROC) (GLenum target, GLshort s, GLshort t, GLshort r);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD3SVPROC) (GLenum target, const GLshort *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4DPROC) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4DVPROC) (GLenum target, const GLdouble *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4FPROC) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4FVPROC) (GLenum target, const GLfloat *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4IPROC) (GLenum target, GLint s, GLint t, GLint r, GLint q);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4IVPROC) (GLenum target, const GLint *v);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4SPROC) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	typedef void (GLAPIENTRY * PFNGLMULTITEXCOORD4SVPROC) (GLenum target, const GLshort *v);
	typedef void (GLAPIENTRY * PFNGLSAMPLECOVERAGEPROC) (GLclampf value, GLboolean invert);

	static PFNGLACTIVETEXTUREPROC glActiveTexture;
	static PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;
	static PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
	static PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
	static PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
	static PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
	static PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
	static PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd;
	static PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf;
	static PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd;
	static PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf;
	static PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d;
	static PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv;
	static PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f;
	static PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv;
	static PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i;
	static PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv;
	static PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s;
	static PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv;
	static PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d;
	static PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv;
	static PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f;
	static PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv;
	static PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i;
	static PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv;
	static PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s;
	static PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv;
	static PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d ;
	static PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv;
	static PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f ;
	static PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
	static PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i ;
	static PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv;
	static PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s;
	static PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv;
	static PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d;
	static PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv;
	static PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f;
	static PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv;
	static PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i;
	static PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv;
	static PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s;
	static PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv;
	static PFNGLSAMPLECOVERAGEPROC glSampleCoverage;

	static void init_opengl_functions_1_3();
};

#endif