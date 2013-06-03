#include "FinalBoss.h"






/*
apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		tempplayer->set_Health(100);
		tempplayer->set_Position(0,0);
		*tempmenue = true;
		*/




bool FinalBoss::render(bool * tempmenue, Player * tempplayer,SDL_Rect camera){
	if(tempplayer->get_Position()->i_y >= 78 && tempplayer->get_Position()->i_y <= 448 && tempplayer->get_Position()->i_x <= 189)
	{
		return true;
		//Gib an die Welt nur true zurück der rest muss in der welt gemacht werden -> reinitialize Player und render_Win
	}
	else
	{

apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Prinzessin"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
return false;
	}



}