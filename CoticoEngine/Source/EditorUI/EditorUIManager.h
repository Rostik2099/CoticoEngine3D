#pragma once
#include<ImGUI/imgui.h>
#include<ImGUI/imgui_impl_glfw.h>
#include<ImGUI/imgui_impl_opengl3.h>
#include<unordered_map>
#include<memory>
#include"Core/World.h"

#include"EditorUI/ImGUILayer.h"

class EditorUIManager
{
public:
	void Init(GLFWwindow* window);
	void BeginRender();
	void EndRender();
	void Render();

	static EditorUIManager* GetUIManager()
	{
		static EditorUIManager manager;
		return &manager;
	};

	void SetCustomColors();

	template<typename T>
	T* CreateNewLayer() 
	{
		std::shared_ptr<T> newLayer = std::make_shared<T>();
		newLayer.get()->SetUUID(World::Get()->GenerateUUID());
		layers[newLayer.get()->GetUUID()] = newLayer;
		return newLayer.get();
	};

	std::shared_ptr<ImGUILayer> GetLayerWithID(std::string id) { return this->layers[id]; };
private:
	EditorUIManager();

	~EditorUIManager();

	std::unordered_map<std::string, std::shared_ptr<ImGUILayer>> layers;
};

