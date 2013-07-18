#include "NPC2.h"

using namespace std;

void NPC2::render(SDL_Rect camera,Player * p_TempPlayer)
{
	///Das Bild von NPC2 wird angezeigt:
	apply_Image(this->get_Position()->i_x - camera.x,this->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("npc2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	///Das Bild vom Bären wird angezeigt:
	apply_Image(p_s_baerposition->i_x - camera.x,p_s_baerposition->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Baer"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

	///Wenn die richtigen bools gesetzt sind fragt der NPC2 nach seinem Baeren:
	if(b_questanfang == true && b_questende == false)
	{
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("qabfrage"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	///Wenn die richtigen bools gesetzt sind dann spricht der NPC2 seine Dankbarkeit aus:
	else if(b_questende == true && PlayCloseToBot(p_TempPlayer) == true)
	{
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("qbelohnung"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		if(b_finish == true)
		{
			EPManager::get_EPManager().Set_Ep(100);
			/*MoneyManager::get_MoneyManager().(20);*/		
		}
		b_finish = false;
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
				///wenn e gedrueckt wird kann man mit dem NPC reden:
				if(even.key.keysym.sym == SDLK_e)			
				{
					if(b_questanfang == true)
					{
						return;
					}
					///Es wird geprüft ob NPC2 in der Reichweite des Players ist
					if(NPC2::get_NPC2().PlayCloseToBot(p_TempPlayer) == true)
					{
						this->b_questanfang = true;
						this->p_QuestTimer->start();
					}
				}
			}
}
///Wenn man den Bären findet wird ein bool gesetzt, damit man sich die Belohnung abholen kann:
void  NPC2::playerclosetobaer(Player * p_TempPlayer)
{
	if(p_TempPlayer->get_Position()->i_x - this->p_s_baerposition->i_x <= 50 && p_TempPlayer->get_Position()->i_x - this->p_s_baerposition->i_x >= -50 && p_TempPlayer->get_Position()->i_y - this->p_s_baerposition->i_y <= 50 && p_TempPlayer->get_Position()->i_y - this->p_s_baerposition->i_y >= -50)
	{
		cout << "bin da" << endl;
		this->b_questende = true;
		this->b_finish = true;
		cout << b_finish << endl;
	}
}
void NPC2::baer_spricht()
{
	if(b_finish == true)
		{
			cout <<"bär spricht"<< endl;
			apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("Baer_spricht"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}		
}
bool NPC2::PlayerCloseToBaer(Player * p_TempPlayer)
{
	if(p_TempPlayer->get_Position()->i_x - this->p_s_baerposition->i_x <= 50 && p_TempPlayer->get_Position()->i_x - this->p_s_baerposition->i_x >= -50 && p_TempPlayer->get_Position()->i_y - this->p_s_baerposition->i_y <= 50 && p_TempPlayer->get_Position()->i_y - this->p_s_baerposition->i_y >= -50)
	{
		return true;
	}
}
///Timer wird gesetzt damit die Quest Anfrage nach drei Sekunden verschwindet:
void NPC2::questloeschen()
{
	if(b_questanfang == true && this->p_QuestTimer->Getticks() >= 2000)
	{
		b_questanfang = false;
	}
}

void NPC2::set_QuestEnde(bool b)
{
	this->b_questende = b;
}






