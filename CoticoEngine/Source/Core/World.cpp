#include"World.h"
#include"CEngine.h"
#include"CObject.h"
#include<iostream>

World::World(CEngine* engine)
{
	this->engine = engine;

	for (int i = 0; i < 10; i++)
	{
		SpawnObject<CObject>();
	}
}

void World::Update()
{
	for (auto obj : objects)
	{
		obj->Update();
	}
	DeleteObjects();
}

void World::DestroyObject(CObject* object)
{
	deletionList.push_back(object);
}

void World::DeleteObjects()
{
	for (auto deleteObj : deletionList)
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
	deletionList.clear();
}