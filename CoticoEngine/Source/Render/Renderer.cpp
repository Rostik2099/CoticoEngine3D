#include "Renderer.h"
#include "Core/CEngine.h"

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	glViewport(0, 0, 800, 800);
	glEnable(GL_DEPTH_TEST);

	FB = new FrameBuffer;
	EditorUIManager::GetUIManager()->Init(engine->GetWindow()->GetGLWindow());
}

void Renderer::Render()
{
	//glBindFramebuffer(GL_FRAMEBUFFER, FB->FBID);
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto mesh : World::Get()->GetMeshComps())
	{
		mesh->Draw(*engine->GetCamera());
	}

	//glBindFramebuffer(GL_FRAMEBUFFER, 0);
	EditorUIManager::GetUIManager()->BeginRender();
	EditorUIManager::GetUIManager()->Render();
	EditorUIManager::GetUIManager()->EndRender();

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer() 
{
	
}
