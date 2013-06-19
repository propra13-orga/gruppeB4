#ifndef AGENT_H_
#define AGENT_H_



#include "Verrückter.h"
#include "Pfleger.h"
#include <vector>



class AgentManager
{
private:
	AgentManager(){}
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
	void set_Bot(int x, int y,BOT_TYPE TEMPTYPE);
	void reinitialize(){crazy_enemies.clear();crazy_enemiesToDelete.clear();allPfleger.clear();}
};


#endif