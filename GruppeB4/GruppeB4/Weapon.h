#include "Resourcemanager.h"
#include "Player.h"
#include "globals.h"
#include "Vektor.h"
#include "NPC1.h"


#ifndef WEAPON_H
#define WEAPON_H



class Weapon{
private:
	WEAPON_TYPE CURRENT_WEAPON;		//angelegte Waffe
	s_Vector * p_s_Position;

	int i_dmg;
public:

	Weapon(int x, int y,WEAPON_TYPE WEAPONTOSET){CURRENT_WEAPON = WEAPONTOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}
	//!!!!!! Besser umschreiben in set_Weapon, die dann je nachdem was man will die weappon umstellt, also set_Weapon(WEAPON_TYPE);
	//void set_Weapon(WEAPON_TYPE TEMPITEM){this->CURRENT_WEAPON = TEMPWEAPON;}
	//void setKnife();		//Waffentyp Messer
	//void setPistol();		//Waffentyp Pistole
	//void setDMG();			//Schaden alle Waffen
	//int getDMG();			//um Schadenswerte zu holen
	void set_Position(int x, int y){this->p_s_Position->i_x = x;this->p_s_Position->i_y = y;}
	s_Vector * get_Position(){return this->p_s_Position;}
	WEAPON_TYPE get_Weapon(){return this->CURRENT_WEAPON;}
	void set_Weapon(WEAPON_TYPE TEMPWEAPON){this->CURRENT_WEAPON = TEMPWEAPON;}
	

	






};




#endif 



