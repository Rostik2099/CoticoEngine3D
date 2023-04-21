#include"CObject.h"
#include"World.h"

void CObject::BeginPlay()
{
}

void CObject::Update()
{
}

void CObject::Destroy()
{
	GetWorld()->DestroyObject(this);
}