#include "ImGUILayer.h"

void ImGUILayer::RenderChildren()
{
	for (auto child : childLayers)
	{
		child->Render();
	}
}
