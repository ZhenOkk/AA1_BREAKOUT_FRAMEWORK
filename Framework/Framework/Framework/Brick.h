#pragma once
#include "Vector2.h"
#include "ConsoleControl.h"

using namespace std;

class Brick {
private:
	Vector2 position;
	int health;
	char symbol;
public:

	Brick();
	Brick(int h, Vector2 pos, char c) { health = h; position = pos; symbol = c; }
	Vector2 GetPosition() { return position; }
	int GetHealth() { return health; }
	void SetPosition(Vector2 p) { position = p; }
	void Render();
	void TakeDamage();
};