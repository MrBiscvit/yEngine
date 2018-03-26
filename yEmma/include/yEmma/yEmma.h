#pragma once

#include <yCore/yGlobal.h>

#define yEMMA_MAJOR 1
#define yEMMA_MINOR 0
#define yEMMA_PATCH 0
#define yEMMA_VERSION yVERSION(yEMMA_MAJOR, yEMMA_MINOR, yEMMA_PATCH)

#if defined(yEMMA_STATIC)
#  define yEMMA_API
#else
#  if defined(yEMMA_BUILD)
#    define yEMMA_API yDECL_EXPORT
#  else
#    define yEMMA_API yDECL_IMPORT
#  endif
#endif

#if defined(yUSE_OPENGL) && defined(yUSE_DIRECT3D)
#  error You can only define one of these macros: yUSE_OPENGL or yUSE_DIRECT3D
#elif !defined(yUSE_OPENGL) && !defined(yUSE_DIRECT3D)
#  if defined(yOS_WINDOWS)
#    define yUSE_DIRECT3D
#  else
#    define yUSE_OPENGL
#  endif
#endif

// TODO: Remove this macros
// Only for OpenGL implementation
#undef yUSE_DIRECT3D
#define yUSE_OPENGL

#if defined(yUSE_DIRECT3D)
#  if !defined(yUSE_DIRECT3D_12) && !defined(yUSE_DIRECT3D_11) && !defined(yUSE_DIRECT3D_9)
#    define yUSE_DIRECT3D_11
#  endif
#endif

#if defined(yUSE_OPENGL)
#include <yEmma/OpenGL/yOpenGL.h>
#elif defined(yUSE_DIRECT3D)
#include <yEmma/Direct3D/yDirect3D.h>
#endif