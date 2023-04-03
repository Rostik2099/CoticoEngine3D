#pragma once

class World;
class BaseComponent
{
public:
	BaseComponent() {};

	void SetWorld(World* world) { this->world = world; };
	virtual void Update() {};
private:
	World* world;
};