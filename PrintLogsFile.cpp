#include "PrintLogsFile.h"
std::ofstream& operator<<(std::ofstream& os, const std::vector<std::string> list_logs)
{
    for (int i = 0; i < list_logs.size(); i++)
        os << list_logs[i];
    return os;
}
PrintLogsFile::PrintLogsFile()
{
	singleton = singleton->GetInstance();
}

void PrintLogsFile::execute()
{
    if (singleton->GetFileLog()) {
        list_logs = singleton->GetListLogsFile();
        std::ofstream fout("logs.txt");
        fout << list_logs;
        fout.close();
    }
}
