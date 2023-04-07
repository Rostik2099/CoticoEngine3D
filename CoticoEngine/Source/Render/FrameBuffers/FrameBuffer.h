#pragma once

#include<glad/glad.h>
#include<ImGUI/imgui.h>

class CEngine;
class FrameBuffer
{
public:
	FrameBuffer(CEngine* engine);
	~FrameBuffer();

	void GenerateBuffer();
	void RegenerateBuffer();
	void Delete();

public:
	GLuint FBID;
	GLuint RBID;
	GLuint TexID;

private:
	CEngine* engine;
};