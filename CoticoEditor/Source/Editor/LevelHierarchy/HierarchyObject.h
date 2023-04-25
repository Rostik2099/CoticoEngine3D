#pragma once
#include "EditorUI/ImGUILayer.h"

class CObject;
class HierarchyObject : public ImGUILayer
{
public:
	HierarchyObject();

	void Render() override;
	void SetObject(Ref<CObject> object) { this->object = object; };

private:
	Ref<CObject> object;
};

