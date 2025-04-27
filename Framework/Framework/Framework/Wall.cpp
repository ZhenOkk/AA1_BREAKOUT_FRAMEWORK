#include "Wall.h"

Wall::Wall() {}

void Wall::Render()
{
	ConsoleXY(position.x, position.y);

	switch (type)
	{
	case HORIZONTAL:
		cout << "|";
		break;
	case VERTICAL:
		cout << "-";
		break;
	case CORNER:
		cout << "+";
		break;
	default:
		break;
	}
}
