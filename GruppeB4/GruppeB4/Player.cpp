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

void Player::render(bool * tempmenue)
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


	if(this->health == 0)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("game_over_raw"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		this->health = 100;
		this->set_Position(0,0);
		*tempmenue = true;
	}
}
bool Player::collision_Detection(LevelSegmente * p_TempSegment,s_Vector * tempposition)
{
	//für den ersten Quadranten
	if(this->get_Position()->i_x <=710 && this->get_Position()->i_y >= 400)
	{
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
	//für den zweiten Quadranten inklusive Gegner
	if(this->get_Position()->i_x > 710 && this->get_Position()->i_y >= 347 - PLAYER_WIDTH)
	{
		if(this->get_Position()->i_x > p_TempSegment->SegmentRect12[0].x + p_TempSegment->SegmentRect12[0].w - PLAYER_WIDTH)
		{
			return true;
		}
		else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect12[1].x && this->get_Position()->i_y <= p_TempSegment->SegmentRect12[0].y)
		{
			return true;
		}
		else if(this->get_Position()->i_x + PLAYER_WIDTH >= p_TempSegment->SegmentRect12[1].x + p_TempSegment->SegmentRect12[1].w && this->get_Position()->i_y <= p_TempSegment->SegmentRect12[0].y)
		{
			return true;
			}
		else if(this->get_Position()->i_y + PLAYER_HEIGHT >= p_TempSegment->SegmentRect12[0].y + p_TempSegment->SegmentRect12[0].h)
		{
			return true;
		}

		//Kollision für den Gegner
		else if(this->get_Position()->i_x + PLAYER_WIDTH >= tempposition->i_x && this->get_Position()->i_x <= tempposition->i_x && this->get_Position()->i_y + PLAYER_HEIGHT >= tempposition->i_y && this->get_Position()->i_y <= tempposition->i_y)//this->get_Position()->i_y + PLAYER_HEIGHT >= tempposition->i_y && this->get_Position()->i_x + PLAYER_WIDTH > tempposition->i_x && this->get_Position()->i_x <= tempposition->i_x)
		{
			this->health = 0;
			cout << health << endl;
		
			return false;
			
		}
		else if(this->get_Position()->i_x + PLAYER_WIDTH >= tempposition->i_x && this->get_Position()->i_x <= tempposition->i_x && this->get_Position()->i_y <= tempposition->i_y + PLAYER_HEIGHT && this->get_Position()->i_y + PLAYER_HEIGHT >= tempposition->i_y + PLAYER_HEIGHT)
		{
		this->health = 0;
			cout << health << endl;
			
			return false;
			
		}
		else if(this->get_Position()->i_x + PLAYER_WIDTH >= tempposition->i_x + PLAYER_WIDTH && this->get_Position()->i_x <= tempposition->i_x + PLAYER_WIDTH && this->get_Position()->i_y <= tempposition->i_y && this->get_Position()->i_y + PLAYER_HEIGHT >= tempposition->i_y)
		{
			this->health = 0;
			cout << health << endl;
			
			return false;
			
		}
		else if(this->get_Position()->i_x + PLAYER_WIDTH >= tempposition->i_x + PLAYER_WIDTH && this->get_Position()->i_x <= tempposition->i_x + PLAYER_WIDTH && this->get_Position()->i_y <= tempposition->i_y + PLAYER_HEIGHT && this->get_Position()->i_y + PLAYER_HEIGHT >= tempposition->i_y + PLAYER_HEIGHT)
		{
			this->health = 0;
			cout << health << endl;
			
			return false;
		}

	}
	//Quadrant 3
	if(this->get_Position()->i_x > 579 && this->get_Position()->i_y <= 346 - PLAYER_WIDTH)
	{
		if(this->get_Position()->i_y >= p_TempSegment->SegmentRect13[0].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[0].x)
		{
			return true;
		}
		else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect13[0].y && this->get_Position()->i_y >= p_TempSegment->SegmentRect13[1].y - PLAYER_HEIGHT && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[1].x && this->get_Position()->i_x >= p_TempSegment->SegmentRect13[0].x)
		{
			return true;
		}
		else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect13[1].x + p_TempSegment->SegmentRect13[1].w - PLAYER_WIDTH)
		{
			return true;
		}
		else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect13[2].y)
		{
			return true;
		}
		else if((this->get_Position()->i_x >= p_TempSegment->SegmentRect13[2].x - PLAYER_WIDTH) && (this->get_Position()->i_x <= p_TempSegment->SegmentRect13[2].x + p_TempSegment->SegmentRect13[2].w - PLAYER_WIDTH) && (this->get_Position()->i_y >= p_TempSegment->SegmentRect13[2].y) && (this->get_Position()->i_y <= p_TempSegment->SegmentRect13[2].y + p_TempSegment->SegmentRect13[2].h + 20))

		{
			if(this->get_Position()->i_y + PLAYER_HEIGHT >= p_TempSegment->SegmentRect13[2].y + p_TempSegment->SegmentRect13[2].h)
			{
				return true;
			}
		}
		else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect13[3].x - 20 && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[3].x + p_TempSegment->SegmentRect13[3].w - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect13[3].y && this->get_Position()->i_y <= p_TempSegment->SegmentRect13[4].y)
		{
			if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[3].x)
			{
				return true;
			}
		}
		else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect13[3].x - 20 && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[3].x + p_TempSegment->SegmentRect13[3].w - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect13[4].y && this->get_Position()->i_y <= 285 + 10)
		{
			if(this->get_Position()->i_x >= p_TempSegment->SegmentRect13[3].x + p_TempSegment->SegmentRect13[3].w - PLAYER_WIDTH)
			{
				return true;
			}
			else if(this->get_Position()->i_y >= 285 - PLAYER_HEIGHT )
			{
				return true;
			}
			else if (this->get_Position()->i_y >= p_TempSegment->SegmentRect13[4].y + p_TempSegment->SegmentRect13[4].h - PLAYER_HEIGHT && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[3].x)
			{
				return true;
			}
		}
		
		
	}
	
	//Quadrant 4

	if(this->get_Position()->i_x < 709 && this->get_Position()->i_y < 350)
	{
		if (this->get_Position()->i_x >= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect13[4].y)
		{cout << "1." << endl;
			return true;
		}
		else if (this->get_Position()->i_x >= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect13[4].y +p_TempSegment->SegmentRect13[4].h - PLAYER_WIDTH )
		{
			return true;
		}
		else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect14[0].y)
		{
			cout << "2." << endl;
				return true;
			
			
		}
		else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect14[0].y + p_TempSegment->SegmentRect14[0].h - PLAYER_HEIGHT)
		{
			cout << "here" << endl;
			return true;
		}
		else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_x <= p_TempSegment->SegmentRect14[0].x)
		{
			return true;
		}
	}


	
}