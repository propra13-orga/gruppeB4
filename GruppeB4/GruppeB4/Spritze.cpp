#include "Spritze.h"

void Spritze::update()
{
	if (this->isactive == true)
	{
		this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x,this->get_Position()->i_y + this->get_Velocity()->i_y);
		//cout << "x: " << this->get_Position()->i_x << "               " << "y: " << this->get_Position()->i_y;
	}
	else
	{
		this->isactive = true;
	}
}

void Spritze::render(SDL_Rect camera)
{
	if(this->isactive == true)
	{
	apply_Image(this->get_Position()->i_x - camera.x ,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Spritze"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
}