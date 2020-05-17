#pragma once
#include "UI.h"
#include "Apple.h"
#include "Ã∞≥‘…ﬂ.h"

class Snake
{
public:
	Snake();
	void Update(UI * ui);
	bool EatApple(Apple &apple);
	void Draw();
	void ChangeDirection(Direction dir);
	bool EatSelf();
private:
	list<POINT> _bodyList;
	Direction _dir;
	int lastMoveTick;
};
