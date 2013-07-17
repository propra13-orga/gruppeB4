#include "S_CollisionManager.h"

bool MultiplayerHighClass::S_CollisionManager::collisionOfTwoPlayerLocal(MultiplayerLowClass::Player * tempPlayer1)
{
	for(list<C_Block>::iterator myIter = S_CollisibalObjectManager::get_CManager().get_BlockList().begin();myIter != S_CollisibalObjectManager::get_CManager().get_BlockList().end();++myIter)
	{
		//oben
		if(tempPlayer1->get_Position()->X <= myIter->get_Position()->X && tempPlayer1->get_Position()->X + 60 >= myIter->get_Position()->X && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y)
		{
			return true;
		}
		else if(tempPlayer1->get_Position()->X <= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->X + 60 >= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y)
		{
			return true;
		}
		else if(tempPlayer1->get_Position()->X >= myIter->get_Position()->X && tempPlayer1->get_Position()->X + 60 <= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y)
		{
			return true;
		}
		//unten
		else if(tempPlayer1->get_Position()->X <= myIter->get_Position()->X && tempPlayer1->get_Position()->X + 60 >= myIter->get_Position()->X && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y + 100 && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y + 100)
		{
			return true;
		}
		else if(tempPlayer1->get_Position()->X >= myIter->get_Position()->X && tempPlayer1->get_Position()->X + 60 <= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y + 100 && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y + 100)
		{
			return true;
		}
		else if(tempPlayer1->get_Position()->X >= myIter->get_Position()->X && tempPlayer1->get_Position()->X  <= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->Y <= myIter->get_Position()->Y + 100 && tempPlayer1->get_Position()->Y + 60 >= myIter->get_Position()->Y + 100)
		{
			return true;
		}
		//seite
		else if(tempPlayer1->get_Position()->X <= myIter->get_Position()->X && tempPlayer1->get_Position()->X + 60 >= myIter->get_Position()->X && tempPlayer1->get_Position()->Y >= myIter->get_Position()->Y && tempPlayer1->get_Position()->Y + 60 <= myIter->get_Position()->Y + 100)
		{
			return true;
		}
		else if(tempPlayer1->get_Position()->X >= myIter->get_Position()->X && tempPlayer1->get_Position()->X <= myIter->get_Position()->X + 100 && tempPlayer1->get_Position()->Y >= myIter->get_Position()->Y && tempPlayer1->get_Position()->Y + 60 <= myIter->get_Position()->Y + 100)
		{
			return true;
		}

	}

}