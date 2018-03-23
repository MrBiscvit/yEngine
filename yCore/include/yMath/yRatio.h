#pragma once

#include <yMath/yMath.h>
#include <ratio>

// TODO: Finish implementation of yRatio<Num, Denom>

template<yint64 Num, yint64 Denom = 1>
class yCORE_API yRatio
{
public:
	typedef yRatio<1, 1000000000000000000> Atto;
	typedef yRatio<1, 1000000000000000> Femto;
	typedef yRatio<1, 1000000000000> Pico;
	typedef yRatio<1, 1000000000> Nano;
	typedef yRatio<1, 1000000> Micro;
	typedef yRatio<1, 1000> Milli;
	typedef yRatio<1, 100> Centi;
	typedef yRatio<1, 10> Deci;
	typedef yRatio<10, 1> Deca;
	typedef yRatio<100, 1> Hecto;
	typedef yRatio<1000, 1> Kilo;
	typedef yRatio<1000000, 1> Mega;
	typedef yRatio<1000000000, 1> Giga;
	typedef yRatio<1000000000000, 1> Tera;
	typedef yRatio<1000000000000000, 1> Peta;
	typedef yRatio<1000000000000000000, 1> Exa;
};