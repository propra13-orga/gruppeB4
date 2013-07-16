#include "S_Resourcemanager.h"
#include "Player.h"
#include "globals.h"
#include "Vector2D.h"



#ifndef WEAPON_H
#define WEAPON_H



class Weapon{
private:
	WEAPON_TYPE CURRENT_WEAPON;		///angelegte Waffe
	MultiplayerStructs::Vector2D<int> * p_s_Position;
	int i_dmg;						///Schadenswert der Waffe
public:

	Weapon(int x, int y,WEAPON_TYPE WEAPONTOSET){CURRENT_WEAPON = WEAPONTOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}
	//!!!!!! Besser umschreiben in set_Weapon, die dann je nachdem was man will die weappon umstellt, also set_Weapon(WEAPON_TYPE);
	//void set_Weapon(WEAPON_TYPE TEMPITEM){this->CURRENT_WEAPON = TEMPWEAPON;}
	//void setKnife();		//Waffentyp Messer
	//void setPistol();		//Waffentyp Pistole
	//void setDMG();			//Schaden alle Waffen
	//int getDMG();			//um Schadenswerte zu holen
	void set_Position(int x, int y){this->p_s_Position->i_x = x;this->p_s_Position->i_y = y;} /// Setze Waffenposition
	s_Vector * get_Position(){return this->p_s_Position;}
	WEAPON_TYPE get_Weapon(){return this->CURRENT_WEAPON;} /// Gibt aktuellen Waffentyp wieder
	void set_Weapon(WEAPON_TYPE TEMPWEAPON){this->CURRENT_WEAPON = TEMPWEAPON;} /// Setzt aktuellen Waffentyp
	

	






};




#endif 



