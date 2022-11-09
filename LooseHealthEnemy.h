#pragma once
#include "EnemyEvent.h"
class LooseHealthEnemy : public EnemyEvent
{
public:
	void execute(Field* Fld, Player* Plr, Enemy* Enm);
	~LooseHealthEnemy();
};

