#include "Resourcemanager.h"
#include "Player.h"
#include "globals.h"

#ifndef WEAPON_H
#define WEAPON_H



class Weapon{
private:
	WEAPON_TYPE CURRENT_WEAPON;		//angelegte Waffe

	int i_dmg;
public:
	//!!!!!! Besser umschreiben in set_Weapon, die dann je nachdem was man will die weappon umstellt, also set_Weapon(WEAPON_TYPE);
	void setKnife();		//Waffentyp Messer
	void setPistol();		//Waffentyp Pistole
	void setDMG();			//Schaden alle Waffen
	int getDMG();			//um Schadenswerte zu holen

	

	






};




#endif 



