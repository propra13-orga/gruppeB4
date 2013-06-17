#include "World.h"

void World::handle_Event(SDL_Event & even)
{
	p_Player1->handle_Input(even);
}

void World::update()
{
	if(this->LevelToSet == true)
	{
		this->initialize_Level();
		LevelToSet = false;
	}
	AgentManager::get_AgentManager().update(this->p_Player1);
	p_Player1->update();
	ItemManager::get_ItemManager().update(this->p_Player1->get_Position());
	WeaponManager::get_WeaponManager().update(this->p_Player1->get_Position());
	MoneyManager::get_MoneyManager().update(this->p_Player1->get_Position());
	
	if(collision_Detection() == true)
	{
		p_Player1->set_Position(p_Player1->get_Position()->i_x - p_Player1->get_Velocity()->i_x , p_Player1->get_Position()->i_y - p_Player1->get_Velocity()->i_y);
	}
}

void World::render(bool * tempmenue,Timer * deltaTime)
{
	AgentManager::get_AgentManager().render( Camera);
	MoneyManager::get_MoneyManager().render(Camera);
	ItemManager::get_ItemManager().render(Camera);
	WeaponManager::get_WeaponManager().render(Camera);
	if( p_BossManager->render(p_Player1,Camera) == false)
	{
		p_Player1->render(tempmenue,deltaTime,Camera,CURRENTLEVEL);
		apply_Image(71 - this->get_Camera().x,67 - this->get_Camera().y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Transthron"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		Overlay::get_Instance().render(this->p_Player1);
	}
	else
	{
		this->render_Win(tempmenue);
		this->p_Player1->reinitialize(this->CURRENTLEVEL);
	}
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
	if (CURRENTLEVEL == LEVEL1)
	{
	AgentManager::get_AgentManager().set_Bot(1035,731,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(411,156,CRAZY_ENEMY);
	AgentManager::get_AgentManager().set_Bot(973,112,PFLEGER);
	ItemManager::get_ItemManager().set_Item(1027,702,HEAL);
	MoneyManager::get_MoneyManager().set_Coin(800,900);
	MoneyManager::get_MoneyManager().set_Coin(1760,765);
	MoneyManager::get_MoneyManager().set_Coin(1760,1025);
	MoneyManager::get_MoneyManager().set_Coin(1260,413);
	MoneyManager::get_MoneyManager().set_Coin(1260,542);
	MoneyManager::get_MoneyManager().set_Coin(1807,116);
	MoneyManager::get_MoneyManager().set_Coin(1172,443);
	MoneyManager::get_MoneyManager().set_Coin(1020,448);
	MoneyManager::get_MoneyManager().set_Coin(820,118);
	MoneyManager::get_MoneyManager().set_Coin(842,544);
	WeaponManager::get_WeaponManager().set_Weapon(400,400,MELEE);
	}
}