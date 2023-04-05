#include"MeshComponent.h"
#include<vector>

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

MeshComponent::MeshComponent()
{
	Texture textures[]
	{
		Texture("Content/Textures/unnamed.png", "diffuse", 0),
	};
	shaderProgram = new Shader("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");

	std::vector<Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector<GLuint> inds(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector<Texture> texs(textures, textures + sizeof(textures) / sizeof(Texture));
	this->mesh = new Mesh(verts, inds, texs);
}

MeshComponent::~MeshComponent()
{
	delete mesh;
	delete shaderProgram;
}

void MeshComponent::Draw(Camera& camera)
{
	mesh->Draw(*shaderProgram, camera);
}

void MeshComponent::SetShaders(const char* vertShader, const char* fragShader)
{
	if (!shaderProgram) delete shaderProgram;

	shaderProgram = new Shader(vertShader, fragShader);
}

void MeshComponent::SetTexture(const char* texturePath)
{
	Texture textures[]
	{
		Texture(texturePath, "diffuse", 0),
	};
	std::vector<Texture> texs(textures, textures + sizeof(textures) / sizeof(Texture));
	mesh->textures = texs;
}
