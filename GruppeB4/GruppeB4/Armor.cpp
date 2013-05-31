#include "Armor.h"




	void Armor::set_Heavy(){
	
		this->CURRENT_ARMOR = HEAVY;		//Schwere Rüstung mit 200LP, also 200LP als MAX Wert, wenn angezogen!
	}

	void Armor::set_Mid(){
	
		this->CURRENT_ARMOR = MID;			//Mittlere Rüstung mit 150LP, also 150LPals MAX Wert, wenn angezogen!
	}

	void Armor::set_Weak(){
		
		this->CURRENT_ARMOR = WEAK;			//Leichte Rüstung mit 120LP, also 120LP als MAX Wert, wenn angezogen!
	}
