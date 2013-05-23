#include "World.h"

void World::handle_event(SDL_Event & even)
{
	p_Player1->handle_input(even);
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
	
	p_Crazy_Enemy->render();
	p_Crazy_Enemy2->render();
	bool check = p_Princess->render(tempmenue,p_Player1);
	if(check == false)
	{
	p_Player1->render(tempmenue,deltaTime);
	}
}
