b#include "Endboss.h"
#include "Resourcmanager"


using namespace std;

void Endboss::update(){

	else if(this->get_Position()->i_x <= p_S_SafePosition->i_x && this->get_Position()->i_y >= p_S_SafePosition->i_y + 284 )
	{
		this->set_Velocity(2,0);
		WALK_STATUS = PSY_RIGHT;
	}

	else if(this->get_Position()->i_x >= p_S_SafePosition->i_x + 397 && this->get_Position()->i_y <= p_S_SafePosition->i_y)
	{
		this->set_Velocity(-2,0);
		WALK_STATUS = PSY_LEFT;
	}


	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
}

void Endboss::render(SDL_Rect camera)
{
	if(this->AnimationTimer->Getticks() >= 100)
	{
		frames++;
		this->AnimationTimer->start();
	}
	else
	{
	}
	if(frames >= 5)
	{
		frames = 0;
	}

	
	if(WALK_STATUS == PSY_RIGHT)
	{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Endboss_Right"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerRightClips[frames]);
	}
	if(WALK_STATUS == PSY_LEFT)
	{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Endboss_Left"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerLeftClips[frames]);
	}
} 