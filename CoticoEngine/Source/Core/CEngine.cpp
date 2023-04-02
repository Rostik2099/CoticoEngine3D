#include "CEngine.h"

int scrWidth = 800, scrHeight = 800;

GLfloat vertices[] = {
		-0.5f, 0.0f, 0.5f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f, 0.0f,	5.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
		0.5f, 0.0f, 0.5f,		1.0f, 1.0f, 0.1f,	5.0f, 0.0f,
		0.0f, 0.8f, 0.0f,		1.0f, 1.0f, 0.1f,	2.5f, 5.0f,
};

GLuint indices[] = {
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4,
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

	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
	VAO1 = new VAO;
	VAO1->Bind();

	VBO1 = new VBO(vertices, sizeof(vertices));
	EBO1 = new EBO(indices, sizeof(indices));

	VAO1->LinkAttrib(*VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*) 0);
	VAO1->LinkAttrib(*VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1->LinkAttrib(*VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1->UnBind();
	VBO1->UnBind();
	EBO1->UnBind();

	texture = new Texture("Content/Textures/unnamed.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	texture->texUnit(*shaderProgram, "tex0", 0);
	
	glEnable(GL_DEPTH_TEST);

	camera = new Camera(scrWidth, scrHeight, glm::vec3(0.0f, 0.0f, 2.0f));
}

void CEngine::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderProgram->Activate();

	camera->Inputs(appWindow->GetWindow());
	camera->Matrix(45.0f, 0.1f, 100.f, *shaderProgram, "camMatrix");

	texture->Bind();
	VAO1->Bind();
	glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(appWindow->GetWindow());
	glfwPollEvents();
}

CEngine::~CEngine()
{
	VAO1->Delete();
	VBO1->Delete();
	EBO1->Delete();
	texture->Delete();
	shaderProgram->Delete();
	delete appWindow;
	glfwTerminate();
}