#pragma once
#include "Event.h"
#include "InputOutput.h"
class PlayerEvent : public Event
{
public:
	~PlayerEvent();
	virtual void execute (Field*, Player*, Enemy*) = 0;
};

