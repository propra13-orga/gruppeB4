#include "Resourcemanager.h"
#include "Vektor.h"
#ifndef NPC2_H
#define NPC2_H

class Player;

class NPC2 {


private:
	s_Vector* p_s_Position;
	s_Vector* p_s_SecondPosition;


public:



	static NPC2 & get_NPC2()
	{
		static NPC2 Instance;
		return Instance;
	}

	NPC2(){p_s_Position = new s_Vector; p_s_Position->i_x = 120; p_s_Position->i_y = 450;}
	~NPC2(){delete p_s_Position;}


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