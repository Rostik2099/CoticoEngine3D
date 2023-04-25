#include "CEngine.h"

void WindowResizeCallback(GLFWwindow* window, int width, int height);

double prevTime = 0.0;
double crntTime = 0.0;
double timeDiff;
unsigned int counter = 0;

CEngine::CEngine()
{
	appWindow = new AppWindow;
	appWindow->CreateWindow("Cotico Engine", windowWidth, windowHeight);
	glfwSetWindowSizeCallback(appWindow->GetGLWindow(), WindowResizeCallback);
	glfwMakeContextCurrent(appWindow->GetGLWindow());
	gladLoadGL();

	inputManager = InputManager::Get();
	renderer = new Renderer(this);
	World::Get()->SetEngine(this);
	camera = new Camera(windowWidth, windowHeight, glm::vec3(0.0f, 0.0f, 2.0f));
}

void CEngine::Draw()
{
	renderer->Render();
}

void CEngine::Update()
{
	World::Get()->Update();
	inputManager->UpdateInputs();
	camera->Inputs(appWindow->GetGLWindow());
	camera->UpdateMatrix(75.0f, 0.1f, 100.f, windowWidth, windowHeight);

	crntTime = glfwGetTime();
	timeDiff = crntTime - prevTime;
	counter++;
	if (timeDiff >= 1.0 / 30.0)
	{
		std::string FPS = std::to_string((1.0 / timeDiff) * counter).substr(0, 4) + " fps";
		std::string ms = std::to_string((timeDiff/counter) * 1000).substr(0, 4) + " ms";
		std::string newTitle = "CoticoEngine " + FPS + " / " + ms;
		glfwSetWindowTitle(appWindow->GetGLWindow(), newTitle.c_str());
		prevTime = crntTime;
		counter = 0;
	}

	glfwPollEvents();
}

void CEngine::GetWindowSize(int& x, int& y)
{
	x = windowWidth;
	y = windowHeight;
}

void CEngine::SetWindowSize(int width, int height)
{
	this->windowWidth = width;
	this->windowHeight = height;
}

void WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	if (width != 0 && height != 0)
	{
		CEngine::Get()->Draw();
		CEngine::Get()->SetWindowSize(width, height);
		CEngine::Get()->GetRenderer()->GetFB()->RegenerateBuffer();
	}
}

CEngine::~CEngine()
{
	delete appWindow;
	delete renderer;
}