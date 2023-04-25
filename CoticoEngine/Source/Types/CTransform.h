#pragma once
#include "CVector.h"

struct CTransform 
{
public:
	CVector location;
	CVector rotation;
	CVector scale = CVector(1.f);
};