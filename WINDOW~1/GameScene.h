#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Player.h"
#include "Graphic.h"

class GameScene : public Scene
{
private:
	Player* player;
	GameObject* enemy;
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

