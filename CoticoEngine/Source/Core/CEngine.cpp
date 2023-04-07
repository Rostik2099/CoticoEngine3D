#include "CEngine.h"

void WindowResizeCallback(GLFWwindow* window, int width, int height);

CEngine::CEngine()
{
	appWindow = new AppWindow;
	appWindow->CreateWindow("Cool Window", windowWidth, windowHeight);
	glfwSetWindowSizeCallback(appWindow->GetGLWindow(), WindowResizeCallback);
	glfwMakeContextCurrent(appWindow->GetGLWindow());
	gladLoadGL();

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
	camera->Inputs(appWindow->GetGLWindow());
	camera->UpdateMatrix(45.0f, 0.1f, 100.f, windowWidth, windowHeight);

	glfwPollEvents();
}

CVector2D CEngine::GetWindowSize()
{
	return CVector2D(windowWidth, windowHeight);
}

void CEngine::SetWindowSize(int width, int height)
{
	this->windowWidth = width;
	this->windowHeight = height;
}

void WindowResizeCallback(GLFWwindow* window, int width, int height)
{
	CEngine::Get()->Draw();
	CEngine::Get()->SetWindowSize(width, height);
	CEngine::Get()->GetRenderer()->GetFB()->RegenerateBuffer();
}

CEngine::~CEngine()
{
	delete appWindow;
	delete renderer;
}