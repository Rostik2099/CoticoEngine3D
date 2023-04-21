#pragma once
#include "Core/CObject.h"
#include "Components/MeshComponent.h"
#include "Events/Event.h"
#include "Components/CubeMapComponent.h"

class TestObject : public CObject
{
public:
	TestObject();

	void Update() override;
	void BeginPlay() override;

	void SayMyName();

private:
	Ref<CubeMapComponent> cubeMap;
	Ref<MeshComponent> mesh;
	Event test;
};

