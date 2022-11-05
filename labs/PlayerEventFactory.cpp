#include "PlayerEventFactory.h"
#include "GetAmmoPlayer.h"
#include "GetHealthPlayer.h"
#include "GetScorePlayer.h"
#include "LooseAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
Event* PlayerEventFactory::CreateEnemyAttack()
{
	return nullptr;
}
Event* PlayerEventFactory::CreateEnemyDie()
{
	return nullptr;
}
Event* PlayerEventFactory::CreateLooseHealthEnemy()
{
	return nullptr;
}
Event* PlayerEventFactory::CreateGetAmmoPlayer()
{
	return new GetAmmoPlayer();
}

Event* PlayerEventFactory::CreateGetHealthPlayer()
{
	return new GetHealthPlayer();
}

Event* PlayerEventFactory::CreateGetScorePlayer()
{
	return new GetScorePlayer();
}

Event* PlayerEventFactory::CreateLooseAmmoPlayer()
{
	return new LooseAmmoPlayer();
}

Event* PlayerEventFactory::CreateLooseHealthPlayer()
{
	return new LooseHealthPlayer();
}

Event* PlayerEventFactory::CreatePlayerDie()
{
	return new PlayerDie();
}
