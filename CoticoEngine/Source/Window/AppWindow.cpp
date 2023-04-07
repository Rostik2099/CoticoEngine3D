#include "AppWindow.h"

AppWindow::AppWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

AppWindow::~AppWindow() 
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void AppWindow::CreateWindow(std::string windowName, int width, int height)
{
	window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
	}
}