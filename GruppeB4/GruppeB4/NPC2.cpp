#include "NPC2.h"

using namespace std;

void NPC2::render(SDL_Rect camera)
{
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("npc2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

	apply_Image(200 - camera.x,200 - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Baer"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

	if(b_questanfang == true && b_questende == false)
	{
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("qabfrage"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	else if(b_questende == true)
	{
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("qbelohnung"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
} 

bool NPC2::PlayCloseToBot(Player * p_TempPlayer)
{
	if(p_TempPlayer->get_Position()->i_x - this->get_Position()->i_x <= 50 && p_TempPlayer->get_Position()->i_x - this->get_Position()->i_x >= -50 && p_TempPlayer->get_Position()->i_y - this->get_Position()->i_y <= 50 && p_TempPlayer->get_Position()->i_y - this->get_Position()->i_y >= -50)
	{
		return true;
	}
	return false;
}
void NPC2::questanfrage(Player * p_TempPlayer,SDL_Event even)
{
	
	if(even.type == SDL_KEYDOWN)
			{
				///wenn e gedrueckt wird kann man mit dem NPC reden
				if(even.key.keysym.sym == SDLK_e)			
				{
					if(b_questanfang == true)
					{
						return;
					}
					if(NPC2::get_NPC2().PlayCloseToBot(p_TempPlayer) == true)
					{
						this->b_questanfang = true;
						this->p_QuestTimer->start();
					}
				}
			}
}
void NPC2::questloeschen()
{
	if(b_questanfang == true && this->p_QuestTimer->Getticks() >= 3000)
	{
		b_questanfang = false;
	}
}
void NPC2::questloeschen2()
{
	if(b_questende == true && this->p_QuestTimer->Getticks() >= 3000)
	{
		b_questende = false;
	}
}
void NPC2::set_QuestEnde(bool b)
{
	this->b_questende = b;
}





