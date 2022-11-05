#include "Frames.h"
#include <conio.h>
#include <Windows.h>
#include "InputOutput.h"
#include "ReadFromKeyb.h"
#include <time.h>
#include "Event.h"
#include "FieldGenerators.h"
#include "EnemyAttack.h"
#include "WithoutLevel2_Component.h"
#include "PrintLogsConsole.h"
#include "PrintLogsFile.h"
#include "DecoratorLevel2.h"
#define esc 27
Frames::Frames()
{
    singleton = singleton->GetInstance();
    woutlevel2 = new WithoutLevel2_Component;
    log_level2 = new DecoratorLevel2(woutlevel2);
    PrLogsConsole = new PrintLogsConsole();
    PrLogsFile = new PrintLogsFile();
    
}

Frames::~Frames()
{
    delete woutlevel2;
    delete log_level2;
    delete PrLogsConsole;
    delete PrLogsFile;
}

void Frames::Update(Field* Fld, Player* Plr, std::vector<Enemy*> Enemies)
{
    int key = 0;
    ReadFromKeyb Rfk;
    InputOutput InOut;
    singleton->logging(log_level2->Operation(GameStart), SecondLevel);
    InOut.Print(Fld, Plr);
    PrLogsConsole->execute();
    PrLogsFile->execute();
    FieldGenerators FldGen;
    clock_t start = clock(), end;
    do
    {
        end = clock();
        if (FldGen.GeneratorBombs(Fld, Enemies, Plr, start, end)) {
            InOut.Print(Fld, Plr);
            PrLogsConsole->execute();
            PrLogsFile->execute();
        }
        if (_kbhit()) {
            key = _getch();
            Rfk.CommRead(Fld, Plr, Enemies, key);
            Rfk.LoggingRead(key);
            InOut.Print(Fld, Plr);
            PrLogsConsole->execute();
            PrLogsFile->execute();
        }
    } while (key != esc && Plr->GetHP() && CheckEnemies(Enemies));
    singleton->logging(log_level2->Operation(GameEnd), SecondLevel);
    InOut.Print(Fld, Plr);
    PrLogsConsole->execute();
    PrLogsFile->execute();
}

bool Frames::CheckEnemies(std::vector<Enemy*> Enemies)
{
    bool check = false;
    for (int i = 0; i < Enemies.size(); i++) {
        if (Enemies[i])
            check = true;
    }
    if (check) {
        return true;
    }
    else {
        system("cls");
        std::cout << "You win!\n";
        for (int i = 0; i < Enemies.size(); i++) {
            delete Enemies[i];
        }
        Sleep(5000);
        return false;
    }
}
