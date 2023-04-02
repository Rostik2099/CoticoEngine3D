#include "CEngine.h"

GLuint uniID, texUni, texture;
int widthImg, heightImg, numColCh;
unsigned char* bytes;

GLfloat vertices[] = {
		-0.5f, -0.5f, 0.f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		0.5f, 0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 0.1f,	1.0f, 0.0f,
};

GLuint indices[] = {
	0, 2, 1,
	0, 3, 2,
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

	glViewport(0, 0, 800, 800);

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

	uniID = glGetUniformLocation(shaderProgram->ID, "scale");

	texture = new Texture("Content/Textures/unnamed.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	texture->texUnit(*shaderProgram, "tex0", 0);
	
}

void CEngine::Draw()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);
	shaderProgram->Activate();
	glUniform1f(uniID, 0.25f);
	texture->Bind();
	VAO1->Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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