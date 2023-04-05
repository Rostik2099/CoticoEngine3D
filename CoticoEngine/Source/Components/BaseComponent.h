#pragma once
#include "Core/World.h"
#include <iostream>

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() { std::cout << "Component deleted" << std::endl; };

	virtual void Update() {};
protected:
	World* GetWorld() { return World::Get(); };
};