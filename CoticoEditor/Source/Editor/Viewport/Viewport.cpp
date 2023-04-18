#include "Viewport.h"
#include "Core/CEngine.h"

Viewport::Viewport() 
{
	FB = CEngine::Get()->GetRenderer()->GetFB();
}

void Viewport::Render()
{
	ImGui::Begin("Viewport", NULL, ImGuiWindowFlags_NoCollapse);
	ImGui::Image((void*)FB->TexID, ImGui::GetWindowSize(), ImVec2(0, 1), ImVec2(1, 0));
	ImGui::End();
}
