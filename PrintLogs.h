#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Singleton.h"
class PrintLogs
{
public:
	virtual void execute() = 0;
protected:
	std::vector<std::string> list_logs;
	Singleton* singleton;
	//void UpLine();
};
