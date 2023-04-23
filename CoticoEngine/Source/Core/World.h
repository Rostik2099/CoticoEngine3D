#pragma once
#include<vector>
#include<unordered_map>
#include<memory>
#include"Types/SoftReference.h"

class MeshComponent;
class BaseComponent;
class Renderer;
class CObject;
class CEngine;

class World
{
public:
	void Update();
	void DestroyObject(CObject* object);
	std::unordered_map<std::string, std::shared_ptr<MeshComponent>> GetMeshComps() { return this->meshComps; };
	void SetEngine(CEngine* engine) { this->engine = engine; };

	template<typename Type>
	Ref<Type> SpawnObject()
	{
		std::shared_ptr<Type> newObj = std::make_shared<Type>();
		std::string newID = GenerateUUID();
		newObj->SetUUID(newID);
		objects[newID] = newObj;
		Ref<Type> objRef(newObj);
		newObj->SetupInputs(InputManager::Get());
		newObj->BeginPlay();
		return objRef;
	};

	template<typename Type>
	Ref<Type> SpawnComponent()
	{
		std::shared_ptr<Type> newComp = std::make_shared<Type>();
		std::string newID = GenerateUUID();
		newComp->SetUUID(newID);
		if (dynamic_cast<MeshComponent*>(newComp.get()))
		{
			this->meshComps[newID] = newComp;
		}
		else
		{
			this->components[newID] = newComp;
		}
		Ref<Type> compRef(newComp);
		newComp->BeginPlay();
		return compRef;
	};

	static World* Get()
	{
		static World world;
		return &world;
	};

	Renderer* GetRenderer();
	std::unordered_map<std::string, std::shared_ptr<CObject>> GetObjectsList() { return this->objects; };
	std::shared_ptr<CObject> GetObjectWithID(std::string UUID);
	std::shared_ptr<BaseComponent> GetComponentWithID(std::string UUID);

private:
	World() {};
	void DeleteObjects();
	void DeleteComps();
	std::string GenerateUUID();

private:
	CEngine* engine;
	std::unordered_map<std::string, std::shared_ptr<CObject>> objects;
	std::unordered_map<std::string, std::shared_ptr<BaseComponent>> components;
	std::unordered_map<std::string, std::shared_ptr<MeshComponent>> meshComps;
	std::vector<CObject*> objectDeletionList;
	std::vector<BaseComponent*> compsDeletionList;
};

