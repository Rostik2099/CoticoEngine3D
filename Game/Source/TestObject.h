#pragma once
#include "Core/CObject.h"
#include "Components/MeshComponent.h"

class TestObject : public CObject
{
public:
	TestObject();

private:
	Ref<MeshComponent> mesh;
};

