#include "Core/CEngine.h"
#include "Editor/LayersHandler.h"
#include "TestObject.h"

int main()
{
	CEngine* engine = CEngine::Get();
	World::Get()->SpawnObject<TestObject>();
	LayersHandler layersHandler;

	while (!engine->WindowShouldClose())
	{
		engine->Draw();
		engine->Update();
	}

	return 0;
}