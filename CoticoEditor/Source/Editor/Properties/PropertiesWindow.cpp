#include "PropertiesWindow.h"
#include "Components/MeshComponent.h"
#include "Core/World.h"

PropertiesWindow::PropertiesWindow() {}

void PropertiesWindow::Render()
{
	ImGui::Begin("Aboba", NULL, ImGuiWindowFlags_NoCollapse);
	int objCount = World::Get()->GetMeshComps().size() - 1;
	MeshComponent* mesh = World::Get()->GetMeshComps()[currentMesh].get();
	ImGui::SliderInt("Object index", &currentMesh, 0, objCount);
	meshLoc[0] = mesh->GetLocation().x * 100;
	meshLoc[1] = mesh->GetLocation().y * 100;
	meshLoc[2] = mesh->GetLocation().z * 100;

	if (ImGui::SliderFloat3("Location", meshLoc, -1000, 1000))
	{
		CVector newLoc = CVector(meshLoc[0] / 100, meshLoc[1] / 100, meshLoc[2] / 100);
		mesh->SetLocation(newLoc);
	}
	ImGui::End();
}
