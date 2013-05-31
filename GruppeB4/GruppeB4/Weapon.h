#include "Resourcemanager.h"
#include "Player.h"


#ifndef WEAPON_H
#define WEAPON_H


enum WEAPON_TYPE {KNIFE,PISTOL}; //zu globals hinzufügen!!!!!!!!!!!!!!!!!!!!!!!!!!!


class Weapon{
private:
	WEAPON_TYPE CURRENT_WEAPON;		//angelegte Waffe

	int i_dmg;
public:
	void setKnife();		//Waffentyp Messer
	void setPistol();		//Waffentyp Pistole
	void setDMG();			//Schaden alle Waffen
	int getDMG();			//um Schadenswerte zu holen

	

	






};




#endif 



