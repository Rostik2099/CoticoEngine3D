#pragma once

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"Shader.h"

class Texture
{
public:
	Texture() {};
	Texture(const char* imagePath, const char* texType, GLenum slot);

	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	virtual void Bind();
	virtual void UnBind();
	virtual void Delete();
	
public:
	GLuint ID;
	const char* type;
};