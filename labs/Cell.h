#pragma once
class Cell
{
public:
	Cell(char);
	~Cell();
	char GetC();
	void SetC(int);
	bool GetPersonPos();
	bool GetWallPos();
	bool GetBoarderPos();
	bool GetEmptyPos();
	bool GetHealthPos();
	bool GetAmmoPos();
	bool GetBombPos();
	bool GetEnemyPos();
private:
	char c;
};

