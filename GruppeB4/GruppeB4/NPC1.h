#include "Resourcemanager.h"
#include "Vektor.h"
#ifndef NPC1_H
#define NPC1_H

class Player;

class NPC1 {


private:
	s_Vector* p_s_Position;


public:



	static NPC1 & get_NPC1()
	{
		static NPC1 Instance;
		return Instance;
	}

	NPC1(){p_s_Position = new s_Vector; p_s_Position->i_x = 780; p_s_Position->i_y = 1030;}
	~NPC1(){delete p_s_Position;}



	s_Vector* get_Position()
	{
		return this->p_s_Position;
	}

	void set_Position(int i_x,int i_y)
	{
		this->p_s_Position->i_x=i_x;this->p_s_Position->i_y=i_y;
	}


	void render(SDL_Rect camera);
	bool PlayCloseToBot(Player * p_TempPlayer);

	
};
#endif