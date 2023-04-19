#include"CubeMapComponent.h"
#include"Core/CEngine.h"
#include"Render/CubeMap/CubeMapTexture.h"
#include<vector>

Vertex Cubevertices[] =
{ //               COORDINATES           /            COLORS              TEXTURE COORDINATES    //
	Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(1.0f, -1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	 glm::vec2(0.0f, 1.0f)},
	Vertex{glm::vec3(1.0f, -1.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-1.0f, -1.0f,  -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(1.0f, 1.0f,  -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(-1.0f, 1.0f,  -1.0f), glm::vec3(0.0f, 1.0f, 0.0f),	glm::vec2(1.0f, 0.0f)},
};

// Indices for vertices order
GLuint Cubeindices[] =
{
	1, 2, 6,
	6, 5, 1,
	0, 4, 7,
	7, 3, 0,
	4, 5, 6,
	6, 7, 4,
	0, 3, 2,
	2, 1, 0,
	0, 1, 5,
	5, 4, 0,
	3, 7, 6,
	6, 2, 3,
};

CubeMapComponent::CubeMapComponent()
{
	CubeMapTexture* texture = new CubeMapTexture(
			{
				"Content/Textures/Skybox/right.png",
				"Content/Textures/Skybox/left.png",
				"Content/Textures/Skybox/top.png",
				"Content/Textures/Skybox/bottom.png",
				"Content/Textures/Skybox/front.png",
				"Content/Textures/Skybox/back.png",
			}, "skybox", 0
		);

	shaderProgram = new Shader("Shaders/skybox_vert.glsl", "Shaders/skybox_frag.glsl");
	shaderProgram->Activate();

	std::vector<Vertex> verts(Cubevertices, Cubevertices + sizeof(Cubevertices) / sizeof(Vertex));
	std::vector<GLuint> inds(Cubeindices, Cubeindices + sizeof(Cubeindices) / sizeof(GLuint));
	this->mesh = new Mesh(verts, inds, texture);
}

void CubeMapComponent::Draw(Camera& camera)
{
	glDepthFunc(GL_LEQUAL);
	shaderProgram->Activate();

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	view = glm::mat4(glm::mat3(glm::lookAt(camera.position, camera.position + camera.orientation, camera.up)));
	int windowX, windowY;
	CEngine::Get()->GetWindowSize(windowX, windowY);
	projection = glm::perspective(glm::radians(75.0f), ((float)windowX / (float)windowY), 0.1f, 100.f);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	mesh->Draw(*shaderProgram, camera);

	glDepthFunc(GL_LESS);
}
