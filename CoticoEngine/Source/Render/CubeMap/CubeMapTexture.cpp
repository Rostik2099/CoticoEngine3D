#include "CubeMapTexture.h"
#include<iostream>

CubeMapTexture::CubeMapTexture(std::vector<const char*> textures, const char* texType, GLenum slot) 
{
	type = texType;
	stbi_set_flip_vertically_on_load(false);
	 
	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_CUBE_MAP, ID);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	for (int i = 0; i < 6; i++)
	{
		int widthImg, heightImg, numColCh;
		unsigned char* bytes = stbi_load(textures[i], &widthImg, &heightImg, &numColCh, 0);
		if (bytes)
		{
			if (numColCh == 4)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
			}
			if (numColCh == 3)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
			}
		}
		else std::cout << "Failde to load texture: " << textures[i] << std::endl;
		stbi_image_free(bytes);
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

//void CubeMapTexture::texUnit(Shader& shader, const char* uniform, GLuint unit)
//{
//	GLuint texUnit = glGetUniformLocation(shader.ID, uniform);
//	shader.Activate();
//	glUniform1i(texUnit, unit);
//}

void CubeMapTexture::Bind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, ID);
}

void CubeMapTexture::UnBind()
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void CubeMapTexture::Delete()
{
	glDeleteTextures(1, &ID);
}