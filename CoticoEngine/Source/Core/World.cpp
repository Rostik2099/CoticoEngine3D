#include"World.h"
#include"CEngine.h"
#include"CObject.h"
#include"Components/BaseComponent.h"
#include"UUID/uuid.h"
#include"Components/CubeMapComponent.h"
#include<iostream>

void World::Update()
{
	for (auto [id, obj] : objects)
	{
		obj->Update();
	}
	DeleteObjects();
	DeleteComps();
}

void World::DestroyObject(CObject* object)
{
	objectDeletionList.push_back(object);
	for (auto comp : object->GetComponentsList())
	{
		compsDeletionList.push_back(comp.GetRaw());
	}
}

Renderer* World::GetRenderer()
{
	return this->engine->GetRenderer();
}

std::shared_ptr<CObject> World::GetObjectWithID(std::string UUID)
{
	return objects[UUID];
}

std::shared_ptr<BaseComponent> World::GetComponentWithID(std::string UUID)
{
	return components[UUID];
}

void World::DeleteObjects()
{
	for (auto deleteObj : objectDeletionList)
	{
		objects.erase(deleteObj->GetUUID());
	}
	objectDeletionList.clear();
}

void World::DeleteComps()
{
	for (auto deleteComp : compsDeletionList)
	{
		if (dynamic_cast<MeshComponent*>(deleteComp))
		{
			meshComps.erase(deleteComp->GetUUID());
		}
		else
		{
			components.erase(deleteComp->GetUUID());
		}
	}
	compsDeletionList.clear();
}

std::string World::GenerateUUID()
{
	UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
	UUIDv4::UUID uuid = uuidGenerator.getUUID();
	return uuid.str();
}
