#include "DecoratorLevel2.h"
#include <Windows.h>
#include <iostream>
DecoratorLevel2::DecoratorLevel2(Component* component) : DecoratorMessage(component)
{
}

std::string DecoratorLevel2::Operation(int type)
{
	return "[LEVEL 2] " + DecoratorMessage::Operation(type);
}
