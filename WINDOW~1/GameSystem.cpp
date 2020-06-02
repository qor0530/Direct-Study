#include "GameSystem.h"

bool GameSystem::GameExit = false;
int GameSystem::change_s_number;

void GameSystem::Init()
{
	SetScene(SCENETYPE::MAIN);
}

void GameSystem::Update()
{
	scene->Update();
}

void GameSystem::Render()
{
	scene->Render();
}

void GameSystem::Release()
{
	scene->Release();
	delete scene;
}

void GameSystem::SetScene(int scenenumber)
{
	current_s_number = scenenumber;
	change_s_number = scenenumber;
	if (scene != nullptr)
	{
		scene->Release();
		delete scene;
	}
	switch (scenenumber)
	{
	case SCENETYPE::GAME:
		scene = new GameScene();
		break;
	case SCENETYPE::MAIN:
		scene = new MainScene();
	}
	if (scene != nullptr)
	{
		scene->Init();
	}
}

void GameSystem::SceneChangeCheck()
{
	if (current_s_number != change_s_number)
	{
		SetScene(change_s_number);
	}
}
