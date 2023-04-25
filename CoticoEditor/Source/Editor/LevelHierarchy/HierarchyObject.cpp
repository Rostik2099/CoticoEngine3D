#include "HierarchyObject.h"
#include "Core/CObject.h"

HierarchyObject::HierarchyObject() {}

void HierarchyObject::Render()
{
	if (object)
	{
		ImGui::Button(typeid(*object.GetRaw()).name());
	}
}
