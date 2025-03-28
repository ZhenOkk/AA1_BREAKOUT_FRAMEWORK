#include "MenuScene.h"

void MenuScene::Update()
{
	if (GetAsyncKeyState('1') != 0) {
		nextScene = "Ranking"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
	else if (GetAsyncKeyState('2') != 0) {
		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState('3') != 0) {
		nextScene = "Exit";
		finished = true;
	}
}

void MenuScene::Render()
{
	std::cout << " _____                 _           _   \n";
	std::cout << "| __  |___ ___ ___ ___| |_ ___ _ _| |_ \n";
	std::cout << "| __ -|  _| -_| .'|  _| '_| . | | |  _|\n";
	std::cout << "|_____|_| |___|__,|___|_,_|___|___|_|  \n";
	std::cout << "\nPress 1 for Ranking and 2 for Gameplay\n";
}
