#include "GetScorePlayer.h"

void GetScorePlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	if (!Enm->GetHP())
		Plr->SetScore(Plr->GetScore() + 1);
}

GetScorePlayer::~GetScorePlayer()
{
}
