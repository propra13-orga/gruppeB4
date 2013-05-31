#ifndef AGENTMANAGER_H_
#define AGENTMANAGER_H_

#include "Verrückter.h"
#include <vector>

class AgentManager
{
public:
	Crazy_enemy * p_Crazy_Enemy;
	Crazy_enemy * p_Crazy_Enemy2;
	AgentManager(){p_Crazy_Enemy = new Crazy_enemy();p_Crazy_Enemy2 = new Crazy_enemy(700,100);}
	~AgentManager(){delete p_Crazy_Enemy;delete p_Crazy_Enemy2;}
	void render(){p_Crazy_Enemy->render();p_Crazy_Enemy2->render();}
};


#endif