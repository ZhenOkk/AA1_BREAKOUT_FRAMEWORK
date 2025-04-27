#include <iostream>
#include "GameManager.h"

using namespace std;

int main() {
	GameManager game;

	while (game.isPlaying) {
		game.Update();
	}
	return 0;
}