#ifndef ITEMMANAGER_H_
#define ITEMMANAGER_H_

#include "Vektor.h"

// Klasse berechnet und verwaltet alle Kollision und Objekte, die mit Items zu tun haben, bzw die items sind. Somit wir dhier alles fern vom Spieler geregelt
//Der Spieler soll durch funktionen wie heal() oder loadMana ganz einfach mithilfe des Itemmanagers �berpr�fen k�nnen
//ob er einen solchen trank besitzt und wenn ja, dann soll das mana geladen werden oder der Spieler geheilt.->Klasse ist zukunfstausgelegt, es wird f�r alle items funktionieren
// VOraussetzung f�reine zeitlose anwendung ist die implementierung der Objekte, so soll es eine Klasse Item geben, die im Itemmanager verwaltet wird.SIe enth�lt einen bool b_IsCarriedByPlayer
// und einen ItemTyp also enum ITEMTYPE {MANA,LIFE}
//Diese Klasse ist ein Singleton, da sie nur einmal im Spiel besteht



#include "Resourcemanager.h"
#include "globals.h"
#include <list>
#include "Item.h"
#include "Player.h"

using namespace std;

class ItemManager
{
private:
	ItemManager(){}
	~ItemManager(){}
	//enth�lt zwei Listen die eine Liste ist gef�llt mit Objekten, die der Spieler noch nciht tr�gt, die aber im level vorhanden sind, 
	//die andere Liste enth�lt Daten, die der Spieler bereits eingesammelt hat
	list<Item> uncatcheditems;
	list<Item> catcheditems;
	
public:
	static ItemManager & get_ItemManager()
	{
		static ItemManager Instance;
		return Instance;
	}
	void set_Item(s_Vector * p_TempPosition,ITEM_TYPE TEMPITEM);//Funktion wird vom Botmanager gebraucht um ein item nach T�tung zu setzen, hier wird lediglich die Position des verstorbenen Bots angegeben und schlie�lich nach einem random prinzip 
	//ein Item an die stelle gesetzt. Dies ist dann ein nicht eingefangenes Item (offensichtlich :) )
	void set_Item(int x, int y,ITEM_TYPE TEMPITEM);
	void render(SDL_Rect camera); //Rendert alle Items die nicht vom Spieler eingesammelt sind
	void update(s_Vector * p_Position);//Umfngreichste Funktion der Klasse, hier wird zun�chst �berpr�ft, ob der Spieler ein neues Item ber�hrt hat.
	//Danach wird das Item in die Liste der catchedItems aufgenommen, ist bereits eine bestimmte Anzahl dieser Items vorhanden, so wird das Item nicht aufgenommen und bleibt auf dem Boden liegen, es bleibt also in den
	//uncatched items. Schliesslich soll am Ende alles sauber aufger�umt sein und der Spieler bekommt auch alles, was er sich holt
	bool find(ITEM_TYPE TEMPITEM); // Man h�tte auch den Standard der STL nehmen k�nnen allerdings ist unser umgang damit doch sehr speziell.
	//Falls die listen im privatebereich bleiben muss eine Funktion her, die nach dem element sucht und einen wahrheitswert zur�ckgibt, falls dieses Element vorhanden ist.
	void kill_Item(ITEM_TYPE TEMPITEM);//Funktion ist daf�r da um ein item was benutzt wurde auch wieder zu l�schen, dabei wird das Firt_Fit prinzip angewendet. Es ist ohne belang welche Position unser Item hat wichtig ist nur der richtige ItemType
	void reinitialize(){catcheditems.clear();uncatcheditems.clear();}//Funktion um einfach alle Listen komplett zu leeren und neu zu erstellen
	void reinitializeLevelSwap(){uncatcheditems.clear();}
	int get_Amount(ITEM_TYPE);
	void anzeigen();

	void insert_item(ITEM_TYPE tempitem);
};





#endif