#ifndef PRINCESS_H_

#define PRINCESS_H_

#include "Vektor.h"
#include "Resourcemanager.h"
#include "Player.h"



class FinalBoss
{
private:
	s_Vector * p_s_Position;
public:
	FinalBoss(){p_s_Position = new s_Vector; p_s_Position->i_x = 100; p_s_Position->i_y = 150;}
	~FinalBoss(){delete p_s_Position;}
	s_Vector* get_Position(){return this->p_s_Position;}
	void  set_Position(int i_x,int i_y){this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;}
	bool render(bool * tempmenue,Player * tempplayer,SDL_Rect camera);

};


	

#endif