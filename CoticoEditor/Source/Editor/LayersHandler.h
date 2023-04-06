#pragma once
#include"EditorUI/EditorUIManager.h"

class LayersHandler
{
public:
	LayersHandler();

private:
	template<typename T>
	T* CreateLayer()
	{
		return EditorUIManager::GetUIManager()->CreateNewLayer<T>();
	};
};

