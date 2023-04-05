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
	mesh->SetLocation(CVector(0.f));
	mesh2->SetLocation(CVector(2.f, 0.0f, 0.0f));
	mesh3->SetLocation(CVector(4.f, 0.f, 0.f));
	mesh4->SetLocation(CVector(6.f, 0.f, 0.f));
	mesh5->SetLocation(CVector(8.f, 0.f, 0.f));
}

