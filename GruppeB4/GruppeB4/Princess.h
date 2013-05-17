#ifndef PRINCESS_H_

#define PRINCESS_H_

#include "Vektor.h"
#include "Resourcemanager.h"



class Princess{






private:

	s_Vector * p_s_Position;
	

public:


	Princess(){p_s_Position = new s_Vector; p_s_Position->i_x = 150; p_s_Position->i_y = 100;}
	~Princess(){delete p_s_Position;}
	





		s_Vector* get_Position(){
	
	
	
			 return this->p_s_Position;
	
	}



	void  set_Position(int i_x,int i_y)
	
	{
			this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;
	}



	void render();

};


	

#endif