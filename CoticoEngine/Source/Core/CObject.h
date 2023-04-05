#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Core/World.h"
#include"Types/SoftReference.h"
#include"Components/BaseComponent.h"

class CObject
{
public:
	CObject() {};

	virtual void Update();
	void Destroy();
	std::vector<Ref<BaseComponent>> GetComponentsList() { return this->components; };

protected:
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
private:
	std::vector<Ref<BaseComponent>> components;
};

