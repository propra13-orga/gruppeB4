#pragma once

#include "C_Block.h"
#include <list>
#include <iostream>
#include "globals.h"

class S_CollisibalObjectManager
{
public:
	enum OBJECTTYPE {Block100x100};
private:
	std::list<C_Block> Blocklist;

	S_CollisibalObjectManager(){}
	~S_CollisibalObjectManager(){}
	S_CollisibalObjectManager(const S_CollisibalObjectManager &){}
public:
	static S_CollisibalObjectManager & get_CManager(){static S_CollisibalObjectManager Instance;return Instance;}
	void set_Object(OBJECTTYPE CURRENTOBJECT,int x, int y);
	list<C_Block> & get_BlockList(){return Blocklist;}
	void show_Insertions();
	void render();
	void delete_lastMember(){Blocklist.pop_back();}
};