#include "Armor.h"




	void Armor::set_Heavy(){
	
		this->CURRENT_ARMOR = HEAVY;		//Schwere R�stung mit 200LP, also 200LP als MAX Wert, wenn angezogen!
	}

	void Armor::set_Mid(){
	
		this->CURRENT_ARMOR = MID;			//Mittlere R�stung mit 150LP, also 150LPals MAX Wert, wenn angezogen!
	}

	void Armor::set_Weak(){
		
		this->CURRENT_ARMOR = WEAK;			//Leichte R�stung mit 120LP, also 120LP als MAX Wert, wenn angezogen!
	}
