#include "Weapon.h"
#include <iostream>
#include <string>





void Weapon::setKnife(){

	this->CURRENT_WEAPON = KNIFE;		//Messer anlegen

}


void Weapon::setPistol(){

	this->CURRENT_WEAPON = PISTOL;		//Pistole anlegen

}
void Weapon::setDMG(){
	
	if(this->CURRENT_WEAPON == KNIFE){
	
		this->i_dmg=30;		// 30 Schadenspukte bei Messer-Stich, bei 90LP des Standart Gegners -->3 Hits = KILL
	}

	if(this->CURRENT_WEAPON == PISTOL){
	
		this->i_dmg=45;		// 45 Schadenspunkte bei Pistolen-Schuss bei 90LP des Standard Gegners --> 2 Hits = KILL
	}

}

int Weapon::getDMG(){

	return this->i_dmg;		// Schadenspunkte holen
}




