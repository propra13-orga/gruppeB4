#ifndef WEAPON_MANAGER_H
#define WEAPON_MANAGER_H
#include "Resourcemanager.h"
#include "Vektor.h"


class WeaponManager{
private:

	WeaponManager(){}
	~WeaponManager(){}


public:


	static WeaponManager & get_WeaponManager()
	{
		static WeaponManager Instance;
		return Instance;
	}


	bool find			
	void render();			//Waffen auf den Boden rendern
	void update();			//Spieler kann Waffe aufheben und benutzen, render wird abgebrochen und im Player gehts weiter
	void kill_weapon();		//Waffe zerstören
	void reinitialize(){}; //Clear




}




















#endif