#include "Brick.h"

Brick::Brick()
{
}

void Brick::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "#";
}

void Brick::TakeDamage()
{
	health = 0;
}
