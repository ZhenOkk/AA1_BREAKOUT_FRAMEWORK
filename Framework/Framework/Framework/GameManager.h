#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "Ball.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

using namespace std;

class GameManager {
private:
	void Menu();
	void Credits();
	void Highscore();

	void Gameplay();
	void InitGameplay(int width, int height, Pad** p, Ball** b, vector<Wall>& w, vector<Brick>& br);

	void GameOver();

	void CheckScore(vector<Brick> bricks);
	void WinLose(Ball* b, vector<Brick>& br, bool& gameplayRunning);

public:
	enum Scene { MENU, GAMEPLAY, HIGHSCORE, CREDITS, GAMEOVER };
	Scene currentScene;
	bool isPlaying;
	int score = 0;
	int bricksCount;

	GameManager() : currentScene(MENU), isPlaying(true) {}
	void Update();
};