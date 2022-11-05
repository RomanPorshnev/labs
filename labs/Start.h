#pragma once
#include "Enemy.h"
#include <vector>
#include "InputOutput.h"
#include "Field.h"
#include "FieldGenerators.h"
#include "Frames.h"
class Start
{
public:
	Start();
	~Start();
	void run();
private:
	Frames Frm;
	FieldGenerators FldGen;
	InputOutput InOut;
	Field* Fld;
	Player* Plr;
	std::vector<Enemy*> Enemies;
	Singleton* singleton;
};

