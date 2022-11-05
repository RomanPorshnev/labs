#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
#include "Singleton.h"
class Command
{
public:
	virtual ~Command();
	virtual void execute(Player*, Field*, std::vector<Enemy*>&) = 0;
protected:
	std::vector<std::vector<Cell>> TempMatrix;
	Singleton* singleton;
};

