#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Core/World.h"
#include"Input/InputManager.h"
#include"Types/SoftReference.h"
#include"Components/BaseComponent.h"

class CObject
{
public:
	CObject() {};

	virtual void BeginPlay();
	virtual void Update();
	virtual void SetupInputs(InputManager* inputManager);
	void Destroy();
	std::vector<Ref<BaseComponent>> GetComponentsList() { return this->components; };

	void SetUUID(std::string uuid) { this->uuid = uuid; };
	std::string GetUUID() { return this->uuid; };

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
	std::string uuid;
};

