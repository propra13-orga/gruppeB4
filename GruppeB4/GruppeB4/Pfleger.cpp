#include "Pfleger.h"

void Pfleger::update()
{
}

void Pfleger::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Pfleger"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}