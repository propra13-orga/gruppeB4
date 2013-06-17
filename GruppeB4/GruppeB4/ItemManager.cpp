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
			this->catcheditems.push_back(Item(0,0,it->get_Item()));
			uncatcheditems.erase(it);
			this->anzeigen();
			break;
		}
	} 
}

void ItemManager::anzeigen()
{
	for(list<Item>::iterator at = this->catcheditems.begin();at != this->catcheditems.end();++at)
	{
		if(at->get_Item() == HEAL)
		{
			cout << "Heiltrank" << endl;
			cout << "Gib mir Butter YEAHHHHHHHHHH BABY" << endl;
		}
	}
}

bool ItemManager::find(ITEM_TYPE  TEMPITEM)
{
	for(list<Item>::iterator myIter = this->catcheditems.begin();myIter != catcheditems.end();++myIter)
	{
		if(myIter->get_Item() == TEMPITEM)
		{
			return true;
		}
	}

}

void ItemManager::kill_Item(ITEM_TYPE TEMPITEM)
{
	for(list<Item>::iterator myIter = this->catcheditems.begin();myIter != catcheditems.end();++myIter)
	{
		if(myIter->get_Item() == TEMPITEM)
		{
			catcheditems.erase(myIter);
			break;
		}
	}
}

void ItemManager::set_Item(s_Vector * p_TempPosition, ITEM_TYPE TEMPITEM)
{

}

void ItemManager::set_Item(int x, int y, ITEM_TYPE TEMPITEM)
{
	this->uncatcheditems.push_back(Item(x,y,TEMPITEM));
}


void ItemManager::insert_item(ITEM_TYPE tempitem){
	if(tempitem == HEAL)
	{
		this->catcheditems.push_back(Item(0,0,HEAL));
	}


}