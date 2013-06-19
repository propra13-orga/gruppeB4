#ifndef PRINCESS_H_

#define PRINCESS_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "Player.h"



class FinalBoss
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_StartPosition;
	status e_walkstatus;
	bool transformed;
public:
	FinalBoss(){p_s_Position = new s_Vector; p_s_Position->i_x = 1490; p_s_Position->i_y = 120;p_s_StartPosition = new s_Vector;p_s_StartPosition->i_x = p_s_Position->i_x;p_s_StartPosition->i_y = p_s_Position->i_y;transformed = false;}
	~FinalBoss(){delete p_s_Position;}
	s_Vector* get_Position(){return this->p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	void render(SDL_Rect camera);
	void update();

};


	

#endif