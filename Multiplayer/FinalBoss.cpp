#include "FinalBoss.h"
#include "Player.h"







/**
apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Win"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		SDL_Delay(5000);
		tempplayer->set_Health(100);
		tempplayer->set_Position(0,0);
		*tempmenue = true;
		*/




void FinalBoss::render(SDL_Rect  camera){
	

	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Prinzessin"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->EndbossClips[i_frames]);
	



}

void FinalBoss::update(Player * p_Player,SDL_Rect camera)
{
	///Bewegungsteil_________________________________________________________________________________________________________________________________
	if(transformed == false)
	{
		p_Player->set_disable(true);
		AnimationTimer->start();
		while(AnimationTimer->Getticks() <= 2000)
		{
			
			if(AnimationTimer->Getticks() >= 300 && transformed == false)
			{
				i_frames++;
				if(i_frames == 6)
				{
					transformed = true;
				}
				AnimationTimer->start();
			}
			SDL_FillRect(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->format,0x00,0x00,0x00));
			apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&camera);
			this->render(camera);
			SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
		p_Player->set_disable(false);
		AttackTimer->start();
		AnimationTimer->start();
	}
	
	if(transformed == true)
	{
		if(raged == false && AttackTimer->Getticks() >= 3000)
		{
			this->p_s_Velocity->i_y = 5;
			this->p_s_Velocity->i_x = 0;
			raged = true;
			AttackTimer->start();
			OverlayTimer->start();
		}
		if(raged == true)
		{
			this->p_s_Velocity->i_y = 5;

			if(p_s_Position->i_y - p_s_StartPosition->i_y >= 200)
			{
				HURTSTATE = HURTABLE;
				this->p_s_Velocity->i_y = 0;
			}
			if(AttackTimer->Getticks() >= 3000)
			{
				this->p_s_Velocity->i_y = -5;
				HURTSTATE = HURT;
				finishmovedoneonce = false;
			
				if(this->p_s_Position->i_y <= p_s_StartPosition->i_y)
				{
					
					this->p_s_Velocity->i_y = 0;
					this->p_s_Velocity->i_x = 2;
					raged = false;
					AttackTimer->start();
				}
			}
			}
		}

		if(raged == false)
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
		}
		this->p_s_Position->i_x += p_s_Velocity->i_x;this->p_s_Position->i_y += this->p_s_Velocity->i_y;

		///ENDE BEwegungsteil_________________________________________________________________________________________________________________

		///Anfang Schadenssetzungsteil__________________________________________________________________________________________________________


		if(this->HURTSTATE == HURT)
		{
			if(p_Player->get_Position()->i_x - this->get_Position()->i_x >= -60 && p_Player->get_Position()->i_x - this->get_Position()->i_x <= 100 && p_Player->get_Position()->i_y - this->get_Position()->i_y <= 100 && p_Player->get_Position()->i_y - this->get_Position()->i_y >= -100)
			{
				p_Player->set_Health(p_Player->get_Health() - 5);
				cout << p_Player->get_Health();
			}
		}
		
}



void FinalBoss::weaken_Endboss(Player * p_Player)
{
	if(this->isactivated == false)
	{
		cout << "Kein Finishmove möglich" << endl;
		return;
	}
	else if(this->HURTSTATE == HURTABLE && finishmovedoneonce == false)
	{
		cout << "finishmove möglich" << endl;
		if(p_Player->get_Position()->i_x - this->get_Position()->i_x >= -60 && p_Player->get_Position()->i_x - this->get_Position()->i_x <= 100 && p_Player->get_Position()->i_y - this->get_Position()->i_y <= 100 && p_Player->get_Position()->i_y - this->get_Position()->i_y >= -100)
		{
			this->i_health -= 200;
			finishmovedoneonce = true;
			if(this->i_health <= 0)
			{
				this->isdead = true;
			}
		}
		return;
	}
	
	else
	{
		cout << "Kein Finishmove möglich" << endl;
		return;
	}
	

}