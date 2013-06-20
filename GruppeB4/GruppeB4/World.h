#ifndef WORLD_H_
#define WORLD_H_

#include "Resourcemanager.h"
#include "Player.h"
#include "LevelSegment.h"
#include "Verrückter.h"
#include "FinalBoss.h"
#include "AgentManager.h"
#include "Overlay.h"
#include "ItemManager.h"
#include "WeaponManager.h"
#include "MoneyManager.h"
#include "Shop.h"
#include "NPC1.h"

class World
{
private:
	Player * p_Player1;
	LevelSegmente * p_Segmente;
	SDL_Rect Camera;
	LEVEL_LOADED CURRENTLEVEL;//Hier entsteht eine Enumeration die gesetzt wird um zu überprüfen, welches Level geladen ist
	bool LevelToSet;
public:
	World(int i_x,int i_y){CURRENTLEVEL = LEVEL3;p_Player1 = new Player(i_x,i_y);p_Segmente = new LevelSegmente();Camera.w = 900; Camera.h = 600;LevelToSet = true;}
	~World(){delete p_Player1;}
	void set_Camera();
	SDL_Rect get_Camera(){return Camera;}
	void render_Win(bool * tempmenue);
	void update();
	void handle_Event(SDL_Event &even);
	void render(bool * tempmenue,Timer * deltaTime);
	bool collision_Detection(){if(p_Player1->collision_Detection(this->p_Segmente,this->CURRENTLEVEL)){return true;}}
	Player * get_Player(){return p_Player1;}
	LevelSegmente * get_LevelSegmente(){return p_Segmente;}

	//initialisierungsfunktionen der einzelnen Level

	void initialize_Level();

	//Ändern desaktuellen Levels

	void try_swapLevel();
	
};

#endif