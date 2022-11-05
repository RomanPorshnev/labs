#include "Message.h"

Message::Message()
{
	message_list.push_back("[Level 1] The player made a move to the down\n");
	message_list.push_back("[Level 1] The player got a health box\n");
	message_list.push_back("[Level 1] The player got ammo\n");
	message_list.push_back("[Level 1] The player stepped on a bomb\n");
	message_list.push_back("[Level 1] The player hit the wall\n");
	message_list.push_back("[Level 1] The player made a move to the left\n");
	message_list.push_back("[Level 1] The player made a move to the right\n");
	message_list.push_back("[Level 1] The player made a move to the up\n");
	message_list.push_back("[Level 1] The enemy has lost health\n");
	message_list.push_back("[Level 1] The player got score\n");
	message_list.push_back("[Level 1] The enemy died\n");
	message_list.push_back("[Level 1] The player did not hit the opponent\n");
	message_list.push_back("[Level 2] The game started\n");
	message_list.push_back("[Level 2] The game finished\n");
	message_list.push_back("[Level 3] Field initialization error\n");
}

std::string Message::GetMessage(int key)
{
	return message_list[key - 1];
}
