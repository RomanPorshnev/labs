#include "LooseHealthPlayer.h"

void LooseHealthPlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Plr->SetHP(Plr->GetHP() - 1);
}

LooseHealthPlayer::~LooseHealthPlayer()
{
}
