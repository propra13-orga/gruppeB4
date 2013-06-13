#include "Resourcemanager.h"
#include "Player.h"
#include "globals.h"
#include "Vektor.h"


#ifndef ARMOR_H
#define ARMOR_H


class Armor{
	

private:
	
	ARMOR_TYPE CURRENT_ARMOR;	//für angelegte Rüstung
	s_Vector * p_s_Position;

public:

	Armor(int x, int y,ARMOR_TYPE ARMORTOSET){CURRENT_ARMOR = ARMORTOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}

	void set_Heavy();	//siehe Armor.cpp
	void set_Mid();	//siehe Armor.cpp
	void set_Weak();	//siehe Armor.cpp

	void set_Position(int x, int y){this->p_s_Position->i_x = x;this->p_s_Position->i_y = y;}
	s_Vector * get_Position(){return this->p_s_Position;}
	ARMOR_TYPE get_Armor(){return this->CURRENT_ARMOR;}
	void set_Armor(ARMOR_TYPE TEMPARMOR){this->CURRENT_ARMOR = TEMPARMOR;}


};

#endif