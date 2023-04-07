#pragma once
#include "EditorUI/ImGUILayer.h"

class DockSpace : public ImGUILayer
{
public:
	DockSpace() {};

	void Render() override;
};

