#include "PropertiesWindow.h"
#include "Components/MeshComponent.h"
#include "Render/Renderer.h"
#include "Core/World.h"

PropertiesWindow::PropertiesWindow()
{
	FB = World::Get()->GetRenderer()->GetFB();
}

void PropertiesWindow::Render()
{
	//ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
	ImGui::Begin("Bebra");
	FB->FBTex->Bind();
	ImGui::Image((void*)(intptr_t)FB->GetTexID(), ImGui::GetWindowSize());
	FB->FBTex->UnBind();
	ImGui::End();
}
