#include "Renderer.h"
#include "Core/CEngine.h"

//Vertex vertices[] =
//{ //               COORDINATES           /            COLORS              TEXTURE COORDINATES    //
//	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)}
//};
//
//// Indices for vertices order
//GLuint indices[] =
//{
//	0, 1, 2,
//	0, 2, 3
//};

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	glViewport(0, 0, 800, 800);
	glEnable(GL_DEPTH_TEST);

	//Texture textures[]
	//{
	//	Texture("Content/Textures/unnamed.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	//};
	//
	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
	//std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	//std::vector<GLuint> inds(indices, indices + sizeof(indices) / sizeof(GLuint));
	//std::vector<Texture> texs(textures, textures + sizeof(textures) / sizeof(Texture));
	//floor = new Mesh(verts, inds, texs);
}

void Renderer::Render()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderProgram->Activate();

	for (auto mesh : meshComps)
	{
		mesh->GetMesh()->Draw(*shaderProgram, *engine->GetCamera());
	}
	//floor->Draw(*shaderProgram, *engine->GetCamera());

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer()
{
	shaderProgram->Delete();
}
