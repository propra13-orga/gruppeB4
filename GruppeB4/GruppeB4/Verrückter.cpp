#include "Verrückter.h"
#include "Resourcemanager.h"

using namespace std;



void Crazy_enemy::update(){
	if(this->get_Position()->i_x <= 1035 && this->get_Position()->i_y <= 731)
	{

	this->set_Velocity(0,2);
	}
	else if(this->get_Position()->i_x <= 1035 && this->get_Position()->i_y >= 1015)
	{
		this->set_Velocity(2,0);
	}
	else if(this->get_Position()->i_x >= 1432 && this->get_Position()->i_y >= 1015)
	{
		this->set_Velocity(0,-2);
	}
	else if(this->get_Position()->i_x >= 1432 && this->get_Position()->i_y <= 731)
	{
		this->set_Velocity(-2,0);
	}


	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
}



void Crazy_enemy::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Verrückter"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
} 



