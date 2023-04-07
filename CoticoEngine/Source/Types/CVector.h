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

class CVector2D
{
public:
	CVector2D() {};
	CVector2D(float a)
	{
		x = a;
		y = a;
	};
	CVector2D(float x, float y) 
	{
		this->x = x;
		this->y = y;
	};

public:
	float x = 0.0f;
	float y = 0.0f;
};