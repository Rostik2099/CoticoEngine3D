#pragma once
#include "EditorUI/ImGUILayer.h"
#include<unordered_map>
#include<string>

class HierarchyObject;
class LevelHierarchy : public ImGUILayer
{
public:
	LevelHierarchy();

	void Render() override;
	void AddObject(CObject* obj);
	void DeleteObject(CObject* obj);

private:
	std::unordered_map<std::string, HierarchyObject*> hierarchyObjects;
};

