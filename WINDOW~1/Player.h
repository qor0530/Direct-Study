#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
private:
	Bullet* bullet[10];
	int currentbullet;
	float bullettime = 0;
public:
	Player(LPCWSTR filename);
public:
	void Move();
	void Shot();
	void Render();
	void BulletAttackCheck(GameObject* obj);
};

