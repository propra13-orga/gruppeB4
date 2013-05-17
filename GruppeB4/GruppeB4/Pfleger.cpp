#include "Pfleger.h"

void Pfleger_H::update()
{
	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
}

void Pfleger_H::render()
}	
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Pfleger"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}