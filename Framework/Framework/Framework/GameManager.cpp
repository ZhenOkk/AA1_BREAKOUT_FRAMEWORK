#include "GameManager.h"

void GameManager::Update()
{
	switch (currentScene)
	{
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		Gameplay();
		break;
	case GameManager::HIGHSCORE:
		Highscore();
		break;
	case GameManager::CREDITS:
		Credits();
		break;
	case GameManager::GAMEOVER:
		GameOver();
		break;
	}
}

void GameManager::Menu()
{
	int sleepTime = 20; //miliseconds
	bool keyPressed = false;
	bool pressed1, pressed2, pressed3;
	while (!keyPressed) {
		cout << " _____             _   _____     _   \n";
		cout << "| __  |___ ___ ___| |_|     |_ _| |_ \n";
		cout << "| __ -|  _| -_| .'| '_|  |  | | |  _|\n";
		cout << "|_____|_| |___|__,|_,_|_____|___|_|  \n\n";
		cout << "  1 - Play\n  2 - Credits\n  3 - Exit\n" << endl;
		pressed1 = GetAsyncKeyState('1') != 0;
		pressed2 = GetAsyncKeyState('2') != 0;
		pressed3 = GetAsyncKeyState('3') != 0;
		keyPressed = pressed1 || pressed2 || pressed3;
		Sleep(sleepTime);
		system("cls");
	}
	if (pressed1) currentScene = GAMEPLAY;
	else if (pressed2) currentScene = CREDITS;
	else if (pressed3) isPlaying = false;
}

void GameManager::Gameplay()
{
	// Start
	int sleepTime = 120; //miliseconds
	bool gameplayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	vector<Wall> walls;
	vector<Brick> bricks;
	int screenWidth = 18;
	int screenHeight = 25;

	InitGameplay(screenWidth, screenHeight, &playerPad, &ball, walls, bricks);

	// Update
	while (gameplayRunning)
	{
		// UPDATE
		ball->Update(walls, bricks, playerPad);
		playerPad->Update(screenHeight);
		CheckScore(bricks);
		WinLose(ball, bricks, gameplayRunning);

		// RENDER
		playerPad->Render();

		for (vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++) {
			it->Render();
		}

		for (vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++)
		{
			it->Render();
		}

		ball->Render();

		Sleep(sleepTime);
		system("cls");
	}

	// End
}

void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, vector<Wall>& w, vector<Brick>& br)
{
	// PAD
	*p = new Pad(2, Vector2(height / 2, width / 2 + width / 3), '-');

	// WALLS
	w.push_back(Wall(CORNER, Vector2(0, 0), '#'));
	w.push_back(Wall(CORNER, Vector2(0, width), '#'));
	w.push_back(Wall(CORNER, Vector2(height, 0), '#'));
	w.push_back(Wall(CORNER, Vector2(height, width), '#'));
	for (int x = 1; x < width; x++) {
		w.push_back(Wall(HORIZONTAL, Vector2(0, x), '|'));
		w.push_back(Wall(HORIZONTAL, Vector2(height, x), '|'));
	}
	for (int x = 1; x < height; x++) {
		w.push_back(Wall(VERTICAL, Vector2(x, 0), '-'));
		w.push_back(Wall(VERTICAL, Vector2(x, width), '-'));
	}

	// BRICKS
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j < height; j++)
		{
			if (i != 2 && j % 2 == 0 || i == 2)
				br.push_back(Brick(1, Vector2(j, i), '-'));
			if (i == 2) j++;
		}
	}

	// BALL
	*b = new Ball(Vector2(height / 2, width / 2), Vector2(1, 1), 1, 'o', 3);

	// SCORE
	bricksCount = br.size();
}

void GameManager::WinLose(Ball* b, vector<Brick>& br, bool& gameplayRunning)
{
	if (br.size() == 0)
	{
		currentScene = GAMEOVER;
		gameplayRunning = false;
	}

	if (b->GetHealth() == 0)
	{
		currentScene = GAMEOVER;
		gameplayRunning = false;
	}
}

void GameManager::CheckScore(vector<Brick> bricks) {

	if (bricksCount > bricks.size())
	{
		score += (bricksCount - bricks.size()) * 15;
		bricksCount = bricks.size();
	}
}

void GameManager::Highscore()
{
	cout << "Highscore" << endl;
}

void GameManager::Credits()
{
	cout << "Iago Merida Valencia" << endl;
	cout << "Sam Corchero Llopart" << endl;
	system("pause");
	currentScene = MENU;
}

void GameManager::GameOver()
{
	cout << " -- [ GAME OVER ] --" << endl;
	cout << "Score: " << score << endl;
	system("pause");
	currentScene = MENU;
}
