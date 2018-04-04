// 
// MIT License
// 
// Copyright(c) 2018 Hubert Gruniaux
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef _YON_CHRONO_HEADER_
#define _YON_CHRONO_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <yCore/yTime.h>

yNAMESPACE_BEGIN

// C API

typedef struct yCORE_API yon_chrono yon_chrono;

yCORE_API yon_chrono * yon_create_chrono();
yCORE_API void yon_destroy_chrono(yon_chrono * chrono);

yCORE_API void yon_start_chrono(yon_chrono * chrono);
yCORE_API yon_time * yon_restart_chrono(yon_chrono * chrono, yon_time * elapsed);
yCORE_API yon_time * yon_elapsed_chrono(yon_chrono * chrono, yon_time * elapsed);

// C++ API

#if defined(__cplusplus)
class yCORE_API yChrono
{
public:
	inline yChrono() : _lastTime() { }

	inline void start() { _lastTime = yTime::currentTime(); }
	inline yTime restart() { yTime e = elapsed(); start(); return e; }
	inline yTime elapsed() const { return yTime::currentTime() - _lastTime; }

private:
	yTime _lastTime;
};
#endif

yNAMESPACE_END

#endif // !_YON_CHRONO_HEADER_