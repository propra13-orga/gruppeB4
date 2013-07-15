#include "Pfleger.h"

void Pfleger::update(Player * p_TempPosition)
{
	this->p_Spritze->update();
	if(p_Spritze->get_Position()->i_x - p_TempPosition->get_Position()->i_x  <= 20 && p_Spritze->get_Position()->i_x - p_TempPosition->get_Position()->i_x >= -20  && p_Spritze->get_Position()->i_y - p_TempPosition->get_Position()->i_y  <= 20 && p_Spritze->get_Position()->i_y - p_TempPosition->get_Position()->i_y >= -20)
	{
		p_Spritze->set_Position(p_Spritze->get_StartPosition()->i_x,p_Spritze->get_StartPosition()->i_y);
		p_TempPosition->set_Health(p_TempPosition->get_Health() - 200);
	}
	if(p_Spritze->get_Position()->i_y - p_Spritze->get_StartPosition()->i_y >= 350)
	{
		p_Spritze->set_Position(p_Spritze->get_StartPosition()->i_x,p_Spritze->get_StartPosition()->i_y);
	}

}

void Pfleger::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Pfleger"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	this->p_Spritze->render(camera);
}


