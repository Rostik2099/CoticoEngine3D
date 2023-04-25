#pragma once
#include<vector>
#include"ObjectEventCallback.h"

class CObject;
class ObjectEvent
{
public:
	ObjectEvent();
	~ObjectEvent();

	template<typename T>
	void AddListener(T* listener, void(T::* funct)(CObject* obj))
	{
		IObjectEventCallback* newCallback = new ObjectEventCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

	virtual void Broadcast(CObject* obj);
protected:
	std::vector<IObjectEventCallback*> callbacks;
};

