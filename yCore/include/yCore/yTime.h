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

#ifndef _YON_TIME_HEADER_
#define _YON_TIME_HEADER_
#pragma once

#include <yCore/yCore.h>

yNAMESPACE_BEGIN

// C API

typedef struct yCORE_API yon_time yon_time;

yCORE_API yon_time * yon_create_time();
yCORE_API void yon_destroy_time(yon_time * time);

yCORE_API yon_time * yon_get_current_time(yon_time * time);
yCORE_API yon_time * yon_get_system_time(yon_time * time);

yCORE_API yuint64 yon_get_hours(yon_time * time);
yCORE_API yuint64 yon_get_minutes(yon_time * time);
yCORE_API yuint64 yon_get_seconds(yon_time * time);
yCORE_API yuint64 yon_get_milliseconds(yon_time * time);
yCORE_API yuint64 yon_get_microseconds(yon_time * time);

yCORE_API yon_time * yon_set_hours(yon_time * time, yuint64 hours);
yCORE_API yon_time * yon_set_minutes(yon_time * time, yuint64 minutes);
yCORE_API yon_time * yon_set_seconds(yon_time * time, yuint64 seconds);
yCORE_API yon_time * yon_set_milliseconds(yon_time * time, yuint64 milliseconds);
yCORE_API yon_time * yon_set_microseconds(yon_time * time, yuint64 microseconds);

yCORE_API yon_time * yon_add_hours(yon_time * time, yuint64 hours);
yCORE_API yon_time * yon_add_minutes(yon_time * time, yuint64 minutes);
yCORE_API yon_time * yon_add_seconds(yon_time * time, yuint64 seconds);
yCORE_API yon_time * yon_add_milliseconds(yon_time * time, yuint64 milliseconds);
yCORE_API yon_time * yon_add_microseconds(yon_time * time, yuint64 microseconds);

yCORE_API yon_time * yon_subtract_hours(yon_time * time, yuint64 hours);
yCORE_API yon_time * yon_subtract_minutes(yon_time * time, yuint64 minutes);
yCORE_API yon_time * yon_subtract_seconds(yon_time * time, yuint64 seconds);
yCORE_API yon_time * yon_subtract_milliseconds(yon_time * time, yuint64 milliseconds);
yCORE_API yon_time * yon_subtract_microseconds(yon_time * time, yuint64 microseconds);

// C++ API

#if defined(__cplusplus)
class yCORE_API yTime
{
public:
	inline yTime() : _ms(0) { }
	inline yTime(yuint64 milliseconds) : _ms(milliseconds) { }

	static yTime currentTime();
	static yTime systemTime();

	inline yuint64 hours() const { return _ms / 120000; }
	inline yuint64 minutes() const { return _ms / 60000; }
	inline yuint64 seconds() const { return _ms / 1000; }
	inline yuint64 milliseconds() const { return _ms; }
	inline yuint64 microseconds() const { return _ms * 1000; }

	inline void setHours(yuint64 hours) { _ms = hours * 120000; }
	inline void setMinutes(yuint64 minutes) { _ms = minutes * 60000; }
	inline void setSeconds(yuint64 seconds) { _ms = seconds * 1000; }
	inline void setMilliseconds(yuint64 milliseconds) { _ms = milliseconds; }
	inline void setMicroseconds(yuint64 microseconds) { _ms = microseconds / 1000; }

	inline void addHours(yuint64 hours) { _ms += hours * 120000; }
	inline void addMinutes(yuint64 minutes) { _ms += minutes * 60000; }
	inline void addSeconds(yuint64 seconds) { _ms += seconds * 1000; }
	inline void addMilliseconds(yuint64 milliseconds) { _ms += milliseconds; }
	inline void addMicroseconds(yuint64 microseconds) { _ms += microseconds / 1000; }

	inline void subtractHours(yuint64 hours) { _ms -= hours * 120000; }
	inline void subtractMinutes(yuint64 minutes) { _ms -= minutes * 60000; }
	inline void subtractSeconds(yuint64 seconds) { _ms -= seconds * 1000; }
	inline void subtractMilliseconds(yuint64 milliseconds) { _ms -= milliseconds; }
	inline void subtractMicroseconds(yuint64 microseconds) { _ms -= microseconds / 1000; }

	inline yTime & operator=(const yTime & other) { _ms = other._ms; return *this; }
	inline yTime & operator=(yuint64 milliseconds) { _ms = milliseconds; return *this; }
	inline yTime & operator*=(const yTime & other) { _ms *= other._ms; return *this; }
	inline yTime & operator*=(yuint64 milliseconds) { _ms *= milliseconds; return *this; }
	inline yTime & operator/=(const yTime & other) { _ms /= other._ms; return *this; }
	inline yTime & operator/=(yuint64 milliseconds) { _ms /= milliseconds; return *this; }
	inline yTime & operator+=(const yTime & other) { _ms += other._ms; return *this; }
	inline yTime & operator+=(yuint64 milliseconds) { _ms += milliseconds; return *this; }
	inline yTime & operator-=(const yTime & other) { _ms -= other._ms; return *this; }
	inline yTime & operator-=(yuint64 milliseconds) { _ms -= milliseconds; return *this; }

private:
	yuint64 _ms;
};

inline yTime operator*(const yTime & value1, const yTime & value2) { return yTime(value1.milliseconds() * value2.milliseconds()); }
inline yTime operator*(const yTime & value1, yuint64 value2) { return yTime(value1.milliseconds() * value2); }
inline yTime operator*(yuint64 value1, const yTime & value2) { return yTime(value1 * value2.milliseconds()); }
inline yTime operator/(const yTime & value1, const yTime & value2) { return yTime(value1.milliseconds() / value2.milliseconds()); }
inline yTime operator/(const yTime & value1, yuint64 value2) { return yTime(value1.milliseconds() / value2); }
inline yTime operator+(const yTime & value1, const yTime & value2) { return yTime(value1.milliseconds() + value2.milliseconds()); }
inline yTime operator+(const yTime & value1, yuint64 value2) { return yTime(value1.milliseconds() + value2); }
inline yTime operator-(const yTime & value1, const yTime & value2) { return yTime(value1.milliseconds() - value2.milliseconds()); }
inline yTime operator-(const yTime & value1, yuint64 value2) { return yTime(value1.milliseconds() - value2); }
#endif

yNAMESPACE_END

#endif // !_YON_TIME_HEADER_