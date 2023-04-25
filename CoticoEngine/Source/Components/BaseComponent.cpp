#include"BaseComponent.h"
#include<iostream>

void BaseComponent::SetLocation(CVector newLoc)
{
	this->transform.location = newLoc;
}

void BaseComponent::SetRotation(CVector newRot)
{
	this->transform.rotation = newRot;
}

void BaseComponent::SetScale(CVector newScale)
{
	this->transform.scale = newScale;
}

void BaseComponent::SetTransform(CTransform newTransform)
{
	this->transform = newTransform;
}
