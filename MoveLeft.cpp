#include "MoveLeft.h"
#include "GetHealthPlayer.h"
#include "GetAmmoPlayer.h"
#include "LooseHealthPlayer.h"
#include "PlayerDie.h"
#include "WithoutLevel1_Component.h"
#include "DecoratorLevel1.h"

MoveLeft::MoveLeft()
{
    ev = nullptr;
    ev_factory = new PlayerEventFactory();
    ev_plr_die = nullptr;
    singleton = singleton->GetInstance();
    woutlevel1 = new WithoutLevel1_Component;
    log_level1 = new DecoratorLevel1(woutlevel1);
}

MoveLeft::~MoveLeft()
{
    singleton = nullptr;
    delete singleton;
    delete ev;
    delete ev_factory;
    delete ev_plr_die;
    singleton = singleton->GetInstance();
}

void MoveLeft::execute(Player* Plr, Field* Fld, std::vector<Enemy*>& Enemies)
{
    singleton->logging(log_level1->Operation(Move_Left), FirstLevel);
    TempMatrix = Fld->GetField();
    char c = TempMatrix[Plr->GetX()][Plr->GetY()].GetC();
    if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetBoarderPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Fld->GetN());
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetEmptyPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()] = TempMatrix[Plr->GetX()][Plr->GetY() - 1];
        Plr->SetY(Plr->GetY() - 1);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetHealthPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = ev_factory->CreateGetHealthPlayer();
        singleton->logging(log_level1->Operation(Get_Health), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetAmmoPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = ev_factory->CreateGetAmmoPlayer();
        singleton->logging(log_level1->Operation(Get_Ammo), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetBombPos()) {
        TempMatrix[Plr->GetX()][Plr->GetY()].SetC(' ');
        Plr->SetY(Plr->GetY() - 1);
        ev = ev_factory->CreateLooseHealthPlayer();
        singleton->logging(log_level1->Operation(Step_Bomb), FirstLevel);
    }
    else if (TempMatrix[Plr->GetX()][Plr->GetY() - 1].GetWallPos()) {
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
