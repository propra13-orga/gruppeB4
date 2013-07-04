#ifndef COLLISIOBALOBJECTMANAGER_H_
#define COLLISIOBALOBJECTMANAGER_H_

#include "CBlock.h"
#include <list>
#include <iostream>
#include "globals.h"

class S_LevelEditor;

using namespace std;


class S_CollisibalObjectManager
{
private:
	list<C_Block> Blocklist;
	list<C_Block> Workinglist;

	S_CollisibalObjectManager(){}
	~S_CollisibalObjectManager(){}
	S_CollisibalObjectManager(const S_CollisibalObjectManager &){}
public:
	static S_CollisibalObjectManager & get_CManager(){static S_CollisibalObjectManager Instance;return Instance;}
	void set_Object(OBJECTTYPE CURRENTOBJECT,int x, int y);
	C_Block * get_WorkingListsFirstMember();
	void find(int x, int y);//Funktion findet das Element, auf das geklickt wurde und tut es in die Bearbeitungsliste, wenn bearbeitungsliste nicht leer, wird das element us der bearbeitungsliste wieder wie vorher gerendert
	void show_Insertions();
	void forced_pushIntoBlockList();
	void render();
};


#endif