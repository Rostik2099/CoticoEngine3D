#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"


TestObject::TestObject()
{
	mesh = CreateComponent<MeshComponent>();
	mesh2 = CreateComponent<MeshComponent>();
	mesh3 = CreateComponent<MeshComponent>();
	mesh4 = CreateComponent<MeshComponent>();
	mesh5 = CreateComponent<MeshComponent>();
	mesh2->SetTexture("Content/Textures/b.png");
	mesh3->SetTexture("Content/Textures/o.png");
	mesh4->SetTexture("Content/Textures/b.png");
	mesh5->SetTexture("Content/Textures/a.png");
	mesh->SetTexture("Content/Textures/a.png");
	//Destroy();
}

void TestObject::Update()
{
}

