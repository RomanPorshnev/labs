#include "PlayerDie.h"
#include <iostream>
#include <Windows.h>
void PlayerDie::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	if (!Plr->GetHP()) {
		matrix = Fld->GetField();
		matrix[Plr->GetX()][Plr->GetY()].SetC(' ');
		Fld->SetMatrix(matrix);
		system("cls");
		std::cout << "Game Over! You Died!";
		Sleep(5000);
		
	}
}

PlayerDie::~PlayerDie()
{
}
