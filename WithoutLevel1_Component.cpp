#include "WithoutLevel1_Component.h"

std::string WithoutLevel1_Component::Operation(int type)
{
	switch (type)
	{
	case 1:
		return "The player made a move to the down  |\n";
	case 2:
		return "The player made a move to the left  |\n";
		
	case 3:
		return "The player made a move to the right |\n";
		
	case 4:
		return "The player made a move to the up    |\n";
	case 5:
		return "The player got a health box         |\n";
	case 6:
		return "The player got ammo                 |\n";
	case 7:
		return "The player stepped on a bomb        |\n";
	case 8:
		return "The player hit the wall             |\n";
	case 9:
		return "The enemy has lost health           |\n";
	case 10:
		return "The player got score                |\n";
	case 11:
		return "The enemy died                      |\n";
	case 12:
		return "The player did not hit the opponent |\n";
	default:
		return "Error of logging                    |\n";
		break;
	}
}

