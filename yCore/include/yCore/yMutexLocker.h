#pragma once

#include <yCore/yCore.h>
#include <yCore/yMutex.h>

class yCORE_API yMutexLocker
{
	yDECL_NO_COPY(yMutexLocker)

public:
	inline yMutexLocker(yMutex & mutex) : _mutex(mutex) { relock(); }
	inline ~yMutexLocker() { unlock(); }

	inline yMutex & mutex() const { return _mutex; }

	inline void relock() { _mutex.lock(); }
	inline void lock() { _mutex.lock(); }
	inline void unlock() { _mutex.unlock(); }

private:
	yMutex & _mutex;
};