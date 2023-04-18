#pragma once
#include "EditorUI/ImGUILayer.h"

class CObject;
class HierarchyObject : public ImGUILayer
{
public:
	HierarchyObject();

	void Render() override;
	void SetObject(CObject* object) { this->object = object; };

private:
	CObject* object;
};

