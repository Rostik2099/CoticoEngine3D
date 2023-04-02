#include"CObject.h"
#include"World.h"

void CObject::Update()
{
}

void CObject::Destroy()
{
	GetWorld()->DestroyObject(this);
}