#include "Singleton.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
Singleton* Singleton::GetInstance()
{
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

Singleton::~Singleton()
{
    delete instance;
}

void Singleton::logging(std::string log, int level_log)
{
    if (file) {
        if ((GetLevel1()) && (level_log == 1)) {
            list_logs_file.push_back(log);
        }
        if ((GetLevel2()) && (level_log == 2)) {
            list_logs_file.push_back(log);
        }
        if ((GetLevel3()) && (level_log == 3)) {
            list_logs_file.push_back(log);
        }
    }
    if (console) {
        if ((GetLevel1()) && (level_log == 1)) {
            list_logs_console.push_back(log);
        }
        if ((GetLevel2()) && (level_log == 2)) {
            list_logs_console.push_back(log);
        }
        if ((GetLevel3()) && (level_log == 3)) {
            list_logs_console.push_back(log);
        }
    }
}

bool Singleton::GetConsoleLog()
{
    if (this->console) {
        return true;
    }
    return false;
}

bool Singleton::GetFileLog()
{
    if (this->file) {
        return true;
    }
    return false;
}

void Singleton::SetConsoleLog(bool new_off_on)
{
    this->console = new_off_on;
}

void Singleton::SetFileLog(bool new_off_on)
{
    this->file = new_off_on;
}

bool Singleton::GetLevel1()
{
    if (this->level1) {
        return true;
    }
    return false;
}

bool Singleton::GetLevel2()
{
    if (this->level2) {
        return true;
    }
    return false;
}

Singleton* Singleton::instance = nullptr;

bool Singleton::GetLevel3()
{
    if (this->level3) {
        return true;
    }
    return false;
}

void Singleton::SetLevel1(bool new_level1)
{
    this->level1 = new_level1;
}

void Singleton::SetLevel2(bool new_level2)
{
    this->level2 = new_level2;
}

void Singleton::SetLevel3(bool new_level3)
{
    this->level3 = new_level3;
}

std::vector<std::string> Singleton::GetListLogsConsole()
{
    return list_logs_console;
}

std::vector<std::string> Singleton::GetListLogsFile()
{
    return list_logs_file;
}

Singleton::Singleton() 
{
    console = true;
    file = true;
    level1 = true;
    level2 = true;
    level3 = true;
}