#ifndef AGENTMANAGER_H_
#define AGENTMANAGER_H_

#include "Verrückter.h"
#include "Player.h"
#include <vector>

class AgentManager
{
public:
	vector<Crazy_enemy*>crazy_enemies;
	AgentManager(){crazy_enemies.push_back( new Crazy_enemy(1035,731));}
	~AgentManager(){delete crazy_enemies[0];}
	void render(SDL_Rect camera){for(int i = 0;i < crazy_enemies.size();i++){crazy_enemies[i]->render( camera);}}
	void check_collision(Player * p_TempPlayer);
	void update(Player * p_TempPlayer){for(int i = 0;i < crazy_enemies.size();i++){check_collision(p_TempPlayer);crazy_enemies[i]->update();}}
};


#endif