#include "InputEvent.h"

AxisEvent::AxisEvent()
{
}

void AxisEvent::Press()
{
	InputEvent::Press();
	for (auto callback : callbacks)
	{
		callback->Broadcast(AxisEvent::scale);
	}
}

void AxisEvent::Release()
{
	if (pressed)
	{
	}
	InputEvent::Release();
}

int AxisEvent::GetKey()
{
	return this->params.key;
}

ActionEvent::ActionEvent() {}

void ActionEvent::Press()
{
	if (!pressed)
	{
		for (auto callback : pressCallbacks)
		{
			callback->Broadcast();
		}
	}
	InputEvent::Press();
}

void ActionEvent::Release()
{
	if (pressed)
	{
		for (auto callback : releaseCallbacks)
		{
			callback->Broadcast();
		}
	}
	InputEvent::Release();
}

int ActionEvent::GetKey()
{
	return this->params.key;
}
