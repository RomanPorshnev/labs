#include "LooseHealthEnemy.h"

void LooseHealthEnemy::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Enm->SetHP(Enm->GetHP() - 1);
}

LooseHealthEnemy::~LooseHealthEnemy()
{
}
