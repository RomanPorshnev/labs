#include "ReadCommand.h"
#include "MoveDown.h"
#include "MoveUp.h"
#include "MoveLeft.h"
#include "MoveRight.h"
#include "Kick.h"
#include <iostream>
#include <Windows.h>
#include <fstream>


#define log_to_file 102
#define log_to_console 99
#define first_level 49
#define second_level 50
#define third_level 51

ReadCommand::ReadCommand() {
    GetCommands();
    up = controller_list[0];
    down = controller_list[1];
    left = controller_list[2];
    right = controller_list[3];
    kick = controller_list[4];
    singleton = singleton->GetInstance();
    command = nullptr;
}

ReadCommand::~ReadCommand()
{
    singleton = nullptr;
    delete singleton;
}

void ReadCommand::execute(Field* Fld, Player* Plr, std::vector<Enemy*>& Enemies, int key)
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
    }
    delete command;
}

void ReadCommand::GetCommands()
{
    std::ifstream fin("CommandList.txt");
    while (std::getline(fin, buff_controller)) {
        for (int i = 0; i < buff_controller.size(); i++)
            if (buff_controller[i] == '=') {
                id = i;
                break;
            }
        controller_list.push_back(buff_controller[id + 1]);
    }
    fin.close();
}

void ReadCommand::LoggingRead(int key)
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
