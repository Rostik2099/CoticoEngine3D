#include "ObjectEvent.h"

ObjectEvent::ObjectEvent()
{
}

ObjectEvent::~ObjectEvent()
{
	for (auto callback : callbacks)
	{
		delete callback;
	}
}

void ObjectEvent::Broadcast(CObject* obj)
{
	for (auto callback : callbacks)
	{
		callback->Run(obj);
	}
}
