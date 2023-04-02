#include "CEngine.h"

int scrWidth = 800, scrHeight = 800;

Vertex vertices[] =
{ //               COORDINATES           /            COLORS              TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)}
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3
};

CEngine::CEngine()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	appWindow = new AppWindow;
	appWindow->CreateWindow("Cool Window", scrWidth, scrHeight);
	glfwMakeContextCurrent(appWindow->GetWindow());

	gladLoadGL();

	glViewport(0, 0, scrWidth, scrHeight);

	Texture textures[]
	{
		Texture("Content/Textures/unnamed.png", "diffuse", 0, GL_RGBA, GL_UNSIGNED_BYTE),
	};

	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> inds(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> texs(textures, textures + sizeof(textures) / sizeof(Texture));
	floor = new Mesh(verts, inds, texs);
	
	glEnable(GL_DEPTH_TEST);
	camera = new Camera(scrWidth, scrHeight, glm::vec3(0.0f, 0.0f, 2.0f));
}

void CEngine::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderProgram->Activate();

	camera->Inputs(appWindow->GetWindow());
	camera->UpdateMatrix(45.0f, 0.1f, 100.f);

	floor->Draw(*shaderProgram, *camera);

	glfwSwapBuffers(appWindow->GetWindow());
	glfwPollEvents();
}

CEngine::~CEngine()
{
	shaderProgram->Delete();
	delete appWindow;
	glfwTerminate();
}