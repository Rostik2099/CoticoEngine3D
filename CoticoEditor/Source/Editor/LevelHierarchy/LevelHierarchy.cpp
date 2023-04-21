#include "LevelHierarchy.h"
#include "HierarchyObject.h"
#include "Core/World.h"

LevelHierarchy::LevelHierarchy()
{
	UpdateList();
}

void LevelHierarchy::Render()
{
	ImGui::Begin("Level Hierarchy");
	RenderChildren();
	ImGui::End();
}

void LevelHierarchy::UpdateList()
{
	for (auto [id, object] : World::Get()->GetObjectsList())
	{
		HierarchyObject* newObject = CreateChildLayer<HierarchyObject>();
		newObject->SetObject(object.get());
	}
}
