#ifndef ITEMMANAGER_H_
#define ITEMMANAGER_H_

#include "Vektor.h"

// Klasse berechnet und verwaltet alle Kollision und Objekte, die mit Items zu tun haben, bzw die items sind. Somit wir dhier alles fern vom Spieler geregelt
//Der Spieler soll durch funktionen wie heal() oder loadMana ganz einfach mithilfe des Itemmanagers überprüfen können
//ob er einen solchen trank besitzt und wenn ja, dann soll das mana geladen werden oder der Spieler geheilt.->Klasse ist zukunfstausgelegt, es wird für alle items funktionieren
// VOraussetzung füreine zeitlose anwendung ist die implementierung der Objekte, so soll es eine Klasse Item geben, die im Itemmanager verwaltet wird.SIe enthält einen bool b_IsCarriedByPlayer
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
	ItemManager(){this->uncatcheditems.push_back(Item(950,870,HEAL));this->uncatcheditems.push_back(Item(1200,870,HEAL));}
	~ItemManager(){this->uncatcheditems.pop_back();}
	//enthält zwei Listen die eine Liste ist gefüllt mit Objekten, die der Spieler noch nciht trägt, die aber im level vorhanden sind, 
	//die andere Liste enthält Daten, die der Spieler bereits eingesammelt hat
	list<Item> uncatcheditems;
	list<Item> chatcheditems;
public:
	static ItemManager & get_ItemManager()
	{
		static ItemManager Instance;
		return Instance;
	}
	void set_Item(s_Vector * p_TempPosition){}//Funktion wird vom Botmanager gebraucht um ein item nach Tötung zu setzen, hier wird lediglich die Position des verstorbenen Bots angegeben und schließlich nach einem random prinzip 
	//ein Item an die stelle gesetzt. Dies ist dann ein nicht eingefangenes Item (offensichtlich :) )
	void render(SDL_Rect camera); //Rendert alle Items die nicht vom Spieler eingesammelt sind
	void update(s_Vector * p_Position);//Umfngreichste Funktion der Klasse, hier wird zunächst überprüft, ob der Spieler ein neues Item berührt hat.
	//Danach wird das Item in die Liste der catchedItems aufgenommen, ist bereits eine bestimmte Anzahl dieser Items vorhanden, so wird das Item nicht aufgenommen und bleibt auf dem Boden liegen, es bleibt also in den
	//uncatched items. Schliesslich soll am Ende alles sauber aufgeräumt sein und der Spieler bekommt auch alles, was er sich holt
	bool find(/*ItemType*/){return false;} // Man hätte auch den Standard der STL nehmen können allerdings ist unser umgang damit doch sehr speziell.
	//Falls die listen im privatebereich bleiben muss eine Funktion her, die nach dem element sucht und einen wahrheitswert zurückgibt, falls dieses Element vorhanden ist.
	void kill_Item(/*ItemType*/){}//Funktion ist dafür da um ein item was benutzt wurde auch wieder zu löschen, dabei wird das Firt_Fit prinzip angewendet. Es ist ohne belang welche Position unser Item hat wichtig ist nur der richtige ItemType
	void reinitialize(){chatcheditems.clear();uncatcheditems.clear();}//Funktion um einfach alle Listen komplett zu leeren und neu zu erstellen
	void anzeigen();


};





#endif