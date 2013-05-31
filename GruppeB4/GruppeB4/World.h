#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"
#include "Verrückter.h"
#include "Princess.h"
#include "AgentManager.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
	Crazy_enemy * p_Crazy_Enemy;
	Crazy_enemy * p_Crazy_Enemy2;
	Princess * p_Princess;
	AgentManager * BotManager;
public:
	World(int i_x,int i_y){p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();p_Princess = new Princess();BotManager = new AgentManager;}
	~World(){delete p_Player1;delete p_Princess;}
	void update();
	void handle_Event(SDL_Event &even);
	void render(bool * tempmenue,Timer * deltaTime);
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente,this->BotManager->p_Crazy_Enemy->get_Position(),this->BotManager->p_Crazy_Enemy2->get_Position()) == true){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}
};

#endif