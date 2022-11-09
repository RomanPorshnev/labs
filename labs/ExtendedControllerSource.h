#pragma once
#include <string>
class ExtendedControllerSource
{
public:
	int virtual execute() = 0;
protected:
	std::string buff_controller;
};

