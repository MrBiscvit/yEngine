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

#include <yCore/yTime.h>
#include <yCore/yMemory.h>
#if defined(_WIN32)
#include <Windows.h>
#else
#include <time.h>
#endif

yNAMESPACE_BEGIN

yTime yTime::currentTime()
{
	yTime time;
#if defined(_WIN32)
	LARGE_INTEGER frequency;
	LARGE_INTEGER t;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&t);

	time.setMicroseconds(1000000 * t.QuadPart / frequency.QuadPart);
#else
	timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	time.setMicroseconds(time, t.tv_sec * 1000000 + t.tv_nsec / 1000);
#endif
	return time;
}
yTime yTime::systemTime()
{
	yTime t;
#if defined(_WIN32)
	SYSTEMTIME systemTime;
	GetSystemTime(&systemTime);
	t._ms = systemTime.wHour * 1200000 +
		systemTime.wMinute * 60000 +
		systemTime.wSecond * 1000 +
		systemTime.wMilliseconds;
#else
	time_t t = time(NULL);
	struct tm currentTime = *localtime(&t);
	t._ms = tm.tm_hour * 1200000 +
		tm.tm_min * 60000 +
		tm.tm_sec * 1000;
#endif

	return t;
}

yNAMESPACE_END