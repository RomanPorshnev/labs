#include "EnemyEventFactory.h"
#include "EnemyAttack.h"
#include "EnemyDie.h"
#include "LooseHealthEnemy.h"
Event* EnemyEventFactory::CreateEnemyAttack()
{
	return new EnemyAttack();
}

Event* EnemyEventFactory::CreateEnemyDie()
{
	return new EnemyDie();
}

Event* EnemyEventFactory::CreateLooseHealthEnemy()
{
	return new LooseHealthEnemy();
}

Event* EnemyEventFactory::CreateGetAmmoPlayer()
{
	return nullptr;
}

Event* EnemyEventFactory::CreateGetHealthPlayer()
{
	return nullptr;
}

Event* EnemyEventFactory::CreateGetScorePlayer()
{
	return nullptr;
}

Event* EnemyEventFactory::CreateLooseAmmoPlayer()
{
	return nullptr;
}

Event* EnemyEventFactory::CreateLooseHealthPlayer()
{
	return nullptr;
}

Event* EnemyEventFactory::CreatePlayerDie()
{
	return nullptr;
}
