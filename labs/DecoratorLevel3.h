#pragma once
#include "Component.h"
#include "DecoratorMessage.h"
class DecoratorLevel3 : public DecoratorMessage
{
public:
	DecoratorLevel3(Component*);
	std::string Operation(int type);
};

