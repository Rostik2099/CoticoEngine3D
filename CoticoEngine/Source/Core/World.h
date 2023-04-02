#pragma once
#include<vector>
#include<memory>
#include"Memory/SoftReference.h"

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
		std::shared_ptr<CObject> newObj = std::make_shared<Type>();
		newObj->SetWorld(this);
		objects.push_back(newObj);
		std::weak_ptr<Type> weakRef = newObj;
		Ref<Type> objRef(weakRef);
		return objRef;
	};

private:
	void DeleteObjects();

private:
	CEngine* engine;
	std::vector<std::shared_ptr<CObject>> objects;
	std::vector<CObject*> deletionList;
};

