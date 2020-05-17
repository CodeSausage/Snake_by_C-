#pragma once

class UI
{
public:
	UI(int x, int y);

	void Draw();
	
	void Compute_Score();
	
	void SetLevel(int x);
	
	int GetLevel();

	int GetScore();
private:
	int _score = 0;
	int _level = 1;
};
