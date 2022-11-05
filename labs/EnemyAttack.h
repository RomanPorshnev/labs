#pragma once
#include "EnemyEvent.h"
class EnemyAttack : public EnemyEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~EnemyAttack();
};

