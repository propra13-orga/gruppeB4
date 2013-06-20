#ifndef AGENT_H_
#define AGENT_H_



#include "Verrückter.h"
#include "Pfleger.h"
#include "FinalBoss.h"
#include <vector>



class AgentManager
{
private:
	AgentManager(){p_BossManager = new FinalBoss();}
	~AgentManager(){}
	vector<Crazy_enemy*>crazy_enemies;//Vektor der alle Crazy enemies speichert
	vector<Pfleger*>allPfleger;
	vector<Crazy_enemy*>crazy_enemiesToDelete;
	FinalBoss * p_BossManager;
public:
	static AgentManager & get_AgentManager(){static AgentManager Instance; return Instance;}
	void render(SDL_Rect camera,LEVEL_LOADED TEMPLEVEL);
	void check_collision(Player * p_TempPlayer,int durchlaufvariable);
	void update(Player * p_TempPlayer,LEVEL_LOADED,SDL_Rect camera);
	void weaken_Bots(Player * p_TempPlayer);
	void set_Bot(int x, int y,BOT_TYPE TEMPTYPE);
	void reinitialize(){crazy_enemies.clear();crazy_enemiesToDelete.clear();allPfleger.clear();}
	FinalBoss * get_Boss(){return p_BossManager;}
};


#endif