#pragma once
#include "EnemyEvent.h"
class EnemyDie : public EnemyEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~EnemyDie();
};

