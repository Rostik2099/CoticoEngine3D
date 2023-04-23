#pragma once
#include "Core/World.h"
#include <iostream>

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() {};

	virtual void BeginPlay() {};
	virtual void Update() {};

	void SetUUID(std::string uuid) { this->uuid = uuid; };
	std::string GetUUID() { return this->uuid; };
protected:
	World* GetWorld() { return World::Get(); };

private:
	std::string uuid;
};