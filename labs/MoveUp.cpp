#include "MoveUp.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
#include "WithoutLevel1_Component.h"
#include "DecoratorLevel1.h"

MoveUp::MoveUp()
{
    ev = nullptr;
    ev_factory = new PlayerEventFactory();
    ev_plr_die = nullptr;
    singleton = singleton->GetInstance();
    woutlevel1 = new WithoutLevel1_Component;
    log_level1 = new DecoratorLevel1(woutlevel1);
}

MoveUp::~MoveUp()
{
    singleton = nullptr;
    delete singleton;
    delete ev;
    delete ev_factory;
    delete ev_plr_die;
}

void MoveUp::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    singleton->logging(log_level1->Operation(Move_Up), FirstLevel);
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Fld->GetM());
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX() - 1][Plr->GetY()];
        Plr->SetX(Plr->GetX() - 1);
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetHealthPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = ev_factory->CreateGetHealthPlayer();
        singleton->logging(log_level1->Operation(Get_Health), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = ev_factory->CreateGetAmmoPlayer();
        singleton->logging(log_level1->Operation(Get_Ammo), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetX(Plr->GetX() - 1);
        ev = ev_factory->CreateLooseHealthPlayer();
        singleton->logging(log_level1->Operation(Step_Bomb), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX() - 1][Plr->GetY()].GetWallPos()) {
        singleton->logging(log_level1->Operation(Meet_Wall), FirstLevel);
    }
    TempMatrix[Plr->GetX()][Plr->GetY()].SetC(c);
    Fld->SetMatrix(TempMatrix);
    if (ev) {
        ev->execute(Fld, Plr, nullptr);
        ev_plr_die = ev_factory->CreatePlayerDie();
        ev_plr_die->execute(Fld, Plr, nullptr);
    }
}
