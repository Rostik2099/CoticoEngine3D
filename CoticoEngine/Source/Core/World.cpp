#include"World.h"
#include"CEngine.h"
#include"CObject.h"
#include"Components/BaseComponent.h"
#include"Components/CubeMapComponent.h"
#include<iostream>

void World::Update()
{
	for (auto obj : objects)
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

void World::DeleteObjects()
{
	for (auto deleteObj : objectDeletionList)
	{
		int pos = 0;
		for (auto obj : objects)
		{
			if (obj.get() == deleteObj)
			{
				break;
			}
			pos++;
		}
		objects.erase(objects.begin() + pos);
	}
	objectDeletionList.clear();
}

void World::DeleteComps()
{
	for (auto deleteComp : compsDeletionList)
	{
		int pos = 0;
		if (dynamic_cast<MeshComponent*>(deleteComp))
		{
			for (auto comp : meshComps)
			{
				if (comp.get() == deleteComp)
				{
					break;
				}
				pos++;
			}
			meshComps.erase(meshComps.begin() + pos);
		}
		else
		{
			for (auto comp : components)
			{
				if (comp.get() == deleteComp)
				{
					break;
				}
				pos++;
			}
			components.erase(components.begin() + pos);
		}
	}
	compsDeletionList.clear();
}
