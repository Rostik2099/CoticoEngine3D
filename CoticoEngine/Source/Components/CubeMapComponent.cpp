#include"CubeMapComponent.h"
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
	skyboxShader = new Shader("Shaders/skybox_vert.glsl", "Shaders/skybox_frag.glsl");

	Texture textures[]
	{
		CubeMapTexture(
			{
				"Content/Textures/unnamed.png",
				"Content/Textures/unnamed.png",
				"Content/Textures/unnamed.png",
				"Content/Textures/unnamed.png",
				"Content/Textures/unnamed.png",
				"Content/Textures/unnamed.png",

			}, "skybox", 0, GL_RGB, GL_UNSIGNED_BYTE),
	};

	std::vector<Vertex> verts(Cubevertices, Cubevertices + sizeof(Cubevertices) / sizeof(Vertex));
	std::vector<GLuint> inds(Cubeindices, Cubeindices + sizeof(Cubeindices) / sizeof(GLuint));
	std::vector<Texture> texs(textures, textures + sizeof(textures) / sizeof(Texture));
	this->mesh = new Mesh(verts, inds, texs);
}

CubeMapComponent::~CubeMapComponent()
{
	delete mesh;
}

void CubeMapComponent::Draw(Shader& shader, Camera& camera)
{
	glDepthFunc(GL_LEQUAL);
	skyboxShader->Activate();

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);
	view = glm::mat4(glm::mat3(glm::lookAt(camera.position, camera.position + camera.orientation, camera.up)));
	projection = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	mesh->Draw(*skyboxShader, camera);

	glDepthFunc(GL_LESS);
}
