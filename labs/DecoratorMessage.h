#pragma once
#include <string>
#include "Component.h"
class DecoratorMessage : public Component
{
public:
	DecoratorMessage(Component*);
	std::string Operation(int type);
protected:
	Component* component_;
};

