#include "Frames.h"
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Event.h"
#include "EnemyAttack.h"
#include "WithoutLevel2_Component.h"
#include "PrintLogsConsole.h"
#include "PrintLogsFile.h"
#include "DecoratorLevel2.h"
#include "ExtendedControllerFile.h"

#define esc 27
Frames::Frames()
{
    key = -1;
    start = clock();
    end = clock();
    controller_source = new ExtendedControllerFile();
    source = 1;
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
    source = InOut.AskControllerSource();
    singleton->logging(log_level2->Operation(GameStart), SecondLevel);
    InOut.Print(Fld, Plr);
    PrLogsConsole->execute();
    PrLogsFile->execute();
    do
    {
        end = clock();
        if (FldGen.GeneratorBombs(Fld, Enemies, Plr, start, end)) {
            InOut.Print(Fld, Plr);
            PrLogsConsole->execute();
            PrLogsFile->execute();
        }
        switch (source)
        {
        case Terminal:
            if (_kbhit()) {
                key = _getch();
                ReadComm.execute(Fld, Plr, Enemies, key);
                ReadComm.LoggingRead(key);
                InOut.Print(Fld, Plr);
                PrLogsConsole->execute();
                PrLogsFile->execute();
            }
            break;
        case File:
            key_file = controller_source->execute();
            if (key_file != -1) {
                ReadComm.execute(Fld, Plr, Enemies, key_file);
                ReadComm.LoggingRead(key);
                InOut.Print(Fld, Plr);
                PrLogsConsole->execute();
                PrLogsFile->execute();
            }
            if (_kbhit()) {
                key = _getch();
            }
            break;
        default:
            break;
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
