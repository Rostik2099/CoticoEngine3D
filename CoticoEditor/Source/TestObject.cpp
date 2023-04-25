#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"


TestObject::TestObject()
{
	cubeMap = CreateComponent<CubeMapComponent>();
	mesh = CreateComponent<MeshComponent>();
	mesh->SetTexture("Content/Textures/unnamed.png");
	Ref<CObject> aboba = SpawnObject<CObject>();
	aboba->Destroy();
	//Destroy();
}

void TestObject::Update()
{
}

void TestObject::SetupInputs(InputManager* inputManager)
{
	inputManager->BindAxis("CameraUp", this, &TestObject::Walk);
	inputManager->BindAction("Jump", IE_PRESS, this, &TestObject::SayMyName);
	inputManager->BindAction("Jump", IE_RELEASE, this, &TestObject::YouAreRight);
}

void TestObject::BeginPlay()
{
}

void TestObject::SayMyName()
{
	std::cout << "Heisenberg" << std::endl;
}

void TestObject::YouAreRight()
{
	std::cout << "You are god damn right" << std::endl;
}

void TestObject::Walk(float scale)
{
	std::cout << "Wolk ne wolk " << scale << std::endl;
}

 