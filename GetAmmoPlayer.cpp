#include "GetAmmoPlayer.h"
#include <Windows.h>
#include <iostream>
void GetAmmoPlayer::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	Plr->SetAmmo(Plr->GetAmmo() + 1);
}

GetAmmoPlayer::~GetAmmoPlayer()
{
}
