#ifndef AGENTMANAGER_H_
#define AGENTMANAGER_H_

#include "Verrückter.h"
#include "Player.h"
#include "Pfleger.h"
#include <vector>

class AgentManager
{
private:
	vector<Crazy_enemy*>crazy_enemies;//Vektor der alle Crazy enemies speichert
	vector<Pfleger*>allPfleger;
	AgentManager(){crazy_enemies.push_back( new Crazy_enemy(1035,731));allPfleger.push_back(new Pfleger(973,112));crazy_enemies.push_back(new Crazy_enemy(411,156));}
	~AgentManager(){delete crazy_enemies[0];}
	
public:
	static AgentManager & get_AgentManager(){static AgentManager Instance; return Instance;}
	void render(SDL_Rect camera){for(unsigned int i = 0;i < crazy_enemies.size();i++){crazy_enemies[i]->render( camera);}allPfleger[0]->render(camera);}
	void check_collision(Player * p_TempPlayer,int durchlaufvariable);
	void update(Player * p_TempPlayer){for(unsigned int i = 0;i < crazy_enemies.size();i++){check_collision(p_TempPlayer,i);crazy_enemies[i]->update();}allPfleger[0]->update(p_TempPlayer);}
};


#endif