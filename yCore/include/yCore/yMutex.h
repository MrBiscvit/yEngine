#pragma once

#include <yCore/yCore.h>

class yCORE_API yMutex
{
	yDECL_NO_COPY(yMutex)

public:
	yMutex();
	~yMutex();

	void lock();
	void unlock();

private:
	yHandle _handle;
};