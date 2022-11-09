#pragma once
#include "Player.h"
#include "Field.h"
#include "Enemy.h"
#include "Singleton.h"
#include "Component.h"
#include "PrintLogs.h"
#include "ExtendedControllerSource.h"
#include "FieldGenerators.h"
#include "InputOutput.h"
#include "ReadCommand.h"
class Frames
{
public:
	Frames();
	~Frames();
	void Update(Field*, Player*, std::vector<Enemy*>);

private:
	clock_t start;
	clock_t end;
	ReadCommand ReadComm;
	InputOutput InOut;
	Singleton* singleton;
	enum log_level2 { GameStart = 1, GameEnd };
	enum levels_log { FirstLevel = 1, SecondLevel, ThirdLevel };
	bool CheckEnemies(std::vector<Enemy*> Enemies);
	std::vector<std::vector<Cell>> TempMatrix;
	std::vector<Enemy*> Enemies;
	Component* woutlevel2;
	Component* log_level2;
	PrintLogs* PrLogsConsole;
	PrintLogs* PrLogsFile;
	enum SourceController { Terminal = 1, File };
	int source;
	int key;
	int key_file;
	ExtendedControllerSource* controller_source;
	FieldGenerators FldGen;
};
