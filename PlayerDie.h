#pragma once
#include "PlayerEvent.h"
class PlayerDie : public PlayerEvent
{
public:
	void execute(Field*, Player*, Enemy*);
	~PlayerDie();
private:
	std::vector<std::vector<Cell>> matrix;
	InputOutput InOut;
};

