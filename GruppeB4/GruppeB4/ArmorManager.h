#ifndef ARMOR_MANAGER_H
#define ARMOR_MANAGER_H

#include "Resourcemanager.h"
#include "Vektor.h"
#include <list>
#include "globals.h"
#include "Player.h"
#include "Armor.h"
using namespace std;


class ArmorManager{

private:

	ArmorManager(){}
	~ArmorManager(){}

	list<Armor> uncatchedarmors;
	list<Armor> catchedarmors;

public:


	static ArmorManager & get_ArmorManager()
	{
		static ArmorManager Instance;
		return Instance;
	}


	bool find(ARMOR_TYPE CURRENT_ARMOR);			
	void render(SDL_Rect camera);		//Rüstung auf den Boden rendern
	void update(s_Vector * p_Position);			//Spieler kann Rüstung aufheben und benutzen, render wird abgebrochen und im Player gehts weiter
	void kill_weapon(ARMOR_TYPE CURRENT_ARMOR);		//Rüstung zerstören
	void reinitialize(){catchedarmors.clear();uncatchedarmors.clear();} //Clear
	void show();




};




















#endif