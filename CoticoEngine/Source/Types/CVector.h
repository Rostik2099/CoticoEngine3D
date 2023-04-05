#pragma once

class CVector
{
public:
	CVector() {};
	CVector(float a) 
	{
		x = a;
		y = a;
		z = a;
	};
	CVector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	};

public:
	float x = 0.f;
	float y = 0.f;
	float z = 0.f;
};

