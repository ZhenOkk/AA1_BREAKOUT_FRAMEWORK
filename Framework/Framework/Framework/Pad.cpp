#include "Pad.h"

Pad::Pad() {}

void Pad::Render()
{
	for (int x = -width; x <= width; x++) {
		ConsoleXY(position.x + x, position.y);
		ConsoleSetColor(ConsoleColor::LIGHTGREY, ConsoleColor::DARKGREY);
		std::cout << symbol;
	}
}

void Pad::Update(int screenWidth)
{
	if ((position.x - (width + 1)) > 0)
	{
		bool pressedLeft;
		pressedLeft = GetAsyncKeyState(VK_LEFT) != 0;
		if (pressedLeft) MoveLeft();
	}

	if ((position.x + (width + 1)) < screenWidth)
	{
		bool pressedRight;
		pressedRight = GetAsyncKeyState(VK_RIGHT) != 0;
		if (pressedRight) MoveRight();
	}
}

void Pad::MoveLeft()
{
	position.x -= 1;
}

void Pad::MoveRight()
{
	position.x += 1;
}
