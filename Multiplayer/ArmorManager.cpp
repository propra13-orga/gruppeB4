#include "ArmorManager.h"


void ArmorManager::render(SDL_Rect camera) ///<Rendert die nicht aufgehobenen Ruestungen
{
	for(list<Armor>::iterator it = this->uncatchedarmors.begin();it != this->uncatchedarmors.end(); ++it)
	{
		
	
		apply_Image(it->get_Position()->i_x - camera.x,it->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("weak"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		
	}

}




void ArmorManager::update(s_Vector * p_TempPosition)///<Ueberprueft und verwaltet die Ruestungsaufnahme
{
	
   for(list<Armor>::iterator it = this->uncatchedarmors.begin();it != this->uncatchedarmors.end(); ++it)
	{
		if(it->get_Position()->i_x - p_TempPosition->i_x <= 30 && it->get_Position()->i_x - p_TempPosition->i_x >= -30  && it->get_Position()->i_y - p_TempPosition->i_y <= 30 && it->get_Position()->i_y - p_TempPosition->i_y >= -30)
		{
			this->catchedarmors.push_back(Armor(0,0,it->get_Armor()));
			EPManager::get_EPManager().Set_Ep(10);
			uncatchedarmors.erase(it);
			this->show();
			break;
		}
	} 
}






ARMOR_TYPE ArmorManager::get_Armor(){ ///<zieht die benoetigte Ruestung aus der Liste der aufgehobene Ruestungen


	for(list<Armor>::iterator myIter = catchedarmors.begin();myIter != catchedarmors.end();myIter++)
	{
		if(myIter->get_Armor() == WEAK)
		{
			return WEAK;
		}
	}


}