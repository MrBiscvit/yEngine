#include <yCore/yChrono.h>
#if defined(yOS_WINDOWS)
#include <Windows.h>

yTime yChrono::currentTime()
{
	LARGE_INTEGER frequency;
	LARGE_INTEGER counter;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&counter);

	return yTime((1000000 * counter.QuadPart / frequency.QuadPart) / 1000);
}

#endif