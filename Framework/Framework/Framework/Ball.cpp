#include "Ball.h"

Ball::Ball()
{
}

void Ball::Bounce(Vector2 normal)
{
}

void Ball::Update(vector<Wall> walls, vector<Brick>& bricks, Pad* pads)
{
	Vector2 targetPos = position + direction;
	bool auxChange = false;

	//Check walls
	for (auto it = walls.begin(); it != walls.end(); it++)
	{
		if (it->GetPosition() == targetPos)
		{
			switch (it->GetType())
			{
			case HORIZONTAL:
				direction.x *= -1;
				break;
			case VERTICAL:
				direction.y *= -1;
				break;
			case CORNER:
				direction.x *= -1;
				direction.y *= -1;
				break;
			}

			auxChange = true;
		}
	}

	if (auxChange) targetPos = position + direction;
	auxChange = false;

	// PADS checked

	Vector2 padPos = pads->GetPosition();
	int padX = padPos.x;
	int padY = padPos.y;

	if (padPos == targetPos)
	{
		direction.y *= -1;
		auxChange = true;
	}

	for (int x = 1; x <= pads->GetWidth(); x++) {
		if (padX == targetPos.x - x && padY == targetPos.y) {
			direction.y *= -1;
			direction.x = 1;
			auxChange = true;
		}

		if (padX == targetPos.x + x && padY == targetPos.y) {
			direction.y *= -1;
			direction.x = -1;
			auxChange = true;
		}
	}

	if (auxChange) targetPos = position + direction;
	auxChange = false;

	// Bricks checked
	int count;
	int toerase;
	bool hit;
	bool looping = true;
	while (looping) {
		hit = false;
		count = 0;
		for (auto it = bricks.begin(); it != bricks.end(); ++it)
		{
			if (it->GetPosition() == targetPos)
			{
				direction.y *= -1;
				hit = true;
				auxChange = true;
				toerase = count;
			}
			count++;
		}
		if (hit)
			bricks.erase(bricks.begin() + toerase);

		if (auxChange) targetPos = position + direction;
		auxChange = false;
		looping = hit;
	}

	// Life Countdown
	if (position.y > padY) {
		position = Vector2(position.x, position.y - 10);
		health--;
	}
	position = position + direction;
}

void Ball::Render()
{
	ConsoleXY(position.x, position.y);
	cout << "O";
}
