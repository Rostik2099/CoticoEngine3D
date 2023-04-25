#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, Texture* texture)
{
	this->vertices = vertices;
	this->indices = indices;
	this->texture = texture;

	VAO.Bind();
	VBO VBO(vertices);
	EBO EBO(indices);

	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO.LinkAttrib(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	VAO.UnBind();
	VBO.UnBind();
	EBO.UnBind();
}

Mesh::~Mesh()
{
	texture->Delete();
	delete texture;
}

void Mesh::Draw(Shader& shader, Camera& camera, glm::mat4 modelMatrix)
{
	shader.Activate(); 
	VAO.Bind();
	
	unsigned int numDiffuse = 0;
	std::string num;
	std::string type = texture->type;
	num = std::to_string(numDiffuse++);
	texture->texUnit(shader, (type + num).c_str(), 0);
	texture->Bind();
	
	shader.SetMatrix("modelMatrix", camera.GetMatrix() * modelMatrix);
	
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	VAO.UnBind();
	texture->UnBind();
}

void Mesh::SetTexture(Texture* texture)
{
	this->texture->Delete();
	this->texture = texture;
}
