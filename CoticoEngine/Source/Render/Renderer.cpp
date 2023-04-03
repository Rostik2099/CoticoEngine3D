#include "Renderer.h"
#include "Core/CEngine.h"

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	glViewport(0, 0, 800, 800);
	glEnable(GL_DEPTH_TEST);

	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
}

void Renderer::Render()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderProgram->Activate();

	for (auto mesh : meshComps)
	{
		mesh->Draw(*shaderProgram, *engine->GetCamera());
	}

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer()
{
	shaderProgram->Delete();
}
