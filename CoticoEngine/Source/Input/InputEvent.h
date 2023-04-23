#pragma once
#include"Events/Event.h"
#include"InputCallback.h"
#include<string>
#include<vector>
#include<iostream>

struct AxisParams
{
	std::string name;
	int key = 0;
	float scale = 1.f;
};

struct ActionParams 
{
	std::string name;
	int key = 0;
};

class InputEvent
{
public:
	InputEvent() {};

	virtual void Press() { pressed = true; };
	virtual void Release()	{ pressed = false; };
	virtual int GetKey() { return 0; };
protected:
	bool pressed = false;
};

class AxisEvent : public InputEvent
{
public:
	AxisEvent();

	void Press() override;
	void Release() override;
	int GetKey() override;
	void SetParams(AxisParams params) { this->params = params; };
	AxisParams GetParams() { return this->params; };

	template<typename T>
	void AddListener(T* listener, void(T::* funct)(float scale))
	{
		IAxisCallback* newCallback = new AxisCallback(listener, funct);
		callbacks.push_back(newCallback);
	};

private:
	std::vector<IAxisCallback*> callbacks;
	AxisParams params;
	float scale = 0.f;
};

class ActionEvent : public InputEvent
{
public:
	ActionEvent();

	void Press() override;
	void Release() override;
	int GetKey() override;
	void SetParams(ActionParams params) { this->params = params; };

	template<typename T>
	void AddListener(T* listener, void(T::* funct)(), ActionType actionType)
	{
		if (actionType == IE_PRESS)
		{
			IActionCallback* newCallback = new ActionCallback(listener, funct);
			pressCallbacks.push_back(newCallback);
		}
		if (actionType == IE_RELEASE)
		{
			IActionCallback* newCallback = new ActionCallback(listener, funct);
			releaseCallbacks.push_back(newCallback);
		}
	};

	ActionParams GetParams() { return this->params; };
private:
	std::vector<IActionCallback*> pressCallbacks;
	std::vector<IActionCallback*> releaseCallbacks;
	ActionParams params;
};