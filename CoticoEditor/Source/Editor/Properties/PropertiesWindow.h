#pragma once
#include "EditorUI/ImGUILayer.h"

class PropertiesWindow : public ImGUILayer
{
public:
	PropertiesWindow();

	void Render() override;

	float meshLoc[3];
	int currentMesh = 0;
};

