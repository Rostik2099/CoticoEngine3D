#include "DockSpace.h"

void DockSpace::Render()
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
}
