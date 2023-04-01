#pragma once
#include<iostream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"Window/AppWindow.h"
#include"Render/Shader.h"
#include"Render/OpenGL/VAO.h"
#include"Render/OpenGL/VBO.h"
#include"Render/OpenGL/EBO.h"

class CEngine
{
public:
	CEngine();
	~CEngine();

	void Draw();

	//Window
	AppWindow* GetWindow() { return this->appWindow; };
	bool WindowShouldClose() { return this->appWindow->WindowShouldClose(); };
	void CreateWindow(std::string windowName) { appWindow->CreateWindow(windowName); };

private:
	AppWindow* appWindow;
	Shader* shaderProgram;
	VAO* VAO1;
	VBO* VBO1;
	EBO* EBO1;
};

