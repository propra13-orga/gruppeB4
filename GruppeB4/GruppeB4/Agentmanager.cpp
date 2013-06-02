#include "AgentManager.h"

void AgentManager::check_collision(Player * p_TempPlayer)
{
	 if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[0]->get_Position()->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[0]->get_Position()->i_x && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[0]->get_Position()->i_y && p_TempPlayer->get_Position()->i_y <= crazy_enemies[0]->get_Position()->i_y)//p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[0]->i_y && p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH > crazy_enemies[0]->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[0]->i_x)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
			
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[0]->get_Position()->i_x && p_TempPlayer->get_Position()->i_x <= crazy_enemies[0]->get_Position()->i_x && p_TempPlayer->get_Position()->i_y <= crazy_enemies[0]->get_Position()->i_y + PLAYER_HEIGHT && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[0]->get_Position()->i_y + PLAYER_HEIGHT)
		{
		p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[0]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_x <= crazy_enemies[0]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_y <= crazy_enemies[0]->get_Position()->i_y && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[0]->get_Position()->i_y)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			cout << p_TempPlayer->get_Health() << endl;
			
		
			
		}
	 else if(p_TempPlayer->get_Position()->i_x + PLAYER_WIDTH >= crazy_enemies[0]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_x <= crazy_enemies[0]->get_Position()->i_x + PLAYER_WIDTH && p_TempPlayer->get_Position()->i_y <= crazy_enemies[0]->get_Position()->i_y + PLAYER_HEIGHT && p_TempPlayer->get_Position()->i_y + PLAYER_HEIGHT >= crazy_enemies[0]->get_Position()->i_y + PLAYER_HEIGHT)
		{
			p_TempPlayer->set_Health(p_TempPlayer->get_Health() - 3);
			
			
			
		}
}