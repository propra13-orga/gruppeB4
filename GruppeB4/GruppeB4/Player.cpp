#include "Player.h"
#include "AgentManager.h"
#include "World.h"

void Player::reinitialize(LEVEL_LOADED CURRENTLEVEL)
{
	if(CURRENTLEVEL == LEVEL1)
	{
	this->set_Position(648,795);
	this->set_Health(400);
	this->set_Mana(100);
	}
	else if(CURRENTLEVEL == LEVEL2)
	{
		this->set_Health(400);
		this->set_Position(1800,960);
	}
	else if(CURRENTLEVEL == LEVEL3)
	{
		this->set_Health(400);
		this->set_Position(80,250);
	}
}

void Player::handle_Input(SDL_Event &even)
{
	if(even.type == SDL_KEYDOWN)
	{
		if(this->disableallabilities == false)
		{
		switch(even.key.keysym.sym)
		{
		case(SDLK_UP):if(this->rageModeToggled == false){this->set_Velocity(0,-2);}else{this->set_Velocity(0,-3);}b_PlayerIsWalkingUp = true;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_DOWN):if(this->rageModeToggled == false){this->set_Velocity(0,2);}else{this->set_Velocity(0,3);};b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = true;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_RIGHT):if(this->rageModeToggled == false){this->set_Velocity(2,0);}else{this->set_Velocity(3,0);}b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = true;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_LEFT):if(this->rageModeToggled == false){this->set_Velocity(-2,0);}else{this->set_Velocity(-3,0);}b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = true;break;
		case(SDLK_4):this->heal(100);cout << i_health << endl;break;
		case(SDLK_v):WeaponManager::get_WeaponManager().swap_weapon();WeaponManager::get_WeaponManager().show_currentWeapon();break;
		case(SDLK_SPACE):this->attack();break;
		case(SDLK_5):this->loadMana(); cout << i_mana << endl; break;
		case(SDLK_r):this->setRageMode();break;
		case(SDLK_f):AgentManager::get_AgentManager().get_Boss()->weaken_Endboss(this);
		}
		}
	}
	else if(even.type == SDL_KEYUP)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_UP):this->set_Velocity(0,0);b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_DOWN):this->set_Velocity(0,0);b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_RIGHT):this->set_Velocity(0,0);b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		case(SDLK_LEFT):this->set_Velocity(0,0);b_PlayerIsWalkingUp = false;b_PlayerIsWalkingDown = false;b_PlayerIsWalkingRight = false;b_PlayerIsWalkingLeft = false;break;
		}
	}
	if(b_PlayerIsWalkingUp == true)
	{
		cout << "Hoch" << endl;
	}
	else if(b_PlayerIsWalkingDown == true)
	{
		cout << "Runter" << endl;
	}
	else if(b_PlayerIsWalkingRight == true)
	{
		cout << "Rechts" << endl;
	}
	else if(b_PlayerIsWalkingLeft == true)
	{
		cout << "Links" << endl;
	}
}

void Player::update()
{
	

	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);

	if(this->rageModeToggled == true)
	{
		if(this->RageModeTimer->Getticks() >= 3000)
		{
			this->rageModeToggled = false;
			this->RageModeTimer->stop();
			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,2);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-2);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(2,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-2,0);
			}

		}
	}

	
}

