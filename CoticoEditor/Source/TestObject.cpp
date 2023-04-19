#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"


TestObject::TestObject()
{
	cubeMap = CreateComponent<CubeMapComponent>();
	mesh = CreateComponent<MeshComponent>();
	mesh->SetTexture("Content/Textures/unnamed.png");
	SpawnObject<CObject>();
	test.AddListener(this, &TestObject::SayMyName);
	test.Broadcast();
	//Destroy();
}

void TestObject::Update()
{
}

void TestObject::SayMyName()
{
	std::cout << "Heisenberg" << std::endl;
}

