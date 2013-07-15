#include "World.h"

void World::handle_Event(SDL_Event & even)
{
	p_Player1->handle_Input(even);
}


void World::openSkilltree(){

	Skilltree::get_Skilltree().render(even);

}
void World::update()
{
	this->try_swapLevel();

	if(this->LevelToSet == true)
	{
		this->initialize_Level();
		LevelToSet = false;
	}
	AgentManager::get_AgentManager().update(this->p_Player1,CURRENTLEVEL,Camera);
	p_Player1->update();
	ItemManager::get_ItemManager().update(this->p_Player1->get_Position());
	WeaponManager::get_WeaponManager().update(this->p_Player1->get_Position());
	MoneyManager::get_MoneyManager().update(this->p_Player1->get_Position());
	ArmorManager::get_ArmorManager().update(this->p_Player1->get_Position());
	

	
	if(collision_Detection() == true)
	{
		p_Player1->set_Position(p_Player1->get_Position()->i_x - p_Player1->get_Velocity()->i_x , p_Player1->get_Position()->i_y - p_Player1->get_Velocity()->i_y);
	}

	if(even.type == SDL_KEYDOWN)
			{
				if(even.key.keysym.sym == SDLK_n)			//wird e gedrueckt geht der shop auf(spaeter nur wenn npc in range ist)
				{
					World::openSkilltree();
				}
}

}





void World::render(bool * tempmenue,Timer * deltaTime)
{
	if(this->CURRENTLEVEL == LEVEL1)
	{
	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&Camera);
	}

	AgentManager::get_AgentManager().render( Camera,CURRENTLEVEL);
	MoneyManager::get_MoneyManager().render(Camera);
	ItemManager::get_ItemManager().render(Camera);
	ArmorManager::get_ArmorManager().render(Camera);
	WeaponManager::get_WeaponManager().render(Camera);
	NPC1::get_NPC1().render(Camera);
	
	p_Player1->render(tempmenue,deltaTime,Camera,CURRENTLEVEL,this);
	if(NPC1::get_NPC1().PlayCloseToBot(this->get_Player()) == true)
	{
		apply_Image(0,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("Aufforderung_e"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	

	Overlay::get_Instance().render(this->p_Player1);

	
	
}







void World::render_Win(bool * tempmenue)
{
	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	SDL_Delay(5000);
	*tempmenue = true;
}


void World::set_Camera()
{
	Camera.x = ( this->p_Player1->get_Position()->i_x + PLAYER_WIDTH/ 2 ) - 900 / 2; Camera.y = ( this->p_Player1->get_Position()->i_y + PLAYER_HEIGHT / 2 ) - 600 / 2;
	 //Keep the camera in bounds. 
	 if( Camera.x < 0 )
	 { Camera.x = 0; } 
	 if( Camera.y < 0 ) 
	 { Camera.y = 0; } 
	 if( Camera.x > 2000 - Camera.w )
	 { Camera.x = 2000 - Camera.w; } 
	 if( Camera.y > 1280 - Camera.h ) 
	 { Camera.y = 1280 - Camera.h; } 
}

void World::initialize_Level()
{
	if (CURRENTLEVEL == LEVEL1 && LevelToSet == true)
	{
	
	}
	
	
}


void World::try_swapLevel()
{
		if(CURRENTLEVEL == LEVEL1)
		{
			if(this->get_Player()->get_Position()->i_x <= 400 && this->get_Player()->get_Position()->i_y <= 1000)
			{
			CURRENTLEVEL = LEVEL2;
			LevelToSet = true;
			AgentManager::get_AgentManager().reinitialize();
			MoneyManager::get_MoneyManager().reinitialize();
			ItemManager::get_ItemManager().reinitializeLevelSwap();
			WeaponManager::get_WeaponManager().reinitializeLevelSwap();
			this->p_Player1->set_Position(1800,960);
			}
		}
		if(CURRENTLEVEL == LEVEL2)
		{
			if(this->get_Player()->get_Position()->i_x >= 1800 && this->get_Player()->get_Position()->i_y <= 800)
			{
				CURRENTLEVEL = LEVEL3;
				LevelToSet = true;
			AgentManager::get_AgentManager().reinitialize();
			MoneyManager::get_MoneyManager().reinitialize();
			ItemManager::get_ItemManager().reinitializeLevelSwap();
			WeaponManager::get_WeaponManager().reinitializeLevelSwap();
			this->p_Player1->set_Position(80,250);
			}
		}
		
	
}