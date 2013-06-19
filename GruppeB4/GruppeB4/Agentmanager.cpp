#include "AgentManager.h"

void AgentManager::update(Player * p_TempPlayer)
{
	for(unsigned int i = 0;i < crazy_enemies.size();i++){check_collision(p_TempPlayer,i);crazy_enemies[i]->update();}for(unsigned int i = 0;i < allPfleger.size();i++)allPfleger[i]->update(p_TempPlayer);

}

void AgentManager::render(SDL_Rect camera)
{
	for(unsigned int i = 0;i < crazy_enemies.size();i++)
	{crazy_enemies[i]->render( camera);}
	for(unsigned int i = 0;i < allPfleger.size();i++)
	allPfleger[i]->render(camera);

	for(vector<Crazy_enemy*>::iterator myIter = crazy_enemiesToDelete.begin();myIter != crazy_enemiesToDelete.end();myIter++)
	{
		apply_Image((*myIter)->get_Position()->i_x - camera.x,(*myIter)->get_Position()->i_y - camera.y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Verrückter_Up"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->PlayerUpClips[0]);
	}
}

void AgentManager::check_collision(Player * p_TempPlayer,int durchlaufvariable)
{
	
	 if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[durchlaufvariable]->get_Position()->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[durchlaufvariable]->get_Position()->i_x && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[durchlaufvariable]->get_Position()->i_y && p_TempPlayer->get_Position()->i_y <= crazy_enemies[durchlaufvariable]->get_Position()->i_y)//p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[durchlaufvariable]->i_y && p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH > crazy_enemies[durchlaufvariable]->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[durchlaufvariable]->i_x)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
			
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[durchlaufvariable]->get_Position()->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[durchlaufvariable]->get_Position()->i_x && p_TempPlayer->get_Position()->i_y <= crazy_enemies[durchlaufvariable]->get_Position()->i_y + PLAYER_HEIGHT && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[durchlaufvariable]->get_Position()->i_y + PLAYER_HEIGHT)
		{
		p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[durchlaufvariable]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_x <= crazy_enemies[durchlaufvariable]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_y <= crazy_enemies[durchlaufvariable]->get_Position()->i_y && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[durchlaufvariable]->get_Position()->i_y)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
			
			
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[durchlaufvariable]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_x <= crazy_enemies[durchlaufvariable]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_y <= crazy_enemies[durchlaufvariable]->get_Position()->i_y + PLAYER_HEIGHT && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[durchlaufvariable]->get_Position()->i_y + PLAYER_HEIGHT)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			
			
			
		}
	}

void AgentManager::weaken_Bots(Player * p_tempPlayer)
{
	if(WeaponManager::get_WeaponManager().CURRENT_WEAPON2 == NONE)
	{
		cout << "Keine Attacke" << endl;
	}
	else if(WeaponManager::get_WeaponManager().CURRENT_WEAPON2 == MELEE)
	{
		if(p_tempPlayer->get_WalkStatus() == PSY_UP)
		{
			for(vector<Crazy_enemy*>::iterator i = crazy_enemies.begin();i != crazy_enemies.end();++i)
			{
				if((*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 >= -150 && (*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 <= 0 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 <= 100 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 >= -50 )
				{
					(*i)->set_health((*i)->get_Health() - 100);
					if((*i)->get_Health() <= 0)
					{
						crazy_enemiesToDelete.push_back(new Crazy_enemy((*i)->get_Position()->i_x,(*i)->get_Position()->i_y));
						crazy_enemies.erase(i);
						break;
					}
				}
			}
		}
		else if(p_tempPlayer->get_WalkStatus() == PSY_DOWN)
		{
			for(vector<Crazy_enemy*>::iterator i = crazy_enemies.begin();i != crazy_enemies.end();++i)
			{
				if((*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 <= 150 && (*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 >= 0 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 <= 100 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 >= -50 )
				{
					(*i)->set_health((*i)->get_Health() - 100);
					if((*i)->get_Health() <= 0)
					{
						crazy_enemiesToDelete.push_back(new Crazy_enemy((*i)->get_Position()->i_x,(*i)->get_Position()->i_y));
						crazy_enemies.erase(i);
						break;
					}
				}
			}
		}
		else if(p_tempPlayer->get_WalkStatus() == PSY_RIGHT)
		{
			for(vector<Crazy_enemy*>::iterator i = crazy_enemies.begin();i != crazy_enemies.end();++i)
			{
				if((*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 <= 50 && (*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 >= -50 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 <= 150 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 >= 0 )
				{
					(*i)->set_health((*i)->get_Health() - 100);
					if((*i)->get_Health() <= 0)
					{
						crazy_enemiesToDelete.push_back(new Crazy_enemy((*i)->get_Position()->i_x,(*i)->get_Position()->i_y));
						crazy_enemies.erase(i);
						break;
					}
				}
			}
		}
		else if(p_tempPlayer->get_WalkStatus() == PSY_LEFT)
		{
			for(vector<Crazy_enemy*>::iterator i = crazy_enemies.begin();i != crazy_enemies.end();++i)
			{
				if((*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 <= 50 && (*i)->get_Position()->i_y + 25 - p_tempPlayer->get_Position()->i_y + 25 >= -50 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 <= 0 && (*i)->get_Position()->i_x + 25 - p_tempPlayer->get_Position()->i_x + 25 >= -150 )
				{
					(*i)->set_health((*i)->get_Health() - 100);
					if((*i)->get_Health() <= 0)
					{
						crazy_enemiesToDelete.push_back(new Crazy_enemy((*i)->get_Position()->i_x,(*i)->get_Position()->i_y));
						crazy_enemies.erase(i);
						break;
					}
				}
			}
		}
	}
}

void AgentManager::set_Bot(int x, int y,BOT_TYPE TEMPTYPE)
{
	if(TEMPTYPE == CRAZY_ENEMY)
	{
		this->crazy_enemies.push_back(new Crazy_enemy(x,y));
	}
	if(TEMPTYPE == PFLEGER)
	{
		this->allPfleger.push_back(new Pfleger(x,y));
	}
	else
	{
		return;
	}
}