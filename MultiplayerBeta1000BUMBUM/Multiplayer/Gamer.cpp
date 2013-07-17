#include "Gamer.h"

void MultiplayerLowClass::Player::update()
{
	this->set_Position(this->get_Position()->X + this->get_Velocity()->X,this->get_Position()->Y + this->get_Velocity()->Y);

		//hier testen ob mit Block kollidiert

	if(this->get_Position()->X <= 0)
	{
		this->set_Position(0,get_Position()->Y);
	}
	if(this->get_Position()->X >= 900 - 60)
	{
		this->set_Position(900 - 60,get_Position()->Y);
	}
	if(this->get_Position()->Y <= 0)
	{
		this->set_Position(get_Position()->X,0);
	}
	if(this->get_Position()->Y >= 600 - 60)
	{
		this->set_Position(get_Position()->X,600 - 60);
	}

}

void MultiplayerLowClass::Player::render()
{
	if(this->CURRENTTYPE == MultiplayerEnumerations::ELECTRIC)
	{
		if(this->directionDown == true)
		{
			this->CURRENTWALKINGSTAT = MultiplayerEnumerations::PSY_DOWN;
			if(this->p_AnimationTimer->Getticks() >= 100)
			{
				animationframe++;
				p_AnimationTimer->start();
			}
		}
		else if(this->directionUp == true)
		{
			this->CURRENTWALKINGSTAT = MultiplayerEnumerations::PSY_UP;
			if(this->p_AnimationTimer->Getticks() >= 100)
			{
				animationframe++;
				p_AnimationTimer->start();
			}
		}
		else if(this->directionRight == true)
		{
			this->CURRENTWALKINGSTAT = MultiplayerEnumerations::PSY_RIGHT;
			if(this->p_AnimationTimer->Getticks() >= 100)
			{
				animationframe++;
				p_AnimationTimer->start();
			}
		}
		else if(this->directionLeft == true)
		{
			this->CURRENTWALKINGSTAT = MultiplayerEnumerations::PSY_LEFT;
			if(this->p_AnimationTimer->Getticks() >= 100)
			{
				animationframe++;
				p_AnimationTimer->start();
			}
		}
		else
		{
		animationframe = 0;
		}
		if(animationframe >= 5)
		{
			animationframe = 0;
		}
	
		MultiplayerHighClass::S_ResourceManager::get_Instance()->ApplyPicture(this->get_Position()->X,this->get_Position()->Y,MultiplayerHighClass::S_ResourceManager::get_Instance()->GetPicture(MultiplayerHighClass::S_ResourceManager::key_electric_player_down),MultiplayerHighClass::S_ResourceManager::get_Instance()->GetScreen(),&MultiplayerHighClass::S_ResourceManager::get_Instance()->PlayerClips[animationframe]);
	}
}