#include "Core/CEngine.h"
#include "TestObject.h"

int main()
{
	CEngine Engine;
	//Engine.GetWorld()->SpawnObject<TestObject>();

	while (!Engine.WindowShouldClose())
	{
		Engine.Draw();
		Engine.Update();
	}

	return 0;
}