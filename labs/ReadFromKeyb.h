#pragma once
#include "Field.h"
#include "Enemy.h"
#include "Command.h"
#include "Singleton.h"
class ReadFromKeyb
{
public:
	ReadFromKeyb();
	~ReadFromKeyb();
	void CommRead(Field*, Player*, std::vector<Enemy*>&, int);
	void LoggingRead(int);
private:
	Command* command;
	Singleton* singleton;
};

