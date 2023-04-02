#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

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

void Mesh::Draw(Shader& shader, Camera& camera)
{
	shader.Activate();
	VAO.Bind();

	unsigned int numDiffuse = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		std::string type = textures[i].type;
		num = std::to_string(numDiffuse++);
		textures[i].texUnit(shader, (type + num).c_str(), i);
		textures[i].Bind();
	}

	//glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.position.x, camera.position.y, camera.position.z);
	camera.Matrix(shader, "camMatrix");

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
