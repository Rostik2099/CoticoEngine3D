#include "LevelHierarchy.h"
#include "HierarchyObject.h"
#include "Core/World.h"
#include "Core/CObject.h"

LevelHierarchy::LevelHierarchy()
{
	//World::Get()->onObjectAdd.AddListener(this, &LevelHierarchy::AddObject);
	//World::Get()->onObjectDelete.AddListener(this, &LevelHierarchy::DeleteObject);
}

void LevelHierarchy::Render()
{
	ImGui::Begin("Level Hierarchy");
	RenderChildren();
	ImGui::End();
}

void LevelHierarchy::AddObject(CObject* obj)
{
	HierarchyObject* newObject = new HierarchyObject;
	newObject->SetObject(obj);
	hierarchyObjects[obj->GetUUID()] = newObject;
}

void LevelHierarchy::DeleteObject(CObject* obj)
{
	delete hierarchyObjects[obj->GetUUID()];
	hierarchyObjects.erase(obj->GetUUID());
}