void Player::render(bool * tempmenue, Timer* deltaTime,SDL_Rect cam,LEVEL_LOADED CURRENTLEVEL,World * p_TempWorld)
{
	if(this->b_PlayerIsWalkingDown == true)
	{
		this->e_currentwalkstatus = PSY_DOWN;

		cout << deltaTime->Getticks();
		if(deltaTime->Getticks() >= 100)
		{

		i_frame++;
		deltaTime->start();
		}
	}
	else if(this->b_PlayerIsWalkingUp == true)
	{
		this->e_currentwalkstatus = PSY_UP;

		if(deltaTime->Getticks() >= 100)
		{
			i_frame++;
			deltaTime->start();
		}
	}
	else if(this->b_PlayerIsWalkingLeft == true)
	{
		this->e_currentwalkstatus = PSY_LEFT;

		if(deltaTime->Getticks() >= 100)
		{
			i_frame++;
			deltaTime->start();
		}
	}
	else if(this->b_PlayerIsWalkingRight == true)
	{
		this->e_currentwalkstatus = PSY_RIGHT;

		if(deltaTime->Getticks() >= 100)
		{
			i_frame++;
			deltaTime->start();
		}
	}
	else
	{
		i_frame = 0;
	}
	if(i_frame >= 5)
	{
		i_frame = 0;
	}

	if(this->e_currentwalkstatus == PSY_DOWN)
	{
		apply_Image(this->get_Position()->i_x - cam.x,this->get_Position()->i_y - cam.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerDownClips[i_frame]);
	}
	else if(this->e_currentwalkstatus == PSY_UP)
	{
		apply_Image(this->get_Position()->i_x - cam.x,this->get_Position()->i_y - cam.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player_Up"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerDownClips[i_frame]);
	}
	else if(this->e_currentwalkstatus == PSY_LEFT)
	{
		apply_Image(this->get_Position()->i_x - cam.x ,this->get_Position()->i_y - cam.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player Left"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerDownClips[i_frame]);
	}
	else if(this->e_currentwalkstatus == PSY_RIGHT)
	{
	apply_Image(this->get_Position()->i_x - cam.x,this->get_Position()->i_y - cam.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player Right"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerDownClips[i_frame]);
	}


	if(this->i_health <= 0)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("game_over_raw"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		apply_Image(this->get_Position()->i_x - cam.x,this->get_Position()->i_y - cam.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("tot"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		AgentManager::get_AgentManager().reinitialize();
		ItemManager::get_ItemManager().reinitialize();
		this->reinitialize(CURRENTLEVEL);
		p_TempWorld->initialize_Level();
		*tempmenue = true;
	}
}
/// Collision

bool Player::collision_Detection(LevelSegmente * p_TempSegment,LEVEL_LOADED CURRENTLEVEL)
{
	///LVL1
	if(CURRENTLEVEL == LEVEL1)
	{
	///fuer den ersten Quadranten:
	if(this->get_Position()->i_x <=968 && this->get_Position()->i_y >= 630)
		{
			///Wand links:
			if(this->get_Position()->i_x <= p_TempSegment->SegmentRect11[0].x )
			{
				return true;
			}
			///Wand oben:
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect11[0].y)
			{
				return true;
			}
			///Wand unten:
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect11[0].y + 476 - PLAYER_HEIGHT)
			{
				return true;
			}
			///Wand rechts oben + Durchgang oben:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect11[0].x + p_TempSegment->SegmentRect11[0].w - PLAYER_HEIGHT && this->get_Position()->i_y <= p_TempSegment->SegmentRect11[1].y)
			{
				return true;
			}
			///Wand rechts unten + Durchgang unten:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect11[0].x  + p_TempSegment->SegmentRect11[0].w - PLAYER_HEIGHT && this->get_Position()->i_y >= p_TempSegment->SegmentRect11[1].y + p_TempSegment->SegmentRect11[1].h - PLAYER_HEIGHT )
			{
				return true;
			}
		}
	///fuer den zweiten Quadranten:
	if(this->get_Position()->i_x >=969 && this->get_Position()->i_y >= 630 - PLAYER_WIDTH)
		{
			///Wand rechts:
			if(this->get_Position()->i_x > p_TempSegment->SegmentRect12[0].x + p_TempSegment->SegmentRect12[0].w - PLAYER_WIDTH)
			{
				return true;
			}
			///Wand oben linke Seite + Durchgang links:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect12[1].x && this->get_Position()->i_y <= p_TempSegment->SegmentRect12[0].y)
			{
				return true;
			}
			///Wand oben rechte Seite + Durchgang rechts:
			else if(this->get_Position()->i_x + PLAYER_WIDTH >= p_TempSegment->SegmentRect12[1].x + p_TempSegment->SegmentRect12[1].w && this->get_Position()->i_y <= p_TempSegment->SegmentRect12[0].y)
			{
				return true;
			}
			///Wand unten:
			else if(this->get_Position()->i_y + PLAYER_HEIGHT >= p_TempSegment->SegmentRect12[0].y + p_TempSegment->SegmentRect12[0].h)
			{
				return true;
			}
		}
	///fuer den dritten Quadrant (Treppenhaus):
	if(this->get_Position()->i_x >= 1203 - PLAYER_WIDTH && this->get_Position()->i_y <= 600 - PLAYER_WIDTH)
		{
			///erster Raum Wand links: 
			if(this->get_Position()->i_y >= p_TempSegment->SegmentRect13[0].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect13[0].x)
			{
				return true;
			}
			//Wand rechts:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect13[1].x + p_TempSegment->SegmentRect13[1].w - PLAYER_WIDTH)
			{
				return true;
			}
			//Wand oben:
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect13[2].y)
			{
				return true;
			}
			//erster Raum unten links:
			else if(this->get_Position()->i_x <= 1330 && this->get_Position()->i_y >= 591 - PLAYER_HEIGHT)
			{
				return true;
			}
			//erster Raum unten rechts:
			else if(this->get_Position()->i_x >= 1546 && this->get_Position()->i_y >= 591 - PLAYER_HEIGHT)
			{
				return true;
			}
			//erster Treppe linke Seite
			else if(this->get_Position()->i_x <= 1677 && this->get_Position()->i_y >= 227 - PLAYER_HEIGHT && this->get_Position()->i_y <= 370)
			{
				return true;
			}
		}
		if(this->get_Position()->i_x <= 1206 && this->get_Position()->i_y <= 500 - PLAYER_WIDTH)
		{
			//letzter Raum Wand unten:
			if(this->get_Position()->i_x <= 1203 && this->get_Position()->i_y >= 489 - PLAYER_HEIGHT && this->get_Position()->i_x >= 950)
			{
				return true;
			}
			//wand oben
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect13[2].y)
			{
				return true;
			}
		}
	//fuer den vierten Quadrant:
	if(this->get_Position()->i_x < 969 && this->get_Position()->i_y < 600)
		{
			//Wand rechts oben + Durchgang oben:
			if (this->get_Position()->i_x >= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect13[4].y)
			{
				return true;
			}
			//Wand rechts unten + Durchgang unten:
			else if (this->get_Position()->i_x >= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect13[4].y +p_TempSegment->SegmentRect13[4].h - PLAYER_WIDTH )
			{
				return true;
			}
			//Wand oben:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect14[0].y)
			{
				return true;
			}
			//Wand unten:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect13[4].x - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect14[0].y + p_TempSegment->SegmentRect14[0].h - PLAYER_HEIGHT)
			{
				return true;
			}
		}
	}
	/// LVL2
	if(CURRENTLEVEL == LEVEL2)
	{
		///fuer den ersten Quadrant:
		if(this->get_Position()->i_x > 1 && this->get_Position()->i_y >  p_TempSegment->SegmentRect21[1].y)
		{
			///Wand unten:
			if(this->get_Position()->i_y >= p_TempSegment->SegmentRect21[0].y + p_TempSegment->SegmentRect21[0].h - PLAYER_HEIGHT)
			{
				return true;
			}
			///Wand links:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect21[0].x)
			{
				return true;
			}
			///Wand oben linke Seite + Durchgang links:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect21[1].x && this->get_Position()->i_y <= p_TempSegment->SegmentRect21[0].y)
			{
				return true;
			}
			///Wand oben rechte Seite + Durchgang rechts:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect21[1].x + p_TempSegment->SegmentRect21[1].w - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect21[0].y)
			{
				return true;
			}
		}
		///fuer den zweiten Quadrant:
		if(this->get_Position()->i_x > 1 && this->get_Position()->i_y <  p_TempSegment->SegmentRect21[1].y)
		{
			///Wand oben:
			if(this->get_Position()->i_y <= p_TempSegment->SegmentRect22[0].y)
			{
				return true;
			}
			///Wand unten rechte Seite:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect21[1].x + p_TempSegment->SegmentRect21[1].w - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect21[1].y - PLAYER_HEIGHT)
			{
				return true;
			}
			///Wand unten linke Seite: 
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect21[1].x && this->get_Position()->i_y >= p_TempSegment->SegmentRect21[1].y - PLAYER_HEIGHT)
			{
				return true;
			}
			///Wand links:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect22[0].x)
			{
				return true;
			}
		}
	}
	/// LVL3
	if(CURRENTLEVEL == LEVEL3)
	{
		///fuer den ersten Quadrant:
		if(this->get_Position()->i_x < p_TempSegment->SegmentRect31[1].x + p_TempSegment->SegmentRect31[1].w - PLAYER_WIDTH && this->get_Position()->i_y <  p_TempSegment->SegmentRect31[0].y + p_TempSegment->SegmentRect31[0].h)
		{
			///Wand unten:
			if(this->get_Position()->i_y + PLAYER_HEIGHT >= p_TempSegment->SegmentRect31[0].y + p_TempSegment->SegmentRect31[0].h)
			{
				return true;
			}
			///Wand oben:
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect31[0].y)
			{
				return true;
			}
			///Wand rechts oben 
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect31[0].x + p_TempSegment->SegmentRect31[0].w - PLAYER_WIDTH && this->get_Position()->i_y >= p_TempSegment->SegmentRect31[1].y + p_TempSegment->SegmentRect31[1].h - PLAYER_HEIGHT)
			{
				return true;
			}
			///Wand rechts unten:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect31[0].x + p_TempSegment->SegmentRect31[0].w - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect31[1].y)
			{
				return true;
			}
		}
		///fuer den zweiten Quadrant:
		if(this->get_Position()->i_x < 1175 && this->get_Position()->i_y < 550 && this->get_Position()->i_x > 785 && this->get_Position()->i_y > 20)
		{
			if(this->get_Position()->i_y >= p_TempSegment->SegmentRect32[1].y - PLAYER_HEIGHT && this->get_Position()->i_x >= 1025 - PLAYER_WIDTH)
			{
				return true;
			}
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect32[0].y)
			{
				return true;
			}
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect32[0].x + p_TempSegment->SegmentRect32[0].w - PLAYER_WIDTH)
			{
				return true;
			}
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect32[1].y - PLAYER_HEIGHT && this->get_Position()->i_x <= p_TempSegment->SegmentRect32[1].x - PLAYER_WIDTH)
			{
				return true;
			}
		}
		///fuer den dritten Quadrant (Flur):
		if(this->get_Position()->i_y > p_TempSegment->SegmentRect32[1].y)
		{
			///erster Raum unten + dritter Flur oben:
			if(this->get_Position()->i_y >= p_TempSegment->SegmentRect33[0].y + p_TempSegment->SegmentRect33[0].h - PLAYER_HEIGHT && this->get_Position()->i_y < p_TempSegment->SegmentRect33[3].y && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[2].x + p_TempSegment->SegmentRect33[2].w - PLAYER_WIDTH && this->get_Position()->i_x < p_TempSegment->SegmentRect33[4].x)
			{
				return true;
			}
			///erster Raum Wand rechts:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect33[0].x + p_TempSegment->SegmentRect33[0].w - PLAYER_WIDTH && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[5].x && this->get_Position()->i_y < p_TempSegment->SegmentRect33[3].y)
			{
				return true;
			}
			///erster Raum Wand links oben + erster Flur oben:
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect33[1].y - PLAYER_HEIGHT && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[0].x)
			{
				return true;
			}
			///erster Raum Wand links unten + erster Flur unten:
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect33[2].y - PLAYER_HEIGHT && this->get_Position()->i_y <= p_TempSegment->SegmentRect33[3].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[0].x && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[2].x + p_TempSegment->SegmentRect33[2].w - PLAYER_WIDTH)
			{
				return true;
			}
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect33[1].y && this->get_Position()->i_y >= p_TempSegment->SegmentRect33[0].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[0].x )
			{
				return true;
			}
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect33[1].x)
			{
				return true;
			}
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect33[3].y + p_TempSegment->SegmentRect33[3].h - PLAYER_HEIGHT)
			{
				return true;
			}
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect33[3].x + p_TempSegment->SegmentRect33[3].w - PLAYER_WIDTH)
			{
				return true;
			}
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect33[4].x + p_TempSegment->SegmentRect33[4].w - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect33[3].y)
			{
				return true;
			}
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect33[4].y + p_TempSegment->SegmentRect33[4].h - PLAYER_HEIGHT && this->get_Position()->i_y >= p_TempSegment->SegmentRect33[4].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[4].x && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[5].x)
			{
				return true;
			}
			else if(this->get_Position()->i_y <= p_TempSegment->SegmentRect33[3].y - PLAYER_HEIGHT && this->get_Position()->i_y >= p_TempSegment->SegmentRect33[4].y && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[4].x + p_TempSegment->SegmentRect33[4].w - PLAYER_WIDTH)
			{
				return true;
			}
			///letzter Flur linke Seite + Boss Raum unten links: 
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect33[5].y + p_TempSegment->SegmentRect33[5].h - PLAYER_HEIGHT && this->get_Position()->i_y <= p_TempSegment->SegmentRect33[3].y && this->get_Position()->i_x <= p_TempSegment->SegmentRect33[4].x && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[5].x)
			{
				return true;
			}
			///letzter Flur rechte + Boss Raum unten recht:
			else if(this->get_Position()->i_y >= p_TempSegment->SegmentRect33[5].y + p_TempSegment->SegmentRect33[5].h - PLAYER_HEIGHT && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[4].x + p_TempSegment->SegmentRect33[4].w - PLAYER_WIDTH && this->get_Position()->i_y <= p_TempSegment->SegmentRect33[3].y)
			{
				return true;
			}
		}
		///Boss Raum:
		if(this->get_Position()->i_y < p_TempSegment->SegmentRect33[4].y && this->get_Position()->i_x >= p_TempSegment->SegmentRect33[5].x - 5)
		{
			///Wand oben:
			if(this->get_Position()->i_y <= p_TempSegment->SegmentRect33[5].y)
			{
				return true;
			}
			///Wand links:
			else if(this->get_Position()->i_x <= p_TempSegment->SegmentRect33[5].x)
			{
				return true;
			}
			///Wand rechts:
			else if(this->get_Position()->i_x >= p_TempSegment->SegmentRect33[5].x + p_TempSegment->SegmentRect33[5].w - PLAYER_WIDTH)
			{
				return true;
			}
		}
	}
		return false;
}
	
