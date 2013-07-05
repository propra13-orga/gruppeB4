#include<iostream>
#include<string>
#include "NPC2.h"
#include "Player.h"

using namespace std;

void NPC2::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("npc2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
} 

bool NPC2::PlayCloseToBot(Player * p_TempPlayer)
{
	if(p_TempPlayer->get_Position()->i_x - this->get_Position()->i_x <= 50 && p_TempPlayer->get_Position()->i_x - this->get_Position()->i_x >= -50 && p_TempPlayer->get_Position()->i_y - this->get_Position()->i_y <= 50 && p_TempPlayer->get_Position()->i_y - this->get_Position()->i_y >= -50)
	{
		return true;
	}
	return false;
}



