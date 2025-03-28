#include "CreditsScene.h"

void CreditsScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void CreditsScene::Render()
{
	std::cout << "Iago Merida\n";
	std::cout << "Sam Corchero :D\n\n";

	std::cout << "Press R to go back to the menu;";
}
