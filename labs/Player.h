#pragma once
class Player
{
public:
	Player(int x = 1, int y = 1);
	~Player();
	int GetX();
	int GetY();
	int GetHP();
	int GetScore();
	int GetAmmo();
	void SetX(int);
	void SetY(int);
	void SetHP(int);
	void SetScore(int);
	void SetAmmo(int);
private:
	int x;
	int y;
	int hp;
	int score;
	int ammo;
};

