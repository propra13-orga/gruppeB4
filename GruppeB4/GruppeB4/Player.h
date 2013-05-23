#ifndef PLAYER_H_
#define PLAYER_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "LevelSegment.h"
#include "globals.h"
enum status {PSY_RIGHT,PSY_LEFT,PSY_UP,PSY_DOWN};

class Player
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;
	bool PlayerIsWalkingRight;
	bool PlayerIsWalkingLeft;
	bool PlayerIsWalkingUp;
	bool PlayerIsWalkingDown;
	int health;

	//Animationsdateien

	int frame;
	status currentwalkstatus;

public:

	//Konstruktoren

	Player():health(100){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = 0; p_s_Position->i_y = 0; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;currentwalkstatus = PSY_DOWN;this->frame = 0;}
	Player(int i_x,int i_y):health(100){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = i_x; p_s_Position->i_y = i_y; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;}
	~Player(){delete p_s_Position;delete p_s_Velocity;}
	// simple FUnktionen f�r den Zugriff auf den privaten Bereich
	s_Vector * get_Position(){return  p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	s_Vector * get_Velocity(){return  p_s_Velocity;}
	void  set_Velocity(int i_x,int i_y){this->p_s_Velocity->i_x = i_x;this->p_s_Velocity->i_y = i_y;}
	void set_Health(int health){this->health = health;}


	//Funktionen die f�r die Bewegung und das Abbilden des Spielers erstellt sind
	bool collision_Detection(LevelSegmente * p_TempSeg,s_Vector * tempposition,s_Vector * tempposition2);
	void update();
	void render(bool * tempmenue);
	void handle_input(SDL_Event &even);
};

#endif
