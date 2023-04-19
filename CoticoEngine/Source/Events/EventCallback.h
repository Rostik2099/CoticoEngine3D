#pragma once
#include <vector>
#include "Types/SoftReference.h"

class IEventCallback 
{
public:
	virtual bool operator() () = 0;
};

template<typename T>
class EventCallback : public IEventCallback
{
public:
	bool operator() () override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)();
			return true;
		}
		return false;
	};

	EventCallback(T* object, void(T::*func)()) 
	{
		this->listener = Ref(object);
		this->function = func;
	};

private:
	void(T::*function)();
	Ref<T> listener;
};