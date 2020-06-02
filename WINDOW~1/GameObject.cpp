#include "GameObject.h"

GameObject::GameObject(LPCWSTR filename)
{
	position = { 500,500 };
	angle = 0;
	scale = { 1,1 };
	Graphic::Load_Bitmap(this, filename);
}

GameObject::~GameObject()
{
}
