#include "Resourcemanager.h"
#include "Player.h"


#ifndef ARMOR_H
#define ARMOR_H

enum ARMOR_TYPE{HEAVY,MID,WEAK}; //in globals einf�gen!!!!!!!!!!!!!!!!!!!


class Armor{
	

private:
	
	ARMOR_TYPE CURRENT_ARMOR;	//f�r angelegte R�stung
	

public:



	void set_Heavy();	//siehe Armor.cpp
	void set_Mid();		//siehe Armor.cpp
	void set_Weak();	//siehe Armor.cpp



};

#endif