#pragma once
#include<iostream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
	
#include "Types/CVector.h"
#include"Window/AppWindow.h"
#include"Render/Renderer.h"
#include"World.h"

class CEngine
{
public:
	~CEngine();

	void Draw();
	void Update();

	//Window
	AppWindow* GetWindow() { return this->appWindow; };
	bool WindowShouldClose() { return this->appWindow->WindowShouldClose(); };
	void CreateWindow(std::string windowName) { appWindow->CreateWindow(windowName, 800, 800); };

	void GetWindowSize(int& x, int& y);
	void SetWindowSize(int width, int height);
	Renderer* GetRenderer() { return this->renderer; };
	//Временная функция
	Camera* GetCamera() { return this->camera; };

	static CEngine* Get()
	{
		static CEngine engine;
		return &engine;
	};

private:
	CEngine();
private:
	AppWindow* appWindow;
	Camera* camera;
	Renderer* renderer;
	int windowWidth = 1600, windowHeight = 900;
};
