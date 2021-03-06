#include "WeaponManager.h"


void WeaponManager::render(SDL_Rect camera)
{
	for(list<Weapon>::iterator it = this->uncatchedweapons.begin();it != this->uncatchedweapons.end(); ++it)
	{
		if( it->get_Weapon() == MELEE)
		{
			
			apply_Image(it->get_Position()->i_x - camera.x,it->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Elektrode"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
			else
		{
				return;
		}
	}

}




void WeaponManager::update(s_Vector * p_TempPosition)
{
	
   for(list<Weapon>::iterator it = this->uncatchedweapons.begin();it != this->uncatchedweapons.end(); ++it)
	{
		if(it->get_Position()->i_x - p_TempPosition->i_x <= 30 && it->get_Position()->i_x - p_TempPosition->i_x >= -30  && it->get_Position()->i_y - p_TempPosition->i_y <= 30 && it->get_Position()->i_y - p_TempPosition->i_y >= -30)
		{
			this->catchedweapons.push_back(Weapon(0,0,it->get_Weapon()));
			EPManager::get_EPManager().Set_Ep(10);
			cout << "Ich bin hier" << endl;
			uncatchedweapons.erase(it);
			this->show();
			break;
		}
	} 
}

void WeaponManager::show()
{
	for(list<Weapon>::iterator it = this->catchedweapons.begin();it != this->catchedweapons.end();++it)
	{
		if(it->get_Weapon() == MELEE)
		{
			cout << "ELEKTRODE AUFGEHOBEN!" << endl;
			cout << "AWAHWHAHHHHHHAHAHAHAH" << endl;
		}
	}
}




void WeaponManager::swap_weapon()
{
	if(CURRENT_WEAPON2 == NONE)
	{
		
		for(list<Weapon>::iterator it = this->catchedweapons.begin();it != this->catchedweapons.end();++it)
		{
			if(it->get_Weapon() == MELEE)
			{
				this->CURRENT_WEAPON2 = MELEE;
			}
		
		}
	}
	else if(CURRENT_WEAPON2 == MELEE)
	{
	
		this->CURRENT_WEAPON2 = NONE;
	}
}

void WeaponManager::set_Weapon(int x, int y, WEAPON_TYPE TEMPWEAPON)
{
	this->uncatchedweapons.push_back(Weapon(x,y,TEMPWEAPON));
}
