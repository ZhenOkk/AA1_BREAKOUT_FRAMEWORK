#pragma once
#include <iostream>

#include "Vector2.h"
#include "ConsoleControl.h"

enum WallType { HORIZONTAL, VERTICAL, CORNER };

using namespace std;

class Wall {
private:
	Vector2 position;
	WallType type;
	char symbol;
public:
	Wall();
	Wall(WallType t, Vector2 pos, char c) { type = t; position = pos; symbol = c; }
	Vector2 GetPosition() { return position; }
	WallType GetType() { return type; }
	void Render();
};