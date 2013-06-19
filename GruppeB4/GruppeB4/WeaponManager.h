#ifndef WEAPON_MANAGER_H
#define WEAPON_MANAGER_H

#include "Resourcemanager.h"
#include "Vektor.h"
#include <list>
#include "globals.h"
#include "Player.h"
#include "Weapon.h"
using namespace std;


class WeaponManager{

private:

	WeaponManager(){}
	~WeaponManager(){}

	list<Weapon> uncatchedweapons;
	list<Weapon> catchedweapons;
public:
	WEAPON_TYPE CURRENT_WEAPON2;




	static WeaponManager & get_WeaponManager()
	{
		static WeaponManager Instance;
		return Instance;
	}


	bool find(WEAPON_TYPE CURRENT_WEAPON);			
	void render(SDL_Rect camera);		//Waffen auf den Boden rendern
	void update(s_Vector * p_Position);			//Spieler kann Waffe aufheben und benutzen, render wird abgebrochen und im Player gehts weiter
	void kill_weapon(WEAPON_TYPE CURRENT_WEAPON);		//Waffe zerstören
	void reinitialize(){catchedweapons.clear();uncatchedweapons.clear();} //Clear
	void reinitializeLevelSwap(){uncatchedweapons.clear();}
	void set_Weapon(int x, int y,WEAPON_TYPE);
	void show();
	void swap_weapon();
	void show_currentWeapon()
		{
		if(CURRENT_WEAPON2 == MELEE)
		{
			cout << "MELEE" << endl;
		}
		if(CURRENT_WEAPON2 == NONE)
		{
			cout << "NONE" << endl;
		}
	}
	


};




















#endif