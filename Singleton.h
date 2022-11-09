#pragma once
#include "Message.h"
class Singleton
{	
public:
	Singleton(const Singleton& other) = delete;
	void operator = (const Singleton) = delete;
	static Singleton* GetInstance();
	~Singleton();
	void logging(std::string, int);
	bool GetConsoleLog();
	bool GetFileLog();
	void SetConsoleLog(bool);
	void SetFileLog(bool);
	bool GetLevel1();
	bool GetLevel2();
	bool GetLevel3();
	void SetLevel1(bool);
	void SetLevel2(bool);
	void SetLevel3(bool);
	std::vector<std::string> GetListLogsConsole();
	std::vector<std::string> GetListLogsFile();
private:
	std::vector<std::string> list_logs_console;
	std::vector<std::string> list_logs_file;
	static Singleton* instance;
	Singleton();
	bool console;
	bool file;
	bool level1;
	bool level2;
	bool level3;
};

