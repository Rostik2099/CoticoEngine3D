#pragma once
#include<ImGUI/imgui.h>
#include<ImGUI/imgui_impl_glfw.h>
#include<ImGUI/imgui_impl_opengl3.h>

class ImGUILayer
{
public:
	ImGUILayer() {};

	virtual void Render() {};
};

