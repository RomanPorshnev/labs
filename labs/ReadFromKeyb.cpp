#include "ReadFromKeyb.h"
#include "MoveDown.h"
#include "MoveUp.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Kick.h"
#include <iostream>
#include <Windows.h>

#define down 115
#define up 119
#define left 97
#define right 100
#define kick 32
#define log_to_file 102
#define log_to_console 99
#define first_level 49
#define second_level 50
#define third_level 51

ReadFromKeyb::ReadFromKeyb() {
    singleton = singleton->GetInstance();
}

ReadFromKeyb::~ReadFromKeyb()
{

}

void ReadFromKeyb::CommRead(Field* Fld, Player* Plr, std::vector<Enemy*>& Enemies, int key)
{
    command = nullptr;
    if (key == down)
    {
        command = new MoveDown();
    }

    if (key == up)
    {
        command = new MoveUp();
    }

    if (key == left)
    {
        command = new MoveLeft();
    }

    if (key == right)
    {
        command = new MoveRight();
    }

    if (key == kick) {
        command = new Kick();
    }

    if (command) {
        command->execute(Plr, Fld, Enemies);
        delete command;
    }  
}

void ReadFromKeyb::LoggingRead(int key)
{
    if (key == log_to_file) {
        if (singleton->GetFileLog()) {
            singleton->SetFileLog(false);
        }
        else {
            singleton->SetFileLog(false);
        }
    }

    if (key == log_to_console) {
        if (singleton->GetConsoleLog()) {
            singleton->SetConsoleLog(false);
        }
        else {
            singleton->SetConsoleLog(true);
        }
    }

    if (key == first_level) {
        if (singleton->GetLevel1()) {
            singleton->SetLevel1(false);
        }
        else {
            singleton->SetLevel1(true);
        }
    }

    if (key == second_level) {
        if (singleton->GetLevel2()) {
            singleton->SetLevel2(false);
        }
        else {
            singleton->SetLevel2(true);
        }
    }

    if (key == third_level) {
        if (singleton->GetLevel3()) {
            singleton->SetLevel3(false);
        }
        else {
            singleton->SetLevel3(true);
        }
    }
}
