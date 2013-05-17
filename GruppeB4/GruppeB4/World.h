#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
public:
	World(int i_x,int i_y){p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();}
	~World(){delete p_Player1;}
	void update();
	void handle_event(SDL_Event &even);
	void render();
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente) == true){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}
};

#endif