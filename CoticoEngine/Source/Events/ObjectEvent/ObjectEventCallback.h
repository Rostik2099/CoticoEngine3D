#pragma once
#include <vector>
#include "Types/SoftReference.h"

class IObjectEventCallback
{
public:
	virtual void Run(CObject* obj) = 0;
};

template<typename T>
class ObjectEventCallback : public IObjectEventCallback
{
public:
	void Run(CObject* obj) override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)(obj);
		}
	};

	ObjectEventCallback(T* object, void(T::* func)(CObject* obj))
	{
		this->listener = Ref(object);
		this->function = func;
	};

private:
	void(T::* function)(CObject* obj);
	Ref<T> listener;
};