#include "Core/CEngine.h"

int main()
{
	CEngine Engine;
	//Engine.CreateWindow("Cotico Engine");

	while (!Engine.WindowShouldClose())
	{
		Engine.Draw();
	}

	return 0;
}