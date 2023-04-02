#include "AppWindow.h"

AppWindow::AppWindow() {}

AppWindow::~AppWindow() 
{
	glfwDestroyWindow(window);
}

void AppWindow::CreateWindow(std::string windowName, int width, int height)
{
	window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
	}
}
