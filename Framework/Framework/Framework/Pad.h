#pragma once
#include <vector>

#include "Vector2.h"
#include "Wall.h"
#include "ConsoleControl.h"

class Pad {
private:
	Vector2 position;
	int width;
	char symbol;
public:
	Pad();
	Pad(int w, Vector2 pos, char c) { width = w; position = pos; symbol = c; }
	Vector2 GetPosition() { return position; }
	void Render();
	void Update(int ScreenWidth);
	void MoveLeft();
	void MoveRight();
	int GetWidth() { return width; }
};