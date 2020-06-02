#include "GameScene.h"

void GameScene::Init()
{
	player = new Player(L"1.png");
	enemy = new GameObject(L"1.jpg");
	enemy->position = { 1300, 300 };
}

void GameScene::Update()
{
	player->Move();
	player->Shot();
	player->BulletAttackCheck(enemy);
}

void GameScene::Render()
{
	player->Render();
	Graphic::Render(enemy);
}

void GameScene::Release()
{
	delete player;
}
