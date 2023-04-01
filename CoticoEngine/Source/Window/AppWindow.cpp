#include "AppWindow.h"

AppWindow::AppWindow() {}

AppWindow::~AppWindow() 
{
	glfwDestroyWindow(window);
}

void AppWindow::CreateWindow(std::string windowName)
{
	window = glfwCreateWindow(900, 600, windowName.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
	}
}
