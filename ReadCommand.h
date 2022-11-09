#pragma once
#include "Field.h"
#include "Enemy.h"
#include "Command.h"
#include "Singleton.h"
class ReadCommand
{
public:
	ReadCommand();
	~ReadCommand();
	void execute(Field*, Player*, std::vector<Enemy*>&, int);
	void GetCommands();
	void LoggingRead(int);
private:
	Command* command;
	Singleton* singleton;
	std::string buff_controller;
	std::string controller_list;
	int id;
	int up;
	int down;
	int left;
	int right;
	int kick;
};

