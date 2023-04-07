#pragma once
#include "Core/World.h"
#include <iostream>

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() {};

	virtual void Update() {};
protected:
	World* GetWorld() { return World::Get(); };
};