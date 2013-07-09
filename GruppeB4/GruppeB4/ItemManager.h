#ifndef ITEMMANAGER_H_
#define ITEMMANAGER_H_

#include "Vektor.h"

/** Klasse berechnet und verwaltet alle Kollision und Objekte, die mit Items zu tun haben, bzw die items sind. Somit wir dhier alles fern vom Spieler geregelt
*Der Spieler soll durch funktionen wie heal() oder loadMana ganz einfach mithilfe des Itemmanagers ueberpruefen koennen
*ob er einen solchen trank besitzt und wenn ja, dann soll das mana geladen werden oder der Spieler geheilt.->Klasse ist zukunfstausgelegt, es wird für alle items funktionieren
*VOraussetzung fuereine zeitlose anwendung ist die implementierung der Objekte, so soll es eine Klasse Item geben, die im Itemmanager verwaltet wird.SIe enthaelt einen bool b_IsCarriedByPlayer
*und einen ItemTyp also enum ITEMTYPE {MANA,LIFE}
*Diese Klasse ist ein Singleton, da sie nur einmal im Spiel besteht*/



#include "Resourcemanager.h"
#include "globals.h"
#include <list>
#include "Item.h"
#include "Player.h"
#include "EPManager.h"

using namespace std;

class ItemManager
{
private:
	ItemManager(){}
	~ItemManager(){}
	/**enthaelt zwei Listen die eine Liste ist gefuellt mit Objekten, die der Spieler noch nciht traegt, die aber im level vorhanden sind, 
	die andere Liste enthaelt Daten, die der Spieler bereits eingesammelt hat*/
	list<Item> uncatcheditems;
	list<Item> catcheditems;
	
public:
	static ItemManager & get_ItemManager()
	{
		static ItemManager Instance;
		return Instance;
	}
	/**Funktion wird vom Botmanager gebraucht um ein item nach Tötung zu setzen, hier wird lediglich die Position des verstorbenen Bots angegeben und schließlich nach einem random prinzip 
	ein Item an die stelle gesetzt. Dies ist dann ein nicht eingefangenes Item (offensichtlich :) )*/
	void set_Item(s_Vector * p_TempPosition,ITEM_TYPE TEMPITEM);
	
	void set_Item(int x, int y,ITEM_TYPE TEMPITEM);
	/**Rendert alle Items die nicht vom Spieler eingesammelt sind*/
	void render(SDL_Rect camera); 
	/**Umfangreichste Funktion der Klasse, hier wird zunaechst ueberprueft, ob der Spieler ein neues Item beruehrt hat.
	Danach wird das Item in die Liste der catchedItems aufgenommen, ist bereits eine bestimmte Anzahl dieser Items vorhanden, so wird das Item nicht aufgenommen und bleibt auf dem Boden liegen, es bleibt also in den
	uncatched items. Schliesslich soll am Ende alles sauber aufgeraeumt sein und der Spieler bekommt auch alles, was er sich holt*/
	void update(s_Vector * p_Position);
	/** Man haette auch den Standard der STL nehmen koennen allerdings ist unser umgang damit doch sehr speziell.
	Falls die listen im privatebereich bleiben muss eine Funktion her, die nach dem element sucht und einen wahrheitswert zurückgibt, falls dieses Element vorhanden ist.*/
	bool find(ITEM_TYPE TEMPITEM); 
	/**Funktion ist dafuer da um ein item was benutzt wurde auch wieder zu loeschen, dabei wird das First_Fit prinzip angewendet. Es ist ohne belang welche Position unser Item hat wichtig ist nur der richtige ItemType*/
	void kill_Item(ITEM_TYPE TEMPITEM);
	/**Funktion um einfach alle Listen komplett zu leeren und neu zu erstellen*/
	void reinitialize(){catcheditems.clear();uncatcheditems.clear();}

	void reinitializeLevelSwap(){uncatcheditems.clear();}
	int get_Amount(ITEM_TYPE);
	void anzeigen();

	void insert_item(ITEM_TYPE tempitem);
};





#endif