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
#include <ctime>

yNAMESPACE_BEGIN

bool yTime::isNull() const
{
	return _hours == 0 && _minutes == 0 &&
		_seconds == 0 && _milliseconds == 0;
}
bool yTime::isValid() const
{
	return _hours >= 0 && _hours < 24 &&
		_minutes >= 0 && _minutes < 60 &&
		_seconds >= 0 & _seconds < 60 &&
		_milliseconds >= 0 && _milliseconds < 999;
}

void yTime::addHours(int hours)
{
	_hours += hours;
}
void yTime::addMinutes(int minutes)
{
	if (minutes >= 0) {
		if (minutes >= 60) {
			int hours = minutes / 60;
			minutes = minutes % 60;
			addHours(hours);
		}

		_minutes += minutes;
	} else {
		minutes = yAbs(minutes);
		if (minutes >= 60) {
			int hours = minutes / 60;
			minutes = minutes % 60;
			addHours(-hours);
		}

		_minutes -= minutes;
	}
}
void yTime::addSeconds(int seconds)
{
	if (seconds >= 0) {
		if (seconds >= 60) {
			int minutes = seconds / 60;
			seconds = seconds % 60;
			addMinutes(minutes);
		}

		_seconds += seconds;
	} else {
		seconds = yAbs(seconds);
		if (seconds >= 60) {
			int minutes = seconds / 60;
			seconds = seconds % 60;
			addMinutes(-minutes);
		}

		_seconds -= seconds;
	}
}
void yTime::addMilliseconds(int milliseconds)
{
	if (milliseconds >= 0) {
		if (milliseconds >= 1000) {
			int seconds = milliseconds / 1000;
			milliseconds = milliseconds % 1000;
			addSeconds(seconds);
		}

		_milliseconds += milliseconds;
	} else {
		milliseconds = yAbs(milliseconds);
		if (milliseconds >= 1000) {
			int seconds = milliseconds / 1000;
			milliseconds = milliseconds % 1000;
			addSeconds(-seconds);
		}

		_milliseconds -= milliseconds;
	}
}

void yTime::setTime(int hours, int minutes, int seconds, int milliseconds)
{
	_hours = _minutes = _seconds = _milliseconds = 0;
	addHours(hours);
	addMinutes(minutes);
	addSeconds(seconds);
	addMilliseconds(milliseconds);
}

yTime yTime::currentTime()
{
	std::time_t now = std::time(yNULLPTR);
#if defined(yCC_MVSC)
	std::tm * nowTime = yNULLPTR;
	localtime_s(nowTime, &now);
#else
	std::tm * nowTime = localtime(&now);
#endif

	yTime time;
	time._hours = nowTime->tm_hour;
	time._minutes = nowTime->tm_min;
	time._seconds = nowTime->tm_sec;
	return time;

}
yTime yTime::currentUTCTime()
{
	std::time_t now = std::time(yNULLPTR);
#if defined(yCC_MVSC)
	std::tm * nowTime = yNULLPTR;
	gmtime_s(nowTime, &now);
#else
	std::tm * nowTime = gmtime(&now);
#endif

	yTime time;
	time._hours = nowTime->tm_hour;
	time._minutes = nowTime->tm_min;
	time._seconds = nowTime->tm_sec;
	return time;
}

yNAMESPACE_END