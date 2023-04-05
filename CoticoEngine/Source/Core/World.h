#pragma once
#include<vector>
#include<memory>
#include"Types/SoftReference.h"

class MeshComponent;
class BaseComponent;
class CObject;
class CEngine;

class World
{
public:
	void Update();
	void DestroyObject(CObject* object);
	std::vector<std::shared_ptr<MeshComponent>> GetMeshComps() { return this->meshComps; };
	void SetEngine(CEngine* engine) { this->engine = engine; };

	template<typename Type>
	Ref<Type> SpawnObject()
	{
		std::shared_ptr<Type> newObj = std::make_shared<Type>();
		objects.push_back(newObj);
		Ref<Type> objRef(newObj);
		return objRef;
	};

	template<typename Type>
	Ref<Type> SpawnComponent()
	{
		std::shared_ptr<Type> newComp = std::make_shared<Type>();
		if (dynamic_cast<MeshComponent*>(newComp.get()))
		{
			this->meshComps.push_back(newComp);
		}
		else
		{
			components.push_back(newComp);
		}
		Ref<Type> compRef(newComp);
		return compRef;
	};

	static World* Get()
	{
		static World world;
		return &world;
	};

private:
	World() {};
	void DeleteObjects();
	void DeleteComps();
private:
	CEngine* engine;
	std::vector<std::shared_ptr<CObject>> objects;
	std::vector<std::shared_ptr<BaseComponent>> components;
	std::vector<std::shared_ptr<MeshComponent>> meshComps;
	std::vector<CObject*> objectDeletionList;
	std::vector<BaseComponent*> compsDeletionList;
};

