#pragma once
#include"Events/EventCallback.h"
#include"KeyMapping.h"

class IAxisCallback
{
public:
	virtual void Broadcast(float scale) = 0;
};

class IActionCallback
{
public:
	virtual void Broadcast() = 0;
};

template<typename T>
class AxisCallback : public IAxisCallback
{
public:
	void Broadcast(float scale) override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)(scale);
		}
	};

	AxisCallback(T* object, void(T::* func)(float scale))
	{
		this->listener = Ref(object);
		this->function = func;
	};

private:
	Ref<T> listener;
	void(T::* function)(float scale);
};

template<typename T>
class ActionCallback : public IActionCallback
{
public:
	void Broadcast () override
	{
		if (listener)
		{
			(listener.GetRaw()->*function)();
		}
	};

	ActionCallback(T* object, void(T::* func)())
	{
		this->listener = Ref(object);
		this->function = func;
	};

private:
	Ref<T> listener;
	void(T::* function)();
};