#pragma once
#include "PrintLogs.h"
class PrintLogsConsole : public PrintLogs
{
public:
	PrintLogsConsole();
	void UpLine();
	void execute();
};

