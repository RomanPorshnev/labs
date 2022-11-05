#pragma once
#include "Event.h"
class EnemyEvent : public Event
{
public:
	~EnemyEvent();
	virtual void execute(Field*, Player*, Enemy*) = 0;
};

