#pragma once
#include<iostream>
#include<string>
#include<GLFW/glfw3.h>

class AppWindow
{
public:
	AppWindow();
	~AppWindow();

	void CreateWindow(std::string windowName, int width, int height);
	bool WindowShouldClose() { return glfwWindowShouldClose(window); };
	GLFWwindow* GetWindow() { return this->window; };

private:
	GLFWwindow* window;
};

