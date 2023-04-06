#pragma once

#include<glad/glad.h>
#include<ImGUI/imgui.h>

class FrameBuffer
{
public:
	FrameBuffer();
	~FrameBuffer();

public:
	GLuint FBID;
	GLuint RBID;
	GLuint TexID;
};