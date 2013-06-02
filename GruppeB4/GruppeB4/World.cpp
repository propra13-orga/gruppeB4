#include "World.h"

void World::handle_Event(SDL_Event & even)
{
	p_Player1->handle_Input(even);
}

void World::update()
{
	BotManager->update(this->p_Player1);
	p_Player1->update();
	if(collision_Detection() == true)
	{
		p_Player1->set_Position(p_Player1->get_Position()->i_x - p_Player1->get_Velocity()->i_x , p_Player1->get_Position()->i_y - p_Player1->get_Velocity()->i_y);
	}
}

void World::render(bool * tempmenue,Timer * deltaTime)
{
	
	BotManager->render( Camera);
	if( p_Princess->render(tempmenue,p_Player1,Camera) == false)
	{
		//Abfrage der Health und Auf den BIldschirmbringen der Gehirne
		if(this->p_Player1->get_Health() >= 300)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else if (this->p_Player1->get_Health() >= 200 && this->p_Player1->get_Health() < 300)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else if (this->p_Player1->get_Health() >= 100 && this->p_Player1->get_Health() < 200)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		}
		else
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn4"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
	p_Player1->render(tempmenue,deltaTime,Camera);
	}
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