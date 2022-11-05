#pragma once
#include "PlayerEvent.h"
class GetScorePlayer : public PlayerEvent
{
public:
	void execute(Field*, Player* Plr, Enemy*);
	~GetScorePlayer();
};

