#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"


TestObject::TestObject()
{
	cubeMap = CreateComponent<CubeMapComponent>();
	//cubeMap->SetShaders("Shaders/default_vert.glsl", "Shaders/default_frag.glsl");
	//cubeMap->SetTexture("Content/Textures/unnamed.png");
	mesh = CreateComponent<MeshComponent>();
	//mesh2 = CreateComponent<MeshComponent>();
	//mesh3 = CreateComponent<MeshComponent>();
	//mesh4 = CreateComponent<MeshComponent>();
	//mesh5 = CreateComponent<MeshComponent>();
	//mesh2->SetTexture("Content/Textures/unnamed.png");
	//mesh3->SetTexture("Content/Textures/o.png");
	//mesh4->SetTexture("Content/Textures/b.png");
	//mesh5->SetTexture("Content/Textures/a.png");
	mesh->SetTexture("Content/Textures/unnamed.png");
	SpawnObject<CObject>();
	//Destroy();
}

void TestObject::Update()
{
}

