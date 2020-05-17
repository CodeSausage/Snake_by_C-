#include "Ã∞≥‘…ﬂ.h"
#include "Snake.h"

Snake::Snake()
{
	POINT head = { 1,1 };
	_bodyList.push_back(head);

	POINT p1 = { 1,2 };
	POINT p2 = { 1,3 };
	POINT p3 = { 2, 3 };
	_bodyList.push_back(p1);
	_bodyList.push_back(p2);
	_bodyList.push_back(p3);

	_dir = Direction::Right;


}
void Snake::Update(UI * ui)
{
	int xoffset[4] = { 0,0,-1,1 };
	int yoffset[4] = { -1, 1, 0, 0 };

	int curTick = GetTickCount();
	
	// avoid 0 to make the code bad.
	if (curTick - lastMoveTick < (500 / (ui->GetLevel() == 0 ? 1 : ui->GetLevel())))
	{
		return;
	}
	if (ui->GetScore()!=0 && ui->GetScore() % 5 == 0)
	{
		ui->SetLevel(ui->GetScore() / 5);
	}

	lastMoveTick = curTick;

	list<POINT>::iterator it = _bodyList.begin();

	int prevX = it->x;
	int prevY = it->y;
	it->x += xoffset[_dir];
	it->y += yoffset[_dir];

	// crosss the wall
	if (it->x * 48 + 160 > 640)
	{
		it->x = 0;
	}
	if (it->x * 48 + 160 < 160)
	{
		it->x = 10;
	}
	if (it->y * 48 > 480)
	{
		it->y = 0;
	}
	if (it->y * 48 < 0)
	{
		it->y = 10;
	}
	it++;

	for (; it != _bodyList.end(); ++it)
	{
		if (it == _bodyList.end())
		{
			break;
		}
		int curX = it->x;
		int curY = it->y;

		it->x = prevX;
		it->y = prevY;

		prevX = curX;
		prevY = curY;
	}
}
bool Snake::EatApple(Apple &apple)
{

	list<POINT>::iterator headPos = _bodyList.begin();

	if (headPos->x != apple.GetX() || headPos->y != apple.GetY())
	{
		return false;
	}
	apple.NewApple();
	while (true)
	{
		bool apple_flag = true;
		for (auto it = _bodyList.begin(); it != _bodyList.end(); it++)
		{
			if (it->x == apple.GetX() && it->y == apple.GetY())
			{
				apple.NewApple();
				apple_flag = false;
			}
		}
		if (apple_flag)
		{
			break;
		}
	}

	POINT  end = _bodyList.back();
	_bodyList.push_back(end);
	return true;
}
void Snake::Draw()
{
	for (list<POINT>::iterator it = _bodyList.begin();
		it != _bodyList.end(); it++)
	{
		POINT pos = *it;
		rectangle(pos.x * 48 + 160, pos.y * 48, (pos.x + 1) * 48 + 160, (pos.y + 1) * 48);
		if (it == _bodyList.begin()) {
			circle(pos.x * 48 + 24 + 160, pos.y * 48 + 24, 15);
		}
	}

}
void Snake::ChangeDirection(Direction dir)
{
	if (_dir == Direction::Up && dir == Direction::Down
		|| _dir == Direction::Down && dir == Direction::Up
		|| _dir == Direction::Left && dir == Direction::Right
		|| _dir == Direction::Right && dir == Direction::Left)
	{
		return;  // can not move in the oppisite dir.
	}
	_dir = dir;
}
bool Snake::EatSelf()
{
	auto headPos = _bodyList.begin();
	auto it = headPos;
	it++;
	for (; it != _bodyList.end(); it++)
	{
		if (headPos->x == it->x && headPos->y == it->y)
		{
			return true;
		}
	}
	return false;
}