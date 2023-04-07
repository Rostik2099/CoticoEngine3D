#include "Core/CEngine.h"
#include "Editor/LayersHandler.h"
#include "TestObject.h"

int main()
{
	CEngine* engine = CEngine::Get();
	LayersHandler layersHandler;
	World::Get()->SpawnObject<TestObject>();

	while (!engine->WindowShouldClose())
	{
		engine->Draw();
		engine->Update();
	}

	return 0;
}