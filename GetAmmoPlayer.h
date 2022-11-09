#pragma once
#include "PlayerEvent.h"
class GetAmmoPlayer : public PlayerEvent
{
public:
	void execute(Field* Fld, Player* Plr, Enemy* Enm);
	~GetAmmoPlayer();
};

