#ifndef PLAYER_H_
#define PLAYER_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "LevelSegment.h"

class Player
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;
	bool PlayerIsWalkingRight;
	bool PlayerIsWalkingLeft;
	bool PlayerIsWalkingUp;
	bool PlayerIsWalkingDown;
public:

	//Konstruktoren

	Player(){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = 0; p_s_Position->i_y = 0; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;}
	Player(int i_x,int i_y){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = i_x; p_s_Position->i_y = i_y; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;}
	~Player(){delete p_s_Position;delete p_s_Velocity;}
	// simple FUnktionen für den Zugriff auf den privaten Bereich
	s_Vector * get_Position(){return  p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	s_Vector * get_Velocity(){return  p_s_Velocity;}
	void  set_Velocity(int i_x,int i_y){this->p_s_Velocity->i_x = i_x;this->p_s_Velocity->i_y = i_y;}


	//Funktionen die für die Bewegung und das Abbilden des Spielers erstellt sind
	bool collision_Detection(LevelSegmente * p_TempSeg);
	void update();
	void render();
	void handle_input(SDL_Event &even);
};

#endif
