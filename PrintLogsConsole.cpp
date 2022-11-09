#include "PrintLogsConsole.h"
std::ostream& operator<<(std::ostream& os, const std::vector<std::string> list_logs)
{   
    size_t buffer = 20;
    if (list_logs.size() > buffer) {
        for (size_t i = list_logs.size() - buffer; i < list_logs.size(); i++)
            os << list_logs[i];
    }
    else {
        for (int i = 0; i < list_logs.size(); i++)
            os << list_logs[i];
    }
    return os;
}
PrintLogsConsole::PrintLogsConsole()
{
    singleton = singleton->GetInstance();
}
void PrintLogsConsole::UpLine()
{
    for (int i = 0; i < 47; i++) {
        std::cout << '_';
    }
    std::cout << "\n";
}
void PrintLogsConsole::execute()
{
    if (singleton->GetConsoleLog()) {
        UpLine();
        list_logs = singleton->GetListLogsConsole();
        std::cout << list_logs;
    }
}

