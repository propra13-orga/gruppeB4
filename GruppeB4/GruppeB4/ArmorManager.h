#ifndef ARMOR_MANAGER_H
#define ARMOR_MANAGER_H

#include "Resourcemanager.h"
#include "Vektor.h"
#include <list>
#include "globals.h"
#include "Player.h"
#include "Armor.h"
#include "EPManager.h"
using namespace std;

/**  Der ArmorManager kümmert sich um die Verwaltung der Ruestungen*/

class ArmorManager{

private:

	ArmorManager(){}
	~ArmorManager(){}

	list<Armor> uncatchedarmors;	///<Liste der nicht aufgehobene Ruestungen
	list<Armor> catchedarmors;		///<Liste der aufgehobenen Ruestungen

public:


	static ArmorManager & get_ArmorManager()
	{
		static ArmorManager Instance;
		return Instance;
	}


	bool find(ARMOR_TYPE CURRENT_ARMOR); ///Überprüft ob die aktuelle Rüstung sich im Inventar des Spielers befindet.	
	void render(SDL_Rect camera);		///<Ruestung auf den Boden rendern.
	void update(s_Vector * p_Position);			///<Spieler kann Ruestung aufheben und benutzen, render wird abgebrochen und im Player gehts weiter
	void kill_armor(ARMOR_TYPE CURRENT_ARMOR);		///<Ruestung zerstoeren.
	void reinitialize(){catchedarmors.clear();uncatchedarmors.clear();} ///Loescht Ruestungslisten.
	void show(){for(list<Armor>::iterator myIter = uncatchedarmors.begin();myIter != uncatchedarmors.end();++myIter){ cout << "Element" << endl;}} ///<Geht Ruestungslisten durch.
	void set_Armor(ARMOR_TYPE TEMPARMOR,int x, int y){uncatchedarmors.push_back(Armor(x,y,TEMPARMOR));} ///<Setzt Ruestungstyp.
	ARMOR_TYPE get_Armor(); ///<zieht die benoetigte Ruestung aus der Liste der aufgehobene Ruestungen.



};




















#endif