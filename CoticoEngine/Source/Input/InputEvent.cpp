#include "InputEvent.h"

AxisEvent::AxisEvent()
{
}

void AxisEvent::Press()
{
	InputEvent::Press();
	this->scale = this->GetParams().scale;
	for (auto callback : callbacks)
	{
		callback->Broadcast(AxisEvent::scale);
	}
}

void AxisEvent::Release()
{
	if (pressed)
	{
		this->scale = 0;
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
