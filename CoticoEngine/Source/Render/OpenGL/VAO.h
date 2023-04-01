#pragma once
#include<glad/glad.h>
#include"VBO.h"

class VAO
{
public:
	VAO();

	void LinkVBO(VBO& VBO, GLuint layout);
	void Bind();
	void UnBind();
	void Delete();

public:
	GLuint ID;
};

