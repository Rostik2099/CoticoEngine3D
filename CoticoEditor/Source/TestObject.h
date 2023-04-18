#pragma once
#include "Core/CObject.h"
#include "Components/MeshComponent.h"
#include "Components/CubeMapComponent.h"

class TestObject : public CObject
{
public:
	TestObject();

	void Update() override;

private:
	Ref<CubeMapComponent> cubeMap;
	Ref<MeshComponent> mesh;
	Ref<MeshComponent> mesh2;
	Ref<MeshComponent> mesh3;
	Ref<MeshComponent> mesh4;
	Ref<MeshComponent> mesh5;
};

