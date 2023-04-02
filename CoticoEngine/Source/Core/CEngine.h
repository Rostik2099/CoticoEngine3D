#pragma once
#include<iostream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
	
#include"Window/AppWindow.h"
#include"Render/Shader.h"
#include"Render/OpenGL/VAO.h"
#include"Render/OpenGL/VBO.h"
#include"Render/OpenGL/EBO.h"
#include"Render/Texture.h"
#include"Camera.h"

class CEngine
{
public:
	CEngine();
	~CEngine();

	void Draw();

	//Window
	AppWindow* GetWindow() { return this->appWindow; };
	bool WindowShouldClose() { return this->appWindow->WindowShouldClose(); };
	void CreateWindow(std::string windowName) { appWindow->CreateWindow(windowName, 800, 800); };

private:
	AppWindow* appWindow;
	Shader* shaderProgram;
	VAO* VAO1;
	VBO* VBO1;
	EBO* EBO1;
	Texture* texture;
	Camera* camera;
};

