#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Memory/SoftReference.h"
#include"Components/BaseComponent.h"

class World;
class CObject
{
public:
	CObject() {};
	CObject(World* world) 
	{
		CObject::CObject();
		this->world = world; 
	};
	~CObject() { std::cout << "Object deleted" << std::endl; };

	virtual void Update();
	void Destroy();

	template<typename T>
	Ref<T> SpawnObject()
	{
		return GetWorld()->SpawnObject<T>();
	};

	template<typename T>
	Ref<T> CreateComponent()
	{
		std::cout << "Biba" << std::endl;
		return GetWorld()->SpawnComponent<T>();
	};

	World* GetWorld();
	void SetWorld(World* world) { this->world = world; };
private:
	World* world;
	std::vector<BaseComponent*> components;
};

