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

	WeaponManager(){this->uncatchedweapons.push_back(Weapon(800,870,MELEE));}
	~WeaponManager(){}

	list<Weapon> uncatchedweapons;
	list<Weapon> catchedweapons;

public:


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
	void show();




};




















#endif