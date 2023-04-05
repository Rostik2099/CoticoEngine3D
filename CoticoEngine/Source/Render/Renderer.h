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
private:
	CEngine* engine;
};

