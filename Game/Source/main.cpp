#include "Core/CEngine.h"

int main()
{
	CEngine Engine;

	while (!Engine.WindowShouldClose())
	{
		Engine.Draw();
		Engine.Update();
	}

	return 0;
}