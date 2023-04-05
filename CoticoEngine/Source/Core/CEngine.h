#pragma once
#include<iostream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
	
#include"Window/AppWindow.h"
#include"Render/Renderer.h"
#include"World.h"

class CEngine
{
public:
	CEngine();
	~CEngine();

	void Draw();
	void Update();

	//Window
	AppWindow* GetWindow() { return this->appWindow; };
	bool WindowShouldClose() { return this->appWindow->WindowShouldClose(); };
	void CreateWindow(std::string windowName) { appWindow->CreateWindow(windowName, 800, 800); };

	Renderer* GetRenderer() { return this->renderer; };
	World* GetWorld() { return this->world; };
	//Временная функция
	Camera* GetCamera() { return this->camera; };
private:
	AppWindow* appWindow;
	Camera* camera;
	Renderer* renderer;
	World* world;
};
