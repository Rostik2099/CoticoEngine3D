#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Core/World.h"
#include"Memory/SoftReference.h"
#include"Components/BaseComponent.h"

class CObject
{
public:
	CObject() {};

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
		Ref<T> newComp = GetWorld()->SpawnComponent<T>();
		std::weak_ptr<BaseComponent> compRef = newComp.Get();
		components.push_back(compRef);
		return newComp;
	};

	World* GetWorld() { return World::Get(); };
	std::vector<Ref<BaseComponent>> GetComponentsList() { return this->components; };
private:
	std::vector<Ref<BaseComponent>> components;
};

