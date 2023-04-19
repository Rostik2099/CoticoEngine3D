#include "Event.h"

Event::Event() {}

Event::~Event()
{
	for (auto callback : callbacks)
	{
		delete callback;
	}
}

void Event::Broadcast()
{
	for (auto callback : callbacks)
	{
		(*callback)();
	}
}
