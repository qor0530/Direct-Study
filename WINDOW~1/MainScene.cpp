#include "MainScene.h"

void MainScene::Init()
{
	SelectUI = new GameObject(L"화살표.png");
	for (int i = 0; i < 3; i++)
	{
		mainUI[i] = new  GameObject(L"게임시작.png");
	}

	SelectUI->position = { 1000,700 };
	SelectUI->scale = { 0.2f, 0.2f };
	for (int i = 0; i < 3; i++)
	{
		mainUI[i]->position = { 1200,700 + (float)160 * i };
		mainUI[i]->scale = { 1,0.5f };
	}
}

void MainScene::Update()
{
	PlayUI();
}

void MainScene::Render()
{
	Graphic::Render(SelectUI);
	for (int i = 0; i < 3; i++)
	{
		Graphic::Render(mainUI[i]);
	}
}

void MainScene::Release()
{
}

void MainScene::PlayUI()
{
	if (GetAsyncKeyState(VK_DOWN) & 0x0001 && cnt < 2)
	{
		cnt++;
	}
	if (GetAsyncKeyState(VK_UP) & 0x0001 && cnt > 0)
	{
		cnt--;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
	{
		switch (cnt)
		{
		case 0:
			GameSystem::change_s_number = GAME;
			break;
		case 1:
			break;
		case 2:
			GameSystem::GameExit = true;
			break;
		}
	}
	SelectUI->position = { 900, 700 + (float)160 * cnt };
}
