#include "GetHealthPlayer.h"

void GetHealthPlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Plr->SetHP(Plr->GetHP() + 1);
}

GetHealthPlayer::~GetHealthPlayer()
{
}
