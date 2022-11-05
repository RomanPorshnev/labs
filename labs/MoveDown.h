#pragma once
#include "Command.h"
#include "Field.h"
#include "EventFactory.h"
#include "PlayerEventFactory.h"
#include "Component.h"
class MoveDown : public Command
{
public:
	MoveDown();
	~MoveDown();
	void execute(Player*, Field*, std::vector<Enemy*>&);
private:
	Event* ev;
	EventFactory* ev_factory;
	Event* ev_plr_die;
	enum log_level1 { Move_Down = 1, Move_Left, Move_Right, Move_Up, Get_Health, 
		Get_Ammo, Step_Bomb, Meet_Wall, Enemy_Health, Player_Score,
	Enemy_Die, Miss};
	enum levels_log { FirstLevel = 1, SecondLevel, ThirdLevel };
	Component* woutlevel1;
	Component* log_level1;
};

