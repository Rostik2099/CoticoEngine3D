#pragma once
#include<glad/glad.h>
#include<vector>

class EBO
{
public:
	EBO(std::vector<GLuint>& indices);

	void Bind();
	void UnBind();
	void Delete();

public:
	GLuint ID;
};