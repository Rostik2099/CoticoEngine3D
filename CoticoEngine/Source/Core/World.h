#pragma once
#include<vector>
#include<memory>
#include"Memory/SoftReference.h"
#include"Components/MeshComponent.h"

class BaseComponent;
class CObject;
class CEngine;
class World
{
public:
	World(CEngine* engine);

	void Update();
	void DestroyObject(CObject* object);

	template<typename Type>
	Ref<Type> SpawnObject()
	{
		std::shared_ptr<Type> newObj = std::make_shared<Type>(this);
		newObj->SetWorld(this);
		objects.push_back(newObj);
		Ref<Type> objRef(newObj);
		return objRef;
	};

	template<typename Type>
	Ref<Type> SpawnComponent()
	{
		std::shared_ptr<Type> newComp = std::make_shared<Type>();
		newComp->SetWorld(this);
		if (dynamic_cast<MeshComponent*>(newComp.get()))
		{
			engine->GetRenderer()->AddMeshComp(std::shared_ptr<MeshComponent>(newComp));
		}
		else
		{
			components.push_back(newComp);
		}
		Ref<Type> compRef(newComp);
		return compRef;
	};

private:
	void DeleteObjects();

private:
	CEngine* engine;
	std::vector<std::shared_ptr<CObject>> objects;
	std::vector<std::shared_ptr<BaseComponent>> components;
	std::vector<CObject*> deletionList;
};

