#include"CObject.h"
#include"World.h"

void CObject::Update()
{
}

World* CObject::GetWorld()
{ 
	return this->world;
};

void CObject::Destroy()
{
	GetWorld()->DestroyObject(this);
}