void Player::heal(int potsize)
{
	if(ItemManager::get_ItemManager().find(HEAL) == true)/// <guckt ob Item da, wenn ja, dann wird die Health um 100 Hochgepushed
	{
		ItemManager::get_ItemManager().kill_Item(HEAL);///<anschliesend muss das benutzte item wieder gelöscht werden
		if(Skilltree::get_Skilltree().t1_1() == true && Skilltree::get_Skilltree().t3_2() == false){
			this->set_Health(this->get_Health() + 150);
		}
		else if(Skilltree::get_Skilltree().t1_1() == true && Skilltree::get_Skilltree().t3_2() == true){
			this->set_Health(this->get_Health() + 175);
		}
		else if(Skilltree::get_Skilltree().t1_1() == false && Skilltree::get_Skilltree().t3_2() == true){
			this->set_Health(this->get_Health() + 175);
		}
		else {this->set_Health(this->get_Health() + potsize);}
	}
	else
	{
		return;
	}
}

void Player::loadMana()
{
	if(ItemManager::get_ItemManager().find(MANA) == true)///< guckt ob Item da, wenn ja, dann wird das Mana um 100 gepushed, was einem die möglichkeit von einem drei sekündigem Sprint gibt
	{
		ItemManager::get_ItemManager().kill_Item(MANA);///<anschliesend muss das benutzte item wieder gelöscht werden
		if(Skilltree::get_Skilltree().t2_3() == true)
		{
			this->set_Mana(this->get_Mana() + 75);
		}
		else{
		this->set_Mana(this->get_Mana() + 50);
		}
	}
	else
	{
		return;
	}
}

