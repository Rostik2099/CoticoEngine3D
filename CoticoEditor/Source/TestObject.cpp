#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"


TestObject::TestObject()
{
	cubeMap = CreateComponent<CubeMapComponent>();
	mesh = CreateComponent<MeshComponent>();
	mesh->SetTexture("Content/Textures/unnamed.png");
	SpawnObject<CObject>();
	//Destroy();
}

void TestObject::Update()
{
}

void TestObject::BeginPlay()
{
	test.AddListener(this, &TestObject::SayMyName);
	test.Broadcast();
}

void TestObject::SayMyName()
{
	std::cout << "Heisenberg" << std::endl;
}

