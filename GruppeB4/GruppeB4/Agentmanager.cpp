#include "AgentManager.h"

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
		cout << "ATTACK WUHHHUUUUUUU" << endl;
	}
}