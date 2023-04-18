#pragma once
#include"Render/Texture.h"
#include<vector>

class CubeMapTexture : public Texture
{
public:
	CubeMapTexture(std::vector<const char*> textures, const char* texType, GLenum slot);

	//void texUnit(Shader& shader, const char* uniform, GLuint unit);
	virtual void Bind() override;
	virtual void UnBind() override;
	virtual void Delete() override;
};