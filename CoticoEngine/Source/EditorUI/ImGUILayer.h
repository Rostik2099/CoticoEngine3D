#pragma once
#include<ImGUI/imgui.h>
#include<ImGUI/imgui_impl_glfw.h>
#include<ImGUI/imgui_impl_opengl3.h>
#include<vector>
#include<string>
#include<memory>
#include"Types/SoftReference.h"

class ImGUILayer
{
public:
	ImGUILayer() {};

	virtual void Render() {};
	void SetUUID(std::string uuid) { this->uuid = uuid; };
	std::string GetUUID() { return this->uuid; };

protected:
	template<typename T>
	T* CreateLayer()
	{
		return EditorUIManager::GetUIManager()->CreateNewLayer<T>();
	};
	
	template<typename T>
	T* CreateChildLayer()
	{
		std::shared_ptr<T> newLayer = std::make_shared<T>();
		childLayers.push_back(newLayer);
		return newLayer.get();
	};

	bool HasFocus();
	void RenderChildren();

	std::vector<std::shared_ptr<ImGUILayer>> childLayers;

	std::string uuid;
};

