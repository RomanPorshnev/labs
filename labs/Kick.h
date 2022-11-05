#pragma once
#include "Command.h"
#include "EnemyEventFactory.h"
#include "PlayerEventFactory.h"
#include "Component.h"
class Kick : public Command
{
public:
	Kick();
	~Kick();
	void execute(Player*, Field*, std::vector<Enemy*>&);
	bool direction(Player*, Field*, Enemy*, int v, int h);
private:
	bool hit;
	EventFactory* ev_factory_enm;
	EventFactory* ev_factory_plr;
	Event* ev_loose_hp_enemy;
	Event* ev_get_score_plr;
	Event* ev_enemy_die;
	Event* ev_loose_ammo_plr;
	enum log_level1 {
		Move_Down = 1, Move_Left, Move_Right, Move_Up, Get_Health,
		Get_Ammo, Step_Bomb, Meet_Wall, Enemy_Health, Player_Score,
		Enemy_Die, Miss
	};
	enum levels_log { FirstLevel = 1, SecondLevel, ThirdLevel };
	Component* woutlevel1;
	Component* log_level1;
};

