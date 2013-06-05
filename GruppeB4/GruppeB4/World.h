#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"
#include "Verrückter.h"
#include "FinalBoss.h"
#include "AgentManager.h"
#include "Overlay.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
	FinalBoss * p_BossManager;
	AgentManager * BotManager;
	SDL_Rect Camera;
	LEVEL_LOADED CURRENTLEVEL;//Hier entsteht eine Enumeration die gesetzt wird um zu überprüfen, welches Level geladen ist
public:
	World(int i_x,int i_y){CURRENTLEVEL = LEVEL1;p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();p_BossManager = new FinalBoss();BotManager = new AgentManager(this->CURRENTLEVEL);Camera.w = 900; Camera.h = 600;}
	~World(){delete p_Player1;delete p_BossManager;}
	void set_Camera();
	SDL_Rect get_Camera(){return Camera;}
	void render_Win(bool * tempmenue);
	void update();
	void handle_Event(SDL_Event &even);
	void render(bool * tempmenue,Timer * deltaTime);
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente,this->CURRENTLEVEL)){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}
};

#endif