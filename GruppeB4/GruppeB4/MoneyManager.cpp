#include "MoneyManager.h"

void MoneyManager::render(SDL_Rect camera)
{
	for(list<RenableObject>::iterator myIter = uncatchedmoney.begin();myIter != uncatchedmoney.end();++myIter)
	{
		apply_Image(myIter->get_Position()->i_x - camera.x,myIter->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Pille"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
}

void MoneyManager::update(s_Vector * p_TempPosition)
{
	for(list<RenableObject>::iterator myIter = uncatchedmoney.begin();myIter != uncatchedmoney.end();++myIter)
	{
		if(myIter->get_Position()->i_x - p_TempPosition->i_x <= 25 && myIter->get_Position()->i_x - p_TempPosition->i_x >= -25  && myIter->get_Position()->i_y - p_TempPosition->i_y <= 25 && myIter->get_Position()->i_y - p_TempPosition->i_y >= -25)
		{
			money++;
			uncatchedmoney.erase(myIter);
			break;
		}
	}
}




int MoneyManager::refreshMoney(int  i_bill){


	money = money -i_bill ;

	return money;
}

void MoneyManager::set_Coin(int x, int y)
{
	this->uncatchedmoney.push_back(RenableObject(x,y,MONEY));
}