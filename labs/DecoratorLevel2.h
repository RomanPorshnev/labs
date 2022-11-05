#pragma once
#include "Component.h"
#include "DecoratorMessage.h"
class DecoratorLevel2 : public DecoratorMessage
{
public:
	DecoratorLevel2(Component*);
	std::string Operation(int type);
};

