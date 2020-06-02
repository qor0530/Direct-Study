#include "Bullet.h"

Bullet::Bullet(LPCWSTR filename) : GameObject(filename)
{
}

void Bullet::Move()
{
	position.y -= 10;
	scale = { 0.5f, 0.5f };
}

void Bullet::Attack(GameObject* obj)
{
	if (ColliderManager::BoxCollider(this, obj))
	{
		obj->exist = false;
	}
}

