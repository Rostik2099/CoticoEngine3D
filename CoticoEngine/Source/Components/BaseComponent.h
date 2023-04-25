#pragma once
#include "Core/World.h"
#include "Types/CTransform.h"
#include <iostream>

class BaseComponent
{
public:
	BaseComponent() {};
	~BaseComponent() {};

	virtual void BeginPlay() {};
	virtual void Update() {};
	CVector GetLocation() { return this->transform.location; };
	CVector GetRotation() { return this->transform.rotation; };
	CVector GetScale() { return this->transform.scale; };
	Ref<CObject> GetOwner() { return Ref<CObject>(owner); };

	void SetUUID(std::string uuid) { this->uuid = uuid; };
	std::string GetUUID() { return this->uuid; };

	virtual void SetLocation(CVector newLoc);
	virtual void SetRotation(CVector newRot);
	virtual void SetScale(CVector newScale);
	virtual void SetTransform(CTransform newTransform);
	void SetOwner(CObject* owner)
	{

	};
protected:
	World* GetWorld() { return World::Get(); };

protected:
	CTransform transform;
private:
	std::string uuid;
	std::weak_ptr<CObject> owner;
};