#pragma once

#include<vector>

#include<glad/glad.h>
#include<glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texUV;
};

class VBO
{
public:
	VBO(std::vector<Vertex>& vertices);

	void Bind();
	void UnBind();
	void Delete();

public:
	GLuint ID;
};

