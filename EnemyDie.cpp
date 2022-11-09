#include "EnemyDie.h"
#include <iostream>
#include <Windows.h>
void EnemyDie::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	if (!Enm->GetHP()) {
		std::vector<std::vector<Cell>> TempMatrix = Fld->GetField();
		TempMatrix[Enm->GetX()][Enm->GetY()].SetC('=');
		Fld->SetMatrix(TempMatrix);
	}
}

EnemyDie::~EnemyDie()
{
}
