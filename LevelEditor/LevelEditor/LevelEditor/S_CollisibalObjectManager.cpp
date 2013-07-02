#include "CollisibalObjectManager.h"


void S_CollisibalObjectManager::set_Object(OBJECTTYPE CURRENTOBJECT,int x, int y)
{
	if (CURRENTOBJECT == Block100x100)
	{
		this->Blocklist.push_back(C_Block(x,y));
	}

}

void S_CollisibalObjectManager::show_Insertions()
{
	for(list<C_Block>::iterator myIter = this->Blocklist.begin();myIter != this->Blocklist.end();++myIter)
	{
		cout << "ein Objekt" << endl;
	}
}

void S_CollisibalObjectManager::render()
{
	for(list<C_Block>::iterator myIter = this->Blocklist.begin();myIter != this->Blocklist.end();++myIter)
	{
		myIter->render();
	}
}