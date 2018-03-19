#pragma once

#include <yCore/yCore.h>

struct yCORE_API yThreadFunction
{
	inline virtual ~yThreadFunction() { }
	inline void operator()() { run(); }
	inline virtual void run() = 0;
};

class yCORE_API yThread
{
	yDECL_NO_COPY(yThread)

public:
	enum Priority
	{
		IdlePriority,
		LowestPriority,
		LowPriority,
		NormalPriority,
		HighPriority,
		HighestPriority,
		TimeCriticalPriority,
		InheritPriority
	};

public:
	inline yThread();
	template<typename T>
	inline yThread(T functor);
	template<typename T, typename Arg>
	inline yThread(T functor, Arg argument);
	template<typename T, typename Obj>
	inline yThread(T(Obj::*function)(), Obj * object);
	inline virtual ~yThread();

	bool isRunning() const;
	bool isExited() const;
	bool isFinished() const;

	Priority priority() const;
	void setPriority(Priority priority);

	yuint stackSize() const;
	void setStackSize(yuint stackSize);

	void start(Priority priority = InheritPriority);
	void exit(int exitCode = 0);
	void terminate();
	void wait();

protected:
	virtual void exec() { }

private:
	void initPrivate();
	void deletePrivate();

private:
	class Private;
	Private * _priv;
	yThreadFunction * _func;
};

// yThread inline implementation
#include <yCore/inline/yThread.inl>