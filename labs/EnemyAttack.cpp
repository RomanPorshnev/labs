#include "EnemyAttack.h"

void EnemyAttack::execute(Field* Fld, Player* Plr, Enemy* Enm)
{
	bool flag = false;
	int x_rand, y_rand;
	int k = 0;
	std::vector<std::vector<Cell>> TempMatrix = Fld->GetField();
	do {
		k++;
		x_rand = 1 + rand() % (Fld->GetM() - 1);
		y_rand = 1 + rand() % (Fld->GetN() - 1);
		if (TempMatrix[x_rand][y_rand].GetEmptyPos()) {
			TempMatrix[x_rand][y_rand].SetC('*');
			flag = true;
			k = 0;
		}
		if (k == Fld->GetM() * Fld->GetN())
			break;
	} while (!flag);
	Fld->SetMatrix(TempMatrix);
}

EnemyAttack::~EnemyAttack()
{
}
