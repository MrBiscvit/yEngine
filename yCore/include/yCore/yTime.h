#pragma once

#include <yCore/yCore.h>

class yCORE_API yTime
{
public:
	inline yTime();
	inline yTime(yint64 milliseconds);

	inline bool isNull() const;

	inline double hour() const;
	inline double minutes() const;
	inline float seconds() const;
	inline yint64 milliseconds() const;
	inline yint64 microseconds() const;

	inline yTime addHours(int hours) const;
	inline yTime addMinutes(int minutes) const;
	inline yTime addSeconds(int seconds) const;
	inline yTime addMilliseconds(int milliseconds) const;
	inline yTime addMicroseconds(int microseconds) const;

	inline yTime & operator*=(const yTime & other);
	inline yTime & operator/=(const yTime & other);
	inline yTime & operator+=(const yTime & other);
	inline yTime & operator-=(const yTime & other);

	static yTime currentTime();

private:
	yint64 _ms; // milliseconds
};

inline yTime operator*(const yTime & value1, const yTime & value2);
inline yTime operator/(const yTime & value1, const yTime & value2);
inline yTime operator+(const yTime & value1, const yTime & value2);
inline yTime operator-(const yTime & value1, const yTime & value2);

// Implementation
#include <yCore/inline/yTime.inl>