#pragma once

#include <yCore/yCore.h>
#include <yCore/yTime.h>

class yCORE_API yChrono
{
public:
	inline yChrono();

	inline yTime elapsed() const;
	inline yTime restart();

	static yTime currentTime();

private:
	yTime _last;
};

// yChrono inline implementation
#include <yCore/inline/yChrono.inl>