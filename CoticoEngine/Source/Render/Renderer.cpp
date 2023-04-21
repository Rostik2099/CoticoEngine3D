#include "Renderer.h"
#include "Core/CEngine.h"

void FramebufferCallback(GLFWwindow* window, int width, int height);

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	int windowX, windowY;
	engine->GetWindowSize(windowX, windowY);
	glViewport(0, 0, windowX, windowY);
	glEnable(GL_DEPTH_TEST);

	EditorUIManager::GetUIManager()->Init(engine->GetWindow()->GetGLWindow());
	glfwSetFramebufferSizeCallback(engine->GetWindow()->GetGLWindow(), FramebufferCallback);

	FB = new FrameBuffer(engine);
}

void Renderer::Render()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FB->FBID);
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto [id, mesh] : World::Get()->GetMeshComps())
	{
		mesh->Draw(*engine->GetCamera());
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	EditorUIManager::GetUIManager()->BeginRender();
	EditorUIManager::GetUIManager()->Render();
	EditorUIManager::GetUIManager()->EndRender();

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer() 
{
	
}

void FramebufferCallback(GLFWwindow* window, int width, int height)
{
	if (width != 0 && height != 0)
	{
		glViewport(0, 0, width, height);
	}
}