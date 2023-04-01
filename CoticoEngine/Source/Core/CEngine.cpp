#include "CEngine.h"

GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,
};

GLuint indices[] = {
	0, 3, 5, 
	3, 2, 4,
	5, 4, 1,
};

CEngine::CEngine()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	appWindow = new AppWindow;
	appWindow->CreateWindow("Cool Window");
	glfwMakeContextCurrent(appWindow->GetWindow());

	gladLoadGL();

	glViewport(0, 0, 900, 600);

	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
	VAO1 = new VAO;
	VAO1->Bind();

	VBO1 = new VBO(vertices, sizeof(vertices));
	EBO1 = new EBO(indices, sizeof(indices));

	VAO1->LinkVBO(*VBO1, 0);
	VAO1->UnBind();
	VBO1->UnBind();
	EBO1->UnBind();
}

void CEngine::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram->Activate();
	VAO1->Bind();
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(appWindow->GetWindow());

	glfwPollEvents();
}

CEngine::~CEngine()
{
	VAO1->Delete();
	VBO1->Delete();
	EBO1->Delete();
	shaderProgram->Delete();
	delete appWindow;
	glfwTerminate();
}