#ifndef PLAYER_H_
#define PLAYER_H_

class AgentManager;

#include "Vektor.h"
#include "Resourcemanager.h"
#include "LevelSegment.h"
#include "globals.h"
#include "Timer.h"
#include "ItemManager.h"
#include "MoneyManager.h"
#include "WeaponManager.h"

class AgentManager;
class World;


class Player
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;
	bool b_PlayerIsWalkingRight;
	bool b_PlayerIsWalkingLeft;
	bool b_PlayerIsWalkingUp;
	bool b_PlayerIsWalkingDown;
	bool rageModeToggled;
	bool disableallabilities;
	Timer * RageModeTimer;
	int i_health;
	int i_lives;
	int i_mana;
	int i_maxhealth;
	//Animationsdateien

	int i_frame;
	status e_currentwalkstatus;

public:

	//Konstruktoren

	Player():i_health(400){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = 0; p_s_Position->i_y = 0; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;e_currentwalkstatus = PSY_DOWN;this->i_frame = 0;rageModeToggled =  false;disableallabilities = false;}
	Player(int i_x,int i_y):i_health(400),i_mana(100){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = i_x; p_s_Position->i_y = i_y; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;RageModeTimer = new Timer();e_currentwalkstatus = PSY_DOWN;this->i_frame = 0;rageModeToggled = false;disableallabilities = false;i_maxhealth = 400;}
	~Player(){delete p_s_Position;delete p_s_Velocity;}
	// simple FUnktionen für den Zugriff auf den privaten Bereich
	s_Vector * get_Position(){return  p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	s_Vector * get_Velocity(){return  p_s_Velocity;}
	void  set_Velocity(int i_x,int i_y){this->p_s_Velocity->i_x = i_x;this->p_s_Velocity->i_y = i_y;}
	void set_Health(int health){this->i_health = health;}
	void set_Mana(int mana){this->i_mana = mana;}
	int get_Health() const {return i_health;}
	int get_Mana() const {return i_mana;}
	bool get_disable(){return disableallabilities;}
	void set_disable(bool t){this->disableallabilities = t;}
	status get_WalkStatus(){return e_currentwalkstatus;}
	void reinitialize(LEVEL_LOADED CURRENTLEVEL);
	int health_cap(){return i_maxhealth;}
	void set_health_cap(int max){this->i_maxhealth =max;}


	//Itembenutzung

	void heal();//Funktion Heilt den Spieler falls in der Liste der catchedItems des Itemmanagers ein heiltrank vorhanden ist
	void loadMana();//Funktion läd mana des spielers, falls in der Liste der Catched items ein Manatrank vorhanden ist
	void setRageMode();//Hier wird der RageMode des Spielers angestellt

	void attack();

	//Funktionen die für die Bewegung und das Abbilden des Spielers erstellt sind
	bool collision_Detection(LevelSegmente * p_TempSeg,LEVEL_LOADED CURRENTLEVEL);
	void update();
	void render(bool * tempmenue,Timer * deltaTime,SDL_Rect cam,LEVEL_LOADED CURRENTLEVEL,World * p_TempWorld);
	void handle_Input(SDL_Event &even);
};

#endif
