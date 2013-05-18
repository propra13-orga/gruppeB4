#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"
#include "Enemy.h"
#include "Princess.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
	Enemy * p_Crazy_Enemy;
	Princess * p_Princess;
	
public:
	World(int i_x,int i_y){p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();p_Crazy_Enemy = new Enemy();p_Princess = new Princess();}
	~World(){delete p_Player1;delete p_Crazy_Enemy;}
	void update();
	void handle_event(SDL_Event &even);
	void render();
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente) == true){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}
};

#endif