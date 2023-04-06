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
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
	ImGui::Begin("Bebra", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiDockNodeFlags_NoResize);
	ImGui::Image((void*)FB->TexID, ImGui::GetWindowSize(), ImVec2(0, 1), ImVec2(1, 0));
	ImGui::End();

	ImGui::Begin("Aboba");
	ImGui::End();

	ImGui::Begin("Steve Huis");
	ImGui::End();

	ImGui::Begin("Pidoraska Negorka");
	ImGui::End();
}
