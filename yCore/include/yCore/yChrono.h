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

class yCORE_API yChrono
{
public:
	inline yChrono() : _lastTime() { }

	inline void start() { _lastTime = now()); }
	inline yClockTime restart() { yClockTime e = elapsed(); start(); return e; }
	inline yClockTime elapsed() const { return now() - _lastTime; }

	static yClockTime now();

private:
	yClockTime _lastTime;
};

yNAMESPACE_END

#endif // !_YON_CHRONO_HEADER_