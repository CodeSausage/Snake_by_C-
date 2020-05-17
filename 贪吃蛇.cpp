#include "Ã∞≥‘…ﬂ.h"
#include "Apple.h"
#include "Snake.h"
#include "UI.h"
#include "Wall.h"

//class Wall;
//class UI;
//class Snake;
//class Apple;

bool isGameRunning = true;
Snake snake;
Wall wall;
Apple apple;
UI ui(1,0);

bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}

void Draw()
{
	cleardevice();
	snake.Draw();
	wall.Draw();
	apple.Draw();
	ui.Draw();
}

void KeyboardControl()
{
	if (IsKeyDown(VK_ESCAPE))//ESC end game
	{
		isGameRunning = false;
		return;
	}
	if (IsKeyDown(VK_LEFT))
	{
		snake.ChangeDirection(Direction::Left);
	}
	if (IsKeyDown(VK_RIGHT))
	{
		snake.ChangeDirection(Direction::Right);
	}
	if (IsKeyDown(VK_DOWN))
	{
		snake.ChangeDirection(Direction::Down);
	}
	if (IsKeyDown(VK_UP))
	{
		snake.ChangeDirection(Direction::Up);
	}

}


void HandleLogic()
{
	snake.Update( &(ui));
	if (snake.EatApple(apple))
	{
		ui.Compute_Score();
	}
}

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	cleardevice(); // use background color clear the screen.

	while (isGameRunning)
	{
		KeyboardControl(); //keyboard logic
		HandleLogic();//Game logic
		if (snake.EatSelf()) {
			RECT levelRect = { 200, 240, 330, 290 };
			drawtext(_T("”Œœ∑Ω· ¯"), &levelRect, DT_CENTER);
			system("pause");
			Sleep(3000);
			break;
		}
		Draw(); // handle the draw
		Sleep(30); // set the flash times

	}

	closegraph(); // clear the EasyX
	return 0;

}
