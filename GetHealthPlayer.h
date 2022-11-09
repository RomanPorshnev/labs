#pragma once
#include "PlayerEvent.h"
class GetHealthPlayer : public PlayerEvent
{
public:
	void execute(Field* Fld, Player* Plr, Enemy* Enm);
	~GetHealthPlayer();
};

