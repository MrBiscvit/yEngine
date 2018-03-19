template<typename T>
struct yCORE_API yThreadFunctor : public yThreadFunction
{
	inline yThreadFunctor(T functor) : _func(functor) { }
	inline virtual void run() { functor(); }
	T _func;
};
template<typename T, typename Arg>
struct yCORE_API yThreadFunctorWithArgument : public yThreadFunction
{
	inline yThreadFunctorWithArgument(T functor, Arg argument) : _func(functor), _arg(argument) { }
	inline virtual void run() { functor(_arg); }
	T _func;
	Arg _arg;
};
template<typename T, typename Obj>
struct yCORE_API yThreadMemberFunction : public yThreadFunction
{
	inline yThreadMemberFunction(T(Obj::*function)(), Obj * object) : _func(function), _obj(object) { }
	inline virtual void run() { (_obj->*_func)(); }
	T(Obj::*_func)();
	Obj * _obj;
};

inline yThread::yThread() :
	_priv(nullptr), _func(new yThreadMemberFunction<void, yThread>((&yThread::exec), this))
{
	initPrivate();
}
template<typename T>
inline yThread::yThread(T functor) :
	_priv(nullptr), _func(new yThreadFunctor<T>(functor))
{
	initPrivate();
}
template<typename T, typename Arg>
inline yThread::yThread(T functor, Arg argument) :
	_priv(nullptr), _func(new yThreadFunctorWithArgument<T, Arg>(functor, argument))
{
	initPrivate();
}
template<typename T, typename Obj>
inline yThread::yThread(T(Obj::* function)(), Obj * object) :
	_priv(nullptr), _func(new yThreadMemberFunction<T, Obj>(function, object))
{
	initPrivate();
}
inline yThread::~yThread()
{
	wait();
	delete _func;
	deletePrivate();
}
