#pragma once
#include "EventFactory.h"

class EnemyEventFactory : public EventFactory
{
public:
	Event* CreateEnemyAttack();
	Event* CreateEnemyDie();
	Event* CreateLooseHealthEnemy();
	Event* CreateGetAmmoPlayer();
	Event* CreateGetHealthPlayer();
	Event* CreateGetScorePlayer();
	Event* CreateLooseAmmoPlayer();
	Event* CreateLooseHealthPlayer();
	Event* CreatePlayerDie();
};

