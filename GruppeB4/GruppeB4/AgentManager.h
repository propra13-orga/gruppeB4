#ifndef AGENTMANAGER_H_
#define AGENTMANAGER_H_

#include "Verrückter.h"
#include "Player.h"
#include <vector>

class AgentManager
{
public:
	vector<Crazy_enemy*>crazy_enemies;
	AgentManager(){crazy_enemies.push_back( new Crazy_enemy(400,250));}
	~AgentManager(){delete crazy_enemies[0];}
	void render(SDL_Rect camera){for(int i = 0;i < crazy_enemies.size();i++){crazy_enemies[i]->render( camera);}}
	void check_collision(Player * p_TempPlayer);
	void update(Player * p_TempPlayer){check_collision(p_TempPlayer);}
};


#endif