#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
class Event
{
public:
	virtual void execute(Field*, Player*, Enemy*) = 0;
	~Event();
};

