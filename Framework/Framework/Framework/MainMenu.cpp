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
		nextScene = "Credits";
		finished = true;
	}
	else if (GetAsyncKeyState('4') != 0) {
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
	std::cout << "\n[1] - Ranking";
	std::cout << "\n[2] - Gameplay";
	std::cout << "\n[3] - Credits";

	ConsoleSetColor(RED, BLACK);
	std::cout << "\n\n[4] - Exit\n\n";
	ConsoleSetColor(WHITE, BLACK);
}
