#pragma once
#include <d2d1.h>
#include "Graphic.h"

class GameObject
{
public:
	GameObject(LPCWSTR filename);
	~GameObject();
public:
	bool exist = true;
	D2D_VECTOR_2F position;
	float angle;
	D2D_VECTOR_2F scale;
	ID2D1Bitmap* pBitmap;
};

