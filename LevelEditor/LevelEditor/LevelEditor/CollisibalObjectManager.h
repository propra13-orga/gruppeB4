#ifndef COLLISIOBALOBJECTMANAGER_H_
#define COLLISIOBALOBJECTMANAGER_H_

#include "CBlock.h"
#include <list>
#include <iostream>
#include "globals.h"

using namespace std;


class S_CollisibalObjectManager
{
private:
	list<C_Block> Blocklist;

	S_CollisibalObjectManager(){}
	~S_CollisibalObjectManager(){}
	S_CollisibalObjectManager(const S_CollisibalObjectManager &){}
public:
	static S_CollisibalObjectManager & get_CManager(){static S_CollisibalObjectManager Instance;return Instance;}
	void set_Object(OBJECTTYPE CURRENTOBJECT,int x, int y);
	void show_Insertions();
	void render();
};


#endif