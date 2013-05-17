
#include "Vektor.h"
#include "Resourcemanager.h"
#ifndef ENEMY_H
#define ENEMY_H







class Enemy {


private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;


public:

Enemy(){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector; p_s_Position->i_x = 800; p_s_Position->i_y = 600; p_s_Velocity->i_x = 0; p_s_Velocity->i_y = 0;}
	~Enemy(){delete p_s_Position;delete p_s_Velocity;}

	



	s_Vector* get_Position()
	{
		return this->p_s_Position;
	}

	void  set_Position(int i_x,int i_y)
	
	{
		this->p_s_Position->i_x = i_x;this->p_s_Position->i_y = i_y;
	}


	s_Vector * get_Velocity()
	{
		return  p_s_Velocity;
	}


	void  set_Velocity(int i_x,int i_y)
	{
		this->p_s_Velocity->i_x = i_x;this->p_s_Velocity->i_y = i_y;
	}

	void render();
	void update();

	//void show_enemyStats();

	
	//void get_health();
	//void set_health();

	//void get_enemy();
	//void set_enemy();




};




















#endif