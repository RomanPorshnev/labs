#include "WithoutLevel3_Component.h"

std::string WithoutLevel3_Component::Operation(int type)
{
	switch (type)
	{
	case 1:
		return "Field initialization error          |\n";
	case 2:
		return "Max value field initialization error|\n";
	default:
		return "Error of logging\n";
		break;
	}
}
