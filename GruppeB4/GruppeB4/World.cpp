#include "World.h"

void World::handle_Event(SDL_Event & even)
{
	p_Player1->handle_Input(even);
}

void World::update()
{
	p_Player1->update();
	if(collision_Detection() == true)
	{
		p_Player1->set_Position(p_Player1->get_Position()->i_x - p_Player1->get_Velocity()->i_x , p_Player1->get_Position()->i_y - p_Player1->get_Velocity()->i_y);
	}
}

void World::render(bool * tempmenue,Timer * deltaTime)
{
	
	BotManager->render();
	if( p_Princess->render(tempmenue,p_Player1) == false)
	{
	p_Player1->render(tempmenue,deltaTime);
	}
	apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("trans"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}
