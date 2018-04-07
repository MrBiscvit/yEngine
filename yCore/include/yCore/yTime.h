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

class yCORE_API yTime
{
public:
	inline yTime() : _hours(0), _minutes(0), _seconds(0), _milliseconds(0) { }
	inline yTime(int hours, int minutes, int seconds, int milliseconds = 0) { setTime(hours, minutes, seconds, milliseconds); }

	bool isNull() const;
	bool isValid() const;

	inline int hours() const { return int(_hours); }
	inline int minutes() const { return int(_minutes); }
	inline int seconds() const { return int(_seconds); }
	inline int milliseconds() const { return int(_milliseconds); }

	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);
	void addMilliseconds(int milliseconds);

	void setTime(int hours, int minutes, int seconds, int milliseconds = 0);

	static yTime currentTime();
	static yTime currentUTCTime();

private:
	yuint8 _hours; // Hours, [0..23]
	yuint8 _minutes; // Minutes, [0..59]
	yuint8 _seconds; // Seconds, [0..59]
	yuint16 _milliseconds; // Milliseconds, [0..999]
};

class yCORE_API yClockTime
{
public:
	inline yClockTime() : _milliseconds(0) { }
	inline yClockTime(yuint64 milliseconds) : _milliseconds(milliseconds) { }

	inline bool isNull() const { return _milliseconds == 0; }
	
	inline double hours() const { return double(minutes()) / 60; }
	inline double minutes() const { return double(seconds()) / 60; }
	inline float seconds() const { return _milliseconds / 1000; }
	inline yuint64 milliseconds() const { return _milliseconds; }
	inline yuint64 microseconds() const { return _milliseconds * 1000; }

	static yClockTime hours(float hours) { return yClockTime(hours * 120000); }
	static yClockTime minutes(float minutes) { return yClockTime(minutes * 60000); }
	static yClockTime seconds(float seconds) { return yClockTime(seconds * 1000); }
	static yClockTime milliseconds(yuint64 milliseconds) { return yClockTime(milliseconds); }
	static yClockTime microseconds(yuint64 microseconds) { return yClockTime(microseconds / 1000); }

	inline yClockTime & operator*=(const yClockTime & other) { _milliseconds *= other._milliseconds; return *this; }
	inline yClockTime & operator/=(const yClockTime & other) { _milliseconds /= other._milliseconds; return *this; }
	inline yClockTime & operator+=(const yClockTime & other) { _milliseconds += other._milliseconds; return *this; }
	inline yClockTime & operator-=(const yClockTime & other) { _milliseconds -= other._milliseconds; return *this; }

private:
	yuint64 _milliseconds;
};

inline yClockTime operator*(const yClockTime & v1, const yClockTime & v2) { return yClockTime(v1.milliseconds() * v2.milliseconds()); }
inline yClockTime operator/(const yClockTime & v1, const yClockTime & v2) { return yClockTime(v1.milliseconds() / v2.milliseconds()); }
inline yClockTime operator+(const yClockTime & v1, const yClockTime & v2) { return yClockTime(v1.milliseconds() + v2.milliseconds()); }
inline yClockTime operator-(const yClockTime & v1, const yClockTime & v2) { return yClockTime(v1.milliseconds() - v2.milliseconds()); }

yNAMESPACE_END

#endif // !_YON_TIME_HEADER_