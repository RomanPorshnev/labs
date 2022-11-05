#include "LooseAmmoPlayer.h"

void LooseAmmoPlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	if (Plr->GetAmmo())
		Plr->SetAmmo(Plr->GetAmmo() - 1);
}

LooseAmmoPlayer::~LooseAmmoPlayer()
{
}
