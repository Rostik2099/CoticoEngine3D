#pragma once

#include<glad/glad.h>
#include<ImGUI/imgui.h>

#include"FrameBufferTexture.h"
class FrameBuffer
{
public:
	FrameBuffer();
	~FrameBuffer();

	GLuint GetTexID();

public:
	GLuint FBID;
	GLuint RBID;
	FrameBufferTexture* FBTex;
};