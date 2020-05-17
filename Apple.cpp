#include "Apple.h"
#include "Ã∞≥‘…ﬂ.h"

Apple::Apple()
{
	NewApple();
}

void Apple::Draw()
{
	circle(_x * 48 + 160 + 24, _y * 48 + 24, 15);
}

void Apple::NewApple()
{
	_x = rand() % 10;
	_y = rand() % 10;
}
int Apple::GetX()
{
	return _x;
}
int Apple::GetY()
{
	return _y;
}