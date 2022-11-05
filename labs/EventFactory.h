#pragma once
#include "Event.h"
class EventFactory
{
public:
	virtual Event* CreateEnemyAttack() = 0;
	virtual Event* CreateEnemyDie() = 0;
	virtual Event* CreateLooseHealthEnemy() = 0;
	virtual Event* CreateGetAmmoPlayer() = 0;
	virtual Event* CreateGetHealthPlayer() = 0;
	virtual Event* CreateGetScorePlayer() = 0;
	virtual Event* CreateLooseAmmoPlayer() = 0;
	virtual Event* CreateLooseHealthPlayer() = 0;
	virtual Event* CreatePlayerDie() = 0;
	~EventFactory();
};

