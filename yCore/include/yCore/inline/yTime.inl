inline yTime::yTime() :
	_ms(0)
{
}
inline yTime::yTime(yint64 milliseconds) :
	_ms(milliseconds)
{
}

inline bool yTime::isNull() const
{
	return _ms == 0;
}

inline double yTime::hour() const
{
	return minutes() / 60.;
}
inline double yTime::minutes() const
{
	return seconds() / 60.;
}
inline float yTime::seconds() const
{
	return milliseconds() / 1000.f;
}
inline yint64 yTime::milliseconds() const
{
	return _ms;
}
inline yint64 yTime::microseconds() const
{
	return milliseconds() * 1000;
}

inline yTime yTime::addHours(int hours) const
{
	return yTime(_ms + yint64(hours * 3600000));
}
inline yTime yTime::addMinutes(int minutes) const
{
	return yTime(_ms + yint64(minutes * 60000));
}
inline yTime yTime::addSeconds(int seconds) const
{
	return yTime(_ms + yint64(seconds * 1000));
}
inline yTime yTime::addMilliseconds(int milliseconds) const
{
	return yTime(_ms + yint64(milliseconds));
}
inline yTime yTime::addMicroseconds(int microseconds) const
{
	return yTime(_ms + yint64(microseconds  / 1000));
}

inline yTime & yTime::operator*=(const yTime & other)
{
	_ms *= other._ms;
	return *this;
}
inline yTime & yTime::operator/=(const yTime & other)
{
	_ms /= other._ms;
	return *this;
}
inline yTime & yTime::operator+=(const yTime & other)
{
	_ms += other._ms;
	return *this;
}
inline yTime & yTime::operator-=(const yTime & other)
{
	_ms -= other._ms;
	return *this;
}

inline yTime operator*(const yTime & value1, const yTime & value2)
{
	return yTime(value1.milliseconds() * value2.milliseconds());
}
inline yTime operator/(const yTime & value1, const yTime & value2)
{
	return yTime(value1.milliseconds() / value2.milliseconds());
}
inline yTime operator+(const yTime & value1, const yTime & value2)
{
	return yTime(value1.milliseconds() + value2.milliseconds());
}
inline yTime operator-(const yTime & value1, const yTime & value2)
{
	return yTime(value1.milliseconds() - value2.milliseconds());
}