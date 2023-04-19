#pragma once
#include <vector>
#include "EventCallback.h"

class Event
{
public:
	Event();
	~Event();

	template<typename T>
	void AddListener(T* listener, void(T::*funct)()) 
	{
		IEventCallback* newCallback = new EventCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

	void Broadcast();
private:
	std::vector<IEventCallback*> callbacks;
};

