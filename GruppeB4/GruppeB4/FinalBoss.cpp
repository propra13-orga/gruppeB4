#include "FinalBoss.h"
#include "Player.h"







/*
apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		tempplayer->set_Health(100);
		tempplayer->set_Position(0,0);
		*tempmenue = true;
		*/




void FinalBoss::render(SDL_Rect  camera){
	

apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Prinzessin"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	



}

void FinalBoss::update(Player * p_Player)
{
	if(transformed == false)
	{
		p_Player->set_disable(true);
		AnimationTimer->start();
		while(AnimationTimer->Getticks() <= 3000)
		{
		
		}
		transformed = true;
		p_Player->set_disable(false);
	}
	else
	{
	if(this->p_s_StartPosition->i_x - this->p_s_Position->i_x >= 284)
	{
		this->p_s_Velocity->i_x = 2;
		this->p_s_Velocity->i_y = 0;
	}
	else if(this->p_s_StartPosition->i_x - this->p_s_Position->i_x <= -284)
	{
		this->p_s_Velocity->i_x = -2;
		this->p_s_Velocity->i_y = 0;
	}

	this->p_s_Position->i_x += p_s_Velocity->i_x;this->p_s_Position->i_y += this->p_s_Velocity->i_y;
	}
}