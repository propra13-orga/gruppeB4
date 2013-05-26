#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"
#include "Verrückter.h"
#include "Princess.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
	Crazy_enemy * p_Crazy_Enemy;
	Crazy_enemy * p_Crazy_Enemy2;
	Princess * p_Princess;
	
public:
	World(int i_x,int i_y){p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();p_Crazy_Enemy = new Crazy_enemy();p_Princess = new Princess();p_Crazy_Enemy2 = new Crazy_enemy(700,100);}
	~World(){delete p_Player1;delete p_Crazy_Enemy;}
	void update();
	void handle_Event(SDL_Event &even);
	void render(bool * tempmenue,Timer * deltaTime);
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente,this->p_Crazy_Enemy->get_Position(),this->p_Crazy_Enemy2->get_Position()) == true){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}
};

#endif