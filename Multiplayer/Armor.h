#include "Resourcemanager.h"
#include "Player.h"
#include "globals.h"
#include "Vektor.h"
#include "NPC1.h"


#ifndef ARMOR_H
#define ARMOR_H



class Armor{
private:
	ARMOR_TYPE CURRENT_ARMOR;		
	s_Vector * p_s_Position;

public:

	Armor(int x, int y,ARMOR_TYPE ARMORTOSET){CURRENT_ARMOR = ARMORTOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}
	void set_Position(int x, int y){this->p_s_Position->i_x = x;this->p_s_Position->i_y = y;} ///Setzt Ruestungsposition
	s_Vector * get_Position(){return this->p_s_Position;}
	ARMOR_TYPE get_Armor(){return this->CURRENT_ARMOR;}///Gibt aktuellen Ruestungstyp wieder
	void set_Armor(ARMOR_TYPE TEMPARMOR){this->CURRENT_ARMOR = TEMPARMOR;}///Setzt aktuelle Ruestung
	

	






};




#endif 



