#include "Princess.h"






/*
apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		tempplayer->set_Health(100);
		tempplayer->set_Position(0,0);
		*tempmenue = true;
		*/




bool Princess::render(bool * tempmenue, Player * tempplayer){
	if(tempplayer->get_Position()->i_y >= 78 && tempplayer->get_Position()->i_y <= 448 && tempplayer->get_Position()->i_x <= 189)
	{
	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		tempplayer->set_Health(100);
		tempplayer->set_Position(0,0);
		*tempmenue = true;
		return true;
	}
	else
	{

apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Prinzessin"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"));
return false;
	}



}