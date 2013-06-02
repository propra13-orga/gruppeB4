#include "Resourcemanager.h"
#include "Vektor.h"
#ifndef NPC1_H
#define NPC1_H

class NPC1 {


private:
	s_Vector* p_s_Position;


public:

	NPC1(){p_s_Position = new s_Vector; p_s_Position->i_x = 0; p_s_Position->i_y = 0;}
	~NPC1(){delete p_s_Position;}



	s_Vector* get_Position()
	{
		return this->p_s_Position
	}

	void set_Position(int i_x,int i_y)
	{
		this->p_s_Position->i_x=i_x;this->p_s_Position->i_y=i_y;
	}

	
}
#endif