void Player::attack()
{
	AgentManager::get_AgentManager().weaken_Bots(this);
}


void Player::setRageMode()
{
	if(this->rageModeToggled == true)
	{
		return;
	}
	else
	{
		

		if(this->i_mana >= 100 && Skilltree::get_Skilltree().t1_2() == false && Skilltree::get_Skilltree().t2_1() == false && Skilltree::get_Skilltree().t3_1() == false)
			{
				
				if(Skilltree::get_Skilltree().t1_4() == false){
			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,3);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-3);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(3,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-3,0);
			}
			
			this->i_mana -= 100;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			}
		}
		
		if(Skilltree::get_Skilltree().t1_4() == true){
				

			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,4);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-4);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(4,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-4,0);
			}
			
			this->i_mana -= 100;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			
			
		}

		if(this->i_mana >= 90 && Skilltree::get_Skilltree().t1_2() == true && Skilltree::get_Skilltree().t2_1() == false && Skilltree::get_Skilltree().t3_1() == false)
			{
				
				if(Skilltree::get_Skilltree().t1_4() == false){
			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,3);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-3);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(3,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-3,0);
			}
			
			this->i_mana -= 90;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			}
		}
		
		if(Skilltree::get_Skilltree().t1_4() == true){
				

			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,4);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-4);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(4,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-4,0);
			}
			
			this->i_mana -= 90;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			
			
		}

		if(this->i_mana >= 80 && Skilltree::get_Skilltree().t1_2() == true && Skilltree::get_Skilltree().t2_1() == true && Skilltree::get_Skilltree().t3_1() == false)
			{
				
				if(Skilltree::get_Skilltree().t1_4() == false){
			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,3);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-3);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(3,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-3,0);
			}
			
			this->i_mana -= 80;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			}
		}
		
		if(Skilltree::get_Skilltree().t1_4() == true){
				

			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,4);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-4);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(4,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-4,0);
			}
			
			this->i_mana -= 80;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			
			
		}

		if(this->i_mana >= 50 && Skilltree::get_Skilltree().t1_2() == true && Skilltree::get_Skilltree().t2_1() == true && Skilltree::get_Skilltree().t3_1() == true)
			{
				
				if(Skilltree::get_Skilltree().t1_4() == false){
			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,3);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-3);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(3,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-3,0);
			}
			
			this->i_mana -= 50;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			}
		}
		
		if(Skilltree::get_Skilltree().t1_4() == true){
				

			if(this->b_PlayerIsWalkingDown == true)
			{
				this->set_Velocity(0,4);
			}
			else if(this->b_PlayerIsWalkingUp == true)
			{
				this->set_Velocity(0,-4);
			}
			else if(this->b_PlayerIsWalkingRight == true)
			{
				this->set_Velocity(4,0);
			}
			else if(this->b_PlayerIsWalkingLeft == true)
			{
				this->set_Velocity(-4,0);
			}
			
			this->i_mana -= 50;
			this->RageModeTimer->start();
			this->rageModeToggled = true;
			
			
		}
		}

	}