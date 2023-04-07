#include "Core/CEngine.h"
#include "TestObject.h"

int main()
{
	CEngine* Engine = CEngine::Get();
	World::Get()->SpawnObject<TestObject>();

	while (!Engine->WindowShouldClose())
	{
		Engine->Draw();
		Engine->Update();
	}

	return 0;
}

