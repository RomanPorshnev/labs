#pragma once
#include <string>
#include <vector>
class Message
{
public:
	Message();
	std::string GetMessage(int);
private:
	std::vector<std::string> message_list;
};

