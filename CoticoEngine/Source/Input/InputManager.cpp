#include "InputManager.h"
#include"Core/CEngine.h"
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<glad/glad.h>

InputManager::~InputManager()
{
	for (auto [name, event] : inputEvents)
	{
		delete event;
	}
	inputEvents.clear();
}

void InputManager::UpdateInputs()
{
	for (auto [name, event] : inputEvents)
	{
		if (glfwGetKey(CEngine::Get()->GetWindow()->GetGLWindow(), event->GetKey()) == GLFW_PRESS)
		{
			event->Press();
		}
		if (glfwGetKey(CEngine::Get()->GetWindow()->GetGLWindow(), event->GetKey()) == GLFW_RELEASE)
		{
			event->Release();
		}
	}
}

void InputManager::LoadEditorInputs()
{
	std::ifstream file;
	file.open("Config/EditorInputs.ini");
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			if (line != "")
			{
				ReadLine(line);
			}
		}
	}
	else std::cout << "Failed to load editor inputs" << std::endl;
	file.close();
}

void InputManager::AddAxisEvent(AxisParams params)
{
	AxisEvent* newEvent = new AxisEvent;
	newEvent->SetParams(params);
	inputEvents[params.name] = newEvent;
}

void InputManager::AddActionEvent(ActionParams params)
{
	ActionEvent* newEvent = new ActionEvent;
	newEvent->SetParams(params);
	inputEvents[params.name] = newEvent;
}

void InputManager::ReadLine(std::string line)
{
	int com, prevCom = line.find_first_of("(");
	std::string inputType = line.substr(0, prevCom);
	int equal, prevEqual = 0;
	bool end = false;
	std::map<std::string, std::string> params;

	for (int i = 0; i < line.length(); i++)
	{
		equal = line.find_first_of("=", prevEqual + 1);
		com = line.find_first_of(",", equal);
		if (com == -1)
		{
			com = line.length() - 1;
			end = true;
		}
		std::string paramName = line.substr(prevCom + 1, equal - prevCom - 1);
		std::string param = line.substr(equal + 1, com - equal - 1);
		params[paramName] = param;
		prevEqual = equal;
		prevCom = com;
		if (end) break;
	}

	if (inputType == "Axis")
	{
		AxisParams parameters;

		parameters.name = params["Name"];
		parameters.key = keyMapping[params["Key"]];
		parameters.scale = std::stof(params["Scale"]);

		AddAxisEvent(parameters);
	}
	if (inputType == "Action")
	{
		ActionParams parameters;

		parameters.name = params["Name"];
		parameters.key = keyMapping[params["Key"]];

		AddActionEvent(parameters);
	}
}

InputManager::InputManager()
{
	LoadEditorInputs();
}
