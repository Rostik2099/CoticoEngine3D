#include "ImGUILayer.h"

bool ImGUILayer::HasFocus()
{
	return ImGui::IsWindowFocused();
}

void ImGUILayer::RenderChildren()
{
	for (auto child : childLayers)
	{
		child->Render();
	}
}
