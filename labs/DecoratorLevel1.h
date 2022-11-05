#pragma once
#include "Component.h"
#include "DecoratorMessage.h"
class DecoratorLevel1 : public DecoratorMessage
{
public:
	DecoratorLevel1(Component*);
	std::string Operation(int type);
};

