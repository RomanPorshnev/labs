#pragma once
#include <vector>
#include "Cell.h"
#include <iostream>
#include "Field.h"
#include "Enemy.h"
#include <fstream>
#include "Singleton.h"
#include "Component.h"
#include "PrintLogs.h"
class InputOutput
{
public:
    InputOutput(int m = 20, int n = 40);
    ~InputOutput();
    void Asking();
    int AskControllerSource();
    bool CheckingForCorrectness(std::string, int&, int);
    void Print(Field*, Player*);
    void info();
    int GetM();
    int GetN();
    void PrintLogsToConsole();
    void PrintLogsToFile();
private:
    char c;
    std::vector<std::string> list_logs;
    int m;
    int n;
    std::vector<std::vector<Cell>> matrix;
    std::vector<Enemy*> Enemies;
    Singleton* singleton;
    enum log_level3 {Error_Init = 1, Error_Maxvalue};
    enum levels_log { FirstLevel = 1, SecondLevel, ThirdLevel };
    Component* woutlevel3;
    Component* log_level3;
    PrintLogs* PrLogsFile;
    PrintLogs* PrLogsConsole;
    enum SourceController{Terminal = 1, File = 2};
};

