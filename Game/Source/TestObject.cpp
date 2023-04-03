#include "TestObject.h"
#include "Core/CEngine.h"
#include "Core/World.h"

TestObject::TestObject()
{
	mesh = CreateComponent<MeshComponent>();
}

