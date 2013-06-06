#include "ItemManager.h"

void ItemManager::render(SDL_Rect camera)
{
	for(list<Item>::iterator it = this->uncatcheditems.begin();it != this->uncatcheditems.end(); ++it)
	{
		if( it->get_Item() == HEAL)
		{
			apply_Image(it->get_Position()->i_x - camera.x,it->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Heiltrank"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else
		{
			return;
		}
	}

}
void ItemManager::update(s_Vector * p_TempPosition)
{
	
   for(list<Item>::iterator it = this->uncatcheditems.begin();it != this->uncatcheditems.end(); ++it)
	{
		if(it->get_Position()->i_x - p_TempPosition->i_x <= 25 && it->get_Position()->i_x - p_TempPosition->i_x >= -25  && it->get_Position()->i_y - p_TempPosition->i_y <= 25 && it->get_Position()->i_y - p_TempPosition->i_y >= -25)
		{
			this->chatcheditems.push_back(Item(0,0,it->get_Item()));
			uncatcheditems.erase(it);
			this->anzeigen();
			break;
		}
	} 
}

void ItemManager::anzeigen()
{
	for(list<Item>::iterator at = this->chatcheditems.begin();at != this->chatcheditems.end();++at)
	{
		if(at->get_Item() == HEAL)
		{
			cout << "Heiltrank" << endl;
		}
	}
}