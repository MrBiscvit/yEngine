#pragma once

#include <yEmma/yEmma.h>

#if defined(yUSE_DIRECT3D)
#  include <Windows.h>
#  include <d3d9.h>
#  if defined(yUSE_DIRECT3D_10)
#    include <d3d10.h>
#  endif
#  if defined(yUSE_DIRECT3D_11)
#    include <d3d11.h>
#  endif
#  if defined(yUSE_DIRECT3D_12)
#    include <d3d12.h>
#  endif
#endif