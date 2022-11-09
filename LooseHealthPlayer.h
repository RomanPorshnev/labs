#pragma once
#include "PlayerEvent.h"

class LooseHealthPlayer : public PlayerEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~LooseHealthPlayer();
};

