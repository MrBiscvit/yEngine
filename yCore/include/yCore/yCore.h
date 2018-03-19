#pragma once

#include <yCore/yGlobal.h>

#define yCORE_MAJOR 1
#define yCORE_MINOR 0
#define yCORE_PATCH 0
#define yCORE_VERSION yVERSION(yCORE_MAJOR, yCORE_MINOR, yCORE_PATCH)

#if defined(yCORE_STATIC)
#  define yCORE_API
#else
#  if defined(yCORE_BUILD)
#    define yCORE_API yDECL_EXPORT
#  else
#    define yCORE_API yDECL_IMPORT
#  endif
#endif