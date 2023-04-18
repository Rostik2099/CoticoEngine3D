#pragma once
#include "EditorUI/ImGUILayer.h"

class LevelHierarchy : public ImGUILayer
{
public:
	LevelHierarchy();

	void Render() override;
	void UpdateList();
};

