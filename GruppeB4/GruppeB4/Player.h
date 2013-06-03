#ifndef PLAYER_H_
#define PLAYER_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "LevelSegment.h"
#include "globals.h"
#include "Timer.h"
#include "ItemManager.h"

enum status {PSY_RIGHT,PSY_LEFT,PSY_UP,PSY_DOWN};

class Player
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;
	bool b_PlayerIsWalkingRight;
	bool b_PlayerIsWalkingLeft;
	bool b_PlayerIsWalkingUp;
	bool b_PlayerIsWalkingDown;
	int i_health;
	int i_lives;

	//Animationsdateien

	int i_frame;
	status e_currentwalkstatus;

public:

	//Konstruktoren

	Player():i_health(400){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = 0; p_s_Position->i_y = 0; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;e_currentwalkstatus = PSY_DOWN;this->i_frame = 0;}
	Player(int i_x,int i_y):i_health(400){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = i_x; p_s_Position->i_y = i_y; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;e_currentwalkstatus = PSY_DOWN;this->i_frame = 0;}
	~Player(){delete p_s_Position;delete p_s_Velocity;}
	// simple FUnktionen für den Zugriff auf den privaten Bereich
	s_Vector * get_Position(){return  p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	s_Vector * get_Velocity(){return  p_s_Velocity;}
	void  set_Velocity(int i_x,int i_y){this->p_s_Velocity->i_x = i_x;this->p_s_Velocity->i_y = i_y;}
	void set_Health(int health){this->i_health = health;}
	int get_Health() const {return i_health;}
	void reinitialize();

	//Itembenutzung

	void heal();//Funktion Heilt den Spieler falls in der Liste der catchedItems des Itemmanagers ein heiltrank vorhanden ist
	void loadMana();//Funktion läd mana des spielers, falls in der Liste der Catched items ein Manatrank vorhanden ist


	//Funktionen die für die Bewegung und das Abbilden des Spielers erstellt sind
	bool collision_Detection(LevelSegmente * p_TempSeg);
	void update();
	void render(bool * tempmenue,Timer * deltaTime,SDL_Rect cam);
	void handle_Input(SDL_Event &even);
};

#endif
