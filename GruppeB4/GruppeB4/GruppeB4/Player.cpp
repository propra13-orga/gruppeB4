#include "Player.h"

void Player::handle_input(SDL_Event &even)
{
	if(even.type == SDL_KEYDOWN)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_UP):this->set_Velocity(0,-2);PlayerIsWalkingUp = true;PlayerIsWalkingDown = false;PlayerIsWalkingRight = false;PlayerIsWalkingLeft = false;break;
		case(SDLK_DOWN):this->set_Velocity(0,2);PlayerIsWalkingUp = false;PlayerIsWalkingDown = true;PlayerIsWalkingRight = false;PlayerIsWalkingLeft = false;break;
		case(SDLK_RIGHT):this->set_Velocity(2,0);PlayerIsWalkingUp = false;PlayerIsWalkingDown = false;PlayerIsWalkingRight = true;PlayerIsWalkingLeft = false;break;
		case(SDLK_LEFT):this->set_Velocity(-2,0);PlayerIsWalkingUp = false;PlayerIsWalkingDown = false;PlayerIsWalkingRight = false;PlayerIsWalkingLeft = true;break;
		}
	}
	else if(even.type == SDL_KEYUP)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_UP):this->set_Velocity(0,0);break;
		case(SDLK_DOWN):this->set_Velocity(0,0);break;
		case(SDLK_RIGHT):this->set_Velocity(0,0);break;
		case(SDLK_LEFT):this->set_Velocity(0,0);break;
		}
	}
	if(PlayerIsWalkingUp == true)
	{
		cout << "Hoch" << endl;
	}
	else if(PlayerIsWalkingDown == true)
	{
		cout << "Runter" << endl;
	}
	else if(PlayerIsWalkingRight == true)
	{
		cout << "Rechts" << endl;
	}
	else if(PlayerIsWalkingLeft == true)
	{
		cout << "Links" << endl;
	}
}

void Player::update()
{
	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
	
}

void Player::render()
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}

bool Player::collision_Detection(LevelSegmente * p_TempSegment)
{
	//f�r den ersten Quadranten
	if(this->get_Position()->i_x <=710 && this->get_Position()->i_y >= 400)
	{
		if(this->get_Position()->i_x <= p_TempSegment->SegmentRect11[0].x)
		{
			return true;
		}
	}
}
