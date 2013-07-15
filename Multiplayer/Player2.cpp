#include "Player2.h"

void Player2::handle_input(SDL_Event &even)
{
	if(even.type == SDL_KEYDOWN)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_w):this->set_Velocity(0,-2);Player2IsWalkingUp = true;Player2IsWalkingDown = false;Player2IsWalkingRight = false;Player2IsWalkingLeft = false;break;
		case(SDLK_s):this->set_Velocity(0,2);Player2IsWalkingUp = false;Player2IsWalkingDown = true;Player2IsWalkingRight = false;Player2IsWalkingLeft = false;break;
		case(SDLK_d):this->set_Velocity(2,0);Player2IsWalkingUp = false;Player2IsWalkingDown = false;Player2IsWalkingRight = true;Player2IsWalkingLeft = false;break;
		case(SDLK_a):this->set_Velocity(-2,0);Player2IsWalkingUp = false;Player2IsWalkingDown = false;Player2IsWalkingRight = false;Player2IsWalkingLeft = true;break;
		}
	}
	else if(even.type == SDL_KEYUP)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_w):this->set_Velocity(0,0);break;
		case(SDLK_s):this->set_Velocity(0,0);break;
		case(SDLK_d):this->set_Velocity(0,0);break;
		case(SDLK_a):this->set_Velocity(0,0);break;
		}
	}
	if(Player2IsWalkingUp == true)
	{
		cout << "Hoch Player2" << endl;
	}
	else if(Player2IsWalkingDown == true)
	{
		cout << "Runter Player2" << endl;
	}
	else if(Player2IsWalkingRight == true)
	{
		cout << "Rechts Player2" << endl;
	}
	else if(Player2IsWalkingLeft == true)
	{
		cout << "Links Player2" << endl;
	}
}

void Player2::update()
{
	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
	
}

void Player2::render()
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}

bool Player2::collision_Detection(LevelSegmente * p_TempSegment)
{
	//für den ersten Quadranten
	if(this->get_Position()->i_x <=710 && this->get_Position()->i_y >= 400)
	{
		cout << "Quadrant eins geladen" << endl;
		if(this->get_Position()->i_x <= p_TempSegment->SegmentRect11[0].x)
		{
			return true;
		}
		else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect11[0].y)
		{
			return true;
		}
		else if(this->get_Position()->i_y >= (p_TempSegment->SegmentRect11[0].y + 173 - PLAYER_HEIGHT))
		{
			return true;
		}
		else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect11[0].x + p_TempSegment->SegmentRect11[0].w - PLAYER_HEIGHT && this->get_Position()->i_y <= p_TempSegment->SegmentRect11[1].y)
		{
			return true;
		}
	}
	if(this->get_Position()->i_x > 710 && this->get_Position()->i_y >= 400)
	{
		cout << "Quadrant zwei geladen" << endl;
		if(this->get_Position()->i_x > p_TempSegment->SegmentRect12[0].x + p_TempSegment->SegmentRect12[0].w - PLAYER_WIDTH)
		{
			return true;
		}
	}
	
}
