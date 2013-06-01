#ifndef AGENTMANAGER_H_
#define AGENTMANAGER_H_

#include "Verrückter.h"
#include <vector>

class AgentManager
{
public:
	Crazy_enemy * p_Crazy_Enemy;
	AgentManager(){p_Crazy_Enemy = new Crazy_enemy(400,250);}
	~AgentManager(){delete p_Crazy_Enemy;}
	void render(){p_Crazy_Enemy->render();}
};


#endif