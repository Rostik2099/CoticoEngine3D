#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<memory>
#include"Components/MeshComponent.h"

#include"Mesh.h"

class CEngine;
class Renderer
{
public:
	Renderer(CEngine* engine);
	~Renderer();

	void Render();
	void AddMeshComp(std::shared_ptr<MeshComponent> mesh) { meshComps.push_back(mesh); };
private:
	CEngine* engine;
	std::vector<std::shared_ptr<MeshComponent>> meshComps;

	Shader* shaderProgram;
	Mesh* floor;
};

