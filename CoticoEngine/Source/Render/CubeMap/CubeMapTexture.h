#pragma once
#include"Render/Texture.h"
#include<vector>

class CubeMapTexture : public Texture
{
public:
	CubeMapTexture(std::vector<const char*> textures, const char* texType, GLenum slot, GLenum format, GLenum pixelType);

	//void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void UnBind();
	void Delete();
};