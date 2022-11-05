#include "DecoratorLevel1.h"

DecoratorLevel1::DecoratorLevel1(Component* component) : DecoratorMessage(component)
{
}

std::string DecoratorLevel1::Operation(int type)
{
	return "[LEVEL 1] " + DecoratorMessage::Operation(type);
}
