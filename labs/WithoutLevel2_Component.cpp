#include "WithoutLevel2_Component.h"

std::string WithoutLevel2_Component::Operation(int type)
{
	switch (type)
	{
	case 1:
		return "The game started                    |\n";
	case 2:
		return "The game finished                   |\n";
	default:
		return "Error of logging\n";
		break;
	}
}
