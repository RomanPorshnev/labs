#pragma once
#include "PlayerEvent.h"
class LooseAmmoPlayer : public PlayerEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~LooseAmmoPlayer();
};

