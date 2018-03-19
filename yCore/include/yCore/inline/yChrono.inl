inline yChrono::yChrono() :
	_last(currentTime())
{
}

inline yTime yChrono::elapsed() const
{
	return yTime(currentTime() - _last);
}
inline yTime yChrono::restart()
{
	yTime current = currentTime();
	yTime elapsed = current - _last;
	_last = current;
	return elapsed;
}