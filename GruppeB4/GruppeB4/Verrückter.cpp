#include "Verr�ckter.h"
#include "Resourcemanager.h"

using namespace std;



void Crazy_enemy::update(){
	if(this->get_Position()->i_x <= p_S_SafePosition->i_x && this->get_Position()->i_y <= p_S_SafePosition->i_y)
	{

	this->set_Velocity(0,2);
	}
	else if(this->get_Position()->i_x <= p_S_SafePosition->i_x && this->get_Position()->i_y >= p_S_SafePosition->i_y + 284 )
	{
		this->set_Velocity(2,0);
	}
	else if(this->get_Position()->i_x >= p_S_SafePosition->i_x + 397  && this->get_Position()->i_y >= p_S_SafePosition->i_y + 284)
	{
		this->set_Velocity(0,-2);
	}
	else if(this->get_Position()->i_x >= p_S_SafePosition->i_x + 397 && this->get_Position()->i_y <= p_S_SafePosition->i_y)
	{
		this->set_Velocity(-2,0);
	}


	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
}



void Crazy_enemy::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Verr�ckter"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerDownClips[0]);
} 



