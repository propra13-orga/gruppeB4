#ifndef AGENT_H_
#define AGENT_H_



#include "Verrückter.h"
#include "Pfleger.h"
#include <vector>



class AgentManager
{
private:
	AgentManager(){crazy_enemies.push_back( new Crazy_enemy(1035,731));allPfleger.push_back(new Pfleger(973,112));crazy_enemies.push_back(new Crazy_enemy(411,156));}
	~AgentManager(){}
	vector<Crazy_enemy*>crazy_enemies;//Vektor der alle Crazy enemies speichert
	vector<Pfleger*>allPfleger;
	vector<Crazy_enemy*>crazy_enemiesToDelete;
public:
	static AgentManager & get_AgentManager(){static AgentManager Instance; return Instance;}
	void render(SDL_Rect camera);
	void check_collision(Player * p_TempPlayer,int durchlaufvariable);
	void update(Player * p_TempPlayer);
	void weaken_Bots(Player * p_TempPlayer);
};


#endif