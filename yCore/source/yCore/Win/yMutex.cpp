#include <yCore/yMutex.h>
#if defined(yOS_WINDOWS)
#include <Windows.h>

yMutex::yMutex()
{
	InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(_handle));
}
yMutex::~yMutex()
{
	DeleteCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(_handle));
}

void yMutex::lock()
{
	EnterCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(_handle));
}
void yMutex::unlock()
{
	LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(_handle));
}

#endif