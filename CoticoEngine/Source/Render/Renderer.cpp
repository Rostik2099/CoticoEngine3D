#include "Renderer.h"
#include "Core/CEngine.h"

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	glViewport(0, 0, 800, 800);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::Render()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto mesh : World::Get()->GetMeshComps())
	{
		mesh->Draw(*engine->GetCamera());
	}

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer() {}
