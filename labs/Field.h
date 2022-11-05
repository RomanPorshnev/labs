#pragma once
#include <vector>
#include "Cell.h"
#include "Player.h"
class Field
{
public:
	Field();
	Field(int m, int n);
	Field(const Field&);
	Field& operator =(const Field&);
	Field(Field&&);
	Field& operator=(Field&& obj);
	~Field();
	void InitMatrix();
	void SetPosPlayer(Player*);
	std::vector<std::vector<Cell>> GetField();
	void SetMatrix(std::vector<std::vector<Cell>>);
	int GetM();
	int GetN();
private:
	int m;
	int n;
	std::vector<std::vector<Cell>> matrix;
};

