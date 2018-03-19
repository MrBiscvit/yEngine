#include <yCore/yTime.h>
#if defined(yOS_WINDOWS)
#include <Windows.h>

yTime yTime::currentTime()
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	yTime result;
	result.addHours(time.wHour);
	result.addMinutes(time.wMinute);
	result.addSeconds(time.wSecond);
	result.addMilliseconds(time.wMilliseconds);

	return result;
}

#endif