#pragma once
#include<iostream>
#include<string>
#include"Memory/SoftReference.h"

class World;
class CObject
{
public:
	CObject() {};
	~CObject() { std::cout << "Object deleted" << std::endl; };

	virtual void Update();
	void Destroy();

	World* GetWorld() { return this->world; };
	void SetWorld(World* world) { this->world = world; };
private:
	World* world;
};

