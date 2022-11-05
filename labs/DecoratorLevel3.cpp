#include "DecoratorLevel3.h"

DecoratorLevel3::DecoratorLevel3(Component* component) : DecoratorMessage(component)
{
}

std::string DecoratorLevel3::Operation(int type)
{
	return "[LEVEL 3] " + DecoratorMessage::Operation(type);
}
