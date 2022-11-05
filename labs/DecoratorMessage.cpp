#include "DecoratorMessage.h"

DecoratorMessage::DecoratorMessage(Component* component) : component_(component)
{
}


std::string DecoratorMessage::Operation(int type)
{
	return this->component_->Operation(type);
}
