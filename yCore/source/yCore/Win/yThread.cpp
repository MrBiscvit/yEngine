#include <yCore/yThread.h>
#if defined(yOS_WINDOWS)
#include <Windows.h>
#include <process.h>

class yThread::Private
{
public:
	bool _isRunning;
	bool _isExited;
	bool _isFinished;
	Priority _prio;
	yuint _stackSize;
	HANDLE _handle;
	yuint _id;

	static yuint __stdcall entryPoint(void * data)
	{
		yThread * thread = reinterpret_cast<yThread*>(data);
		yASSERT(thread);

		thread->_func->run();

		_endthreadex(0);
		thread->_priv->_isRunning = false;
		thread->_priv->_isExited = false;
		thread->_priv->_isFinished = true;
		return 0;
	}
};

bool yThread::isRunning() const
{
	return _priv->_isRunning;
}
bool yThread::isExited() const
{
	return _priv->_isExited;
}
bool yThread::isFinished() const
{
	return _priv->_isFinished;
}

yThread::Priority yThread::priority() const
{
	return _priv->_prio;
}
void yThread::setPriority(yThread::Priority priority)
{
	_priv->_prio = priority;
	if (_priv->_isRunning) {
		switch (priority) {
		case yThread::IdlePriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_IDLE);
		case yThread::LowestPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_LOWEST);
		case yThread::LowPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_BELOW_NORMAL);
		case yThread::NormalPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_NORMAL);
		case yThread::HighPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_ABOVE_NORMAL);
		case yThread::HighestPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_HIGHEST);
		case yThread::TimeCriticalPriority:
			SetThreadPriority(_priv->_handle, THREAD_PRIORITY_TIME_CRITICAL);
		case yThread::InheritPriority:
		default:
			SetThreadPriority(_priv->_handle, GetThreadPriority(GetCurrentThread()));
		}
	}
}

yuint yThread::stackSize() const
{
	return _priv->_stackSize;
}
void yThread::setStackSize(yuint stackSize)
{
	_priv->_stackSize = stackSize;
}

void yThread::start(yThread::Priority priority)
{
	_priv->_handle = reinterpret_cast<HANDLE>(_beginthreadex(
		NULL, 
		0, 
		&Private::entryPoint,
		this,
		0, 
		&_priv->_id));

	setPriority(priority);

	_priv->_isRunning = true;
	_priv->_isExited = false;
	_priv->_isFinished = false;
}
void yThread::exit(int exitCode)
{
	if (_priv->_handle) {
		TerminateThread(_priv->_handle, exitCode);
		_priv->_isRunning = false;
		_priv->_isExited = true;
		_priv->_isFinished = true;
	}
}
void yThread::terminate()
{
	if (_priv->_handle) {
		TerminateThread(_priv->_handle, 0);
		_priv->_isRunning = false;
		_priv->_isExited = true;
		_priv->_isFinished = true;
	}
}
void yThread::wait()
{
	if (_priv->_handle) {
		yASSERT(_priv->_id != GetCurrentThreadId());
		WaitForSingleObject(_priv->_handle, INFINITE);

		CloseHandle(_priv->_handle);

		_priv->_isRunning = false;
		_priv->_isExited = false;
		_priv->_isFinished = true;
	}
}

void yThread::initPrivate()
{
	_priv = new Private;
}
void yThread::deletePrivate()
{
	delete _priv;
}

#endif
