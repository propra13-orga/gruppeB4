#ifndef PRINCESS_H_

#define PRINCESS_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "Timer.h"

class Player;

class FinalBoss
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_StartPosition;
	s_Vector * p_s_Velocity;
	status e_walkstatus;
	Timer * AnimationTimer;
	Timer * AttackTimer;
	bool transformed;
	bool isactivated;
	bool raged;
public:
	FinalBoss(){p_s_Position = new s_Vector; p_s_Position->i_x = 1490; p_s_Position->i_y = 120;p_s_StartPosition = new s_Vector;p_s_StartPosition->i_x = p_s_Position->i_x;p_s_StartPosition->i_y = p_s_Position->i_y;transformed = false;p_s_Velocity = new s_Vector();p_s_Velocity->i_x = -2;p_s_Velocity->i_y = 0;AnimationTimer = new Timer();AttackTimer = new Timer();raged = false;}
	~FinalBoss(){delete p_s_Position;}
	s_Vector* get_Position(){return this->p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	bool get_isactivated(){return isactivated;}
	void set_isactivated(bool t){isactivated = t;}
	void render(SDL_Rect camera);
	void update(Player * p_Player);

};


	

#endif