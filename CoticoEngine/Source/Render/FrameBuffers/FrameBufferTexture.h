#pragma once
#include<glad/glad.h>
#include<ImGUI/imgui.h>
#include<ImGUI/imgui_impl_glfw.h>
#include<ImGUI/imgui_impl_opengl3.h>
#include"Render/Texture.h"

class FrameBufferTexture : public Texture
{
public:
	FrameBufferTexture();
};

