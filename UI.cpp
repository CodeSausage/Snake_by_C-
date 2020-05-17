#include "UI.h"
#include "̰����.h"

UI::UI(int x = 1, int y = 0)
{
	_level = x;
	_score = y;
}
void UI::Draw()
{
	RECT scoreRect = { 10, 10, 140, 50 };
	RECT scoreRect2 = { 20, 10, 150, 50 };
	//string score = "����";
	drawtext(_T("����: "), &scoreRect, DT_CENTER);
	TCHAR s[5];
	swprintf_s(s, _T("%d"), _score);
	outtextxy(30, 10, s);
	//drawtext('c', &scoreRect, DT_CENTER);

	RECT levelRect = { 10, 240, 140, 290 };
	RECT levelRect2 = { 20, 240, 150, 290 };
	drawtext(_T("�Ѷ�"), &levelRect, DT_CENTER);
	TCHAR s2[5];
	swprintf_s(s2, _T("%d"), _level);
	outtextxy(30, 240, s2);
	//drawtext(_level, &levelRect2, DT_CENTER);
}

void UI::Compute_Score()
{
	_score++;
}

void UI::SetLevel(int x)
{
	_level = x;
}

int UI::GetLevel()
{
	return _level;
}

int UI::GetScore()
{
	return _score;
}