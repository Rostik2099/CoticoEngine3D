#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>
#include<memory>
#include"Components/MeshComponent.h"

#include"EditorUI/EditorUIManager.h"
#include"Mesh.h"
#include"Render/FrameBuffers/FrameBuffer.h"

class CEngine;
class Renderer
{
public:
	Renderer(CEngine* engine);
	~Renderer();

	void Render();
	FrameBuffer* GetFB() { return this->FB; };

private:
	CEngine* engine;
	FrameBuffer* FB;
};

