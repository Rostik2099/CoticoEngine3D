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

	void Render(std::vector<std::shared_ptr<MeshComponent>> meshComps);
private:
	CEngine* engine;
};

