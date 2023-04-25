#pragma once
#include"KeyMapping.h"
#include"InputEvent.h"
#include<unordered_map>

class InputManager
{
public:
	static InputManager* Get() 
	{
		static InputManager input;
		return &input;
	};

	~InputManager();
	void UpdateInputs();

	template<typename T>
	void BindAxis(std::string actionKey, T* listener, void(T::*function)(float scale)) 
	{
		int contains = inputEvents.count(actionKey);
		if (contains > 0)
		{
			AxisEvent* event = dynamic_cast<AxisEvent*>(inputEvents[actionKey]);
			event->AddListener(listener, function);
		}
		else std::cout << "Failed to bind action. Key " << actionKey << " didn't found" << std::endl;
	};

	template<typename T>
	void BindAction(std::string actionKey, ActionType actionType, T* listener, void(T::* function)())
	{
		int contains = inputEvents.count(actionKey);
		if (contains > 0)
		{
			ActionEvent* event = dynamic_cast<ActionEvent*>(inputEvents[actionKey]);
			event->AddListener(listener, function, actionType);
		}
		else std::cout << "Failed to bind action. Key " << actionKey << " didn't found" << std::endl;
	};

private:
	void LoadEditorInputs();
	void AddAxisEvent(AxisParams params);
	void AddActionEvent(ActionParams params);
	void ReadLine(std::string line);

private:
	InputManager();
	std::unordered_map<std::string, InputEvent*> inputEvents;
	KeyMapping keyMap;
};

