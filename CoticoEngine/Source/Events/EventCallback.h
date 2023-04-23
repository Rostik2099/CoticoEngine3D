#pragma once
#include <vector>
#include "Types/SoftReference.h"

class IEventCallback
{
public:
	virtual void Run() = 0;
};

template<typename T>
class EventCallback : public IEventCallback
{
public:
	void Run() override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)();
		}
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