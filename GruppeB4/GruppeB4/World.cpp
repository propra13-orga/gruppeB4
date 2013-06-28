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
				if(even.key.keysym.sym == SDLK_n)			//wird e gedrückt geht der shop auf(später nur wenn npc in range ist)
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
	if(this->CURRENTLEVEL == LEVEL2)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&Camera);
	}
	if(this->CURRENTLEVEL == LEVEL3)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&Camera);
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
	AgentManager::get_AgentManager().set_Bot(1035,731,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(411,156,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(973,112,PFLEGER);
	ItemManager::get_ItemManager().set_Item(1027,702,HEAL);
	ItemManager::get_ItemManager().set_Item(1300,440,MANA);
	ArmorManager::get_ArmorManager().set_Armor(WEAK,500,1000);
	MoneyManager::get_MoneyManager().set_Coin(800,900);
	MoneyManager::get_MoneyManager().set_Coin(1760,765);
	MoneyManager::get_MoneyManager().set_Coin(1760,1025);
	MoneyManager::get_MoneyManager().set_Coin(1260,413);
	MoneyManager::get_MoneyManager().set_Coin(1260,542);
	MoneyManager::get_MoneyManager().set_Coin(1763,152);
	MoneyManager::get_MoneyManager().set_Coin(1140,436);
	MoneyManager::get_MoneyManager().set_Coin(1020,448);
	MoneyManager::get_MoneyManager().set_Coin(820,118);
	MoneyManager::get_MoneyManager().set_Coin(842,544);
	WeaponManager::get_WeaponManager().set_Weapon(400,400,MELEE);
	}
	else if(CURRENTLEVEL == LEVEL1 && LevelToSet == false)
	{
	AgentManager::get_AgentManager().set_Bot(1035,731,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(411,156,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(973,112,PFLEGER);
	ItemManager::get_ItemManager().set_Item(1027,702,HEAL);
	ItemManager::get_ItemManager().set_Item(1300,440,MANA);

	}
	else if(CURRENTLEVEL == LEVEL2 && LevelToSet == true)
	{
		AgentManager::get_AgentManager().set_Bot(1035,731,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(580,731,CRAZY_ENEMY);	
		AgentManager::get_AgentManager().set_Bot(300,731,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(575,760,PFLEGER);
		ItemManager::get_ItemManager().set_Item(202,624,HEAL);
		ItemManager::get_ItemManager().set_Item(998,276,MANA);
		MoneyManager::get_MoneyManager().set_Coin(1328,1139);
		MoneyManager::get_MoneyManager().set_Coin(1013,787);
		MoneyManager::get_MoneyManager().set_Coin(702,1158);
		MoneyManager::get_MoneyManager().set_Coin(85,817);
		MoneyManager::get_MoneyManager().set_Coin(71,1153);
		MoneyManager::get_MoneyManager().set_Coin(816,291);
		MoneyManager::get_MoneyManager().set_Coin(1152,642);
		MoneyManager::get_MoneyManager().set_Coin(1782,307);
        MoneyManager::get_MoneyManager().set_Coin(1328,1139);
		MoneyManager::get_MoneyManager().set_Coin(1328,1139);
		MoneyManager::get_MoneyManager().set_Coin(1328,1139);
		MoneyManager::get_MoneyManager().set_Coin(1328,1139);
		AgentManager::get_AgentManager().set_Bot(603,329,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(1010,329,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(1422,329,CRAZY_ENEMY);
	}
	else if (CURRENTLEVEL == LEVEL2 && LevelToSet == false)
	{
		AgentManager::get_AgentManager().set_Bot(1035,731,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(580,731,CRAZY_ENEMY);	
		AgentManager::get_AgentManager().set_Bot(300,731,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(575,760,PFLEGER);
		ItemManager::get_ItemManager().set_Item(202,624,HEAL);
		ItemManager::get_ItemManager().set_Item(998,276,MANA);
		AgentManager::get_AgentManager().set_Bot(603,329,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(1010,329,CRAZY_ENEMY);
		AgentManager::get_AgentManager().set_Bot(1422,329,CRAZY_ENEMY);
	}

	else if(CURRENTLEVEL == LEVEL3 && LevelToSet == true)
	{
	AgentManager::get_AgentManager().set_Bot(338,109,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(700,135,PFLEGER);
	AgentManager::get_AgentManager().set_Bot(820,135,PFLEGER);
	ItemManager::get_ItemManager().set_Item(1051,903,HEAL);
	ItemManager::get_ItemManager().set_Item(1910,1055,HEAL);
	ItemManager::get_ItemManager().set_Item(773,1100,MANA);
	MoneyManager::get_MoneyManager().set_Coin(610,484);
	MoneyManager::get_MoneyManager().set_Coin(1088,90);
	MoneyManager::get_MoneyManager().set_Coin(237,757);
	MoneyManager::get_MoneyManager().set_Coin(231,1119);
	MoneyManager::get_MoneyManager().set_Coin(1094,1062);
	MoneyManager::get_MoneyManager().set_Coin(1559,960);
	MoneyManager::get_MoneyManager().set_Coin(1559,880);
	MoneyManager::get_MoneyManager().set_Coin(1559,755);
		
	
	}
	else if (CURRENTLEVEL == LEVEL3 && LevelToSet == false)
	{
	AgentManager::get_AgentManager().set_Bot(338,109,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(719,135,PFLEGER);
	AgentManager::get_AgentManager().set_Bot(814,135,PFLEGER);
	ItemManager::get_ItemManager().set_Item(1051,903,HEAL);
	ItemManager::get_ItemManager().set_Item(1910,1055,HEAL);
	ItemManager::get_ItemManager().set_Item(773,1155,MANA);
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