#pragma once
#include "ExtendedControllerSource.h"
class ExtendedControllerFile : public ExtendedControllerSource
{
public:
	ExtendedControllerFile();
	int execute();
private:
	int id;
};

