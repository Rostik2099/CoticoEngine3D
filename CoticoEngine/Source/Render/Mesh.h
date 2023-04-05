#pragma once

#include<string>
#include<vector>

#include"OpenGL/VAO.h"
#include"OpenGL/VBO.h"
#include"OpenGL/EBO.h"
#include"Core/Camera.h"
#include"Texture.h"

class Mesh
{
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);
	~Mesh();

	void Draw(Shader& shader, Camera& camera);

public:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	VAO VAO;
};

