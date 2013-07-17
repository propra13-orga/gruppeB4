#ifndef CBLOCK_H_
#define CBLOCK_H_

#include "CollisiobalObject.h"
#include "Resourcemanager.h"

class C_Block: public CollisibalObject
{
private:
public:
	C_Block(int x,int y):CollisibalObject(x,y){}
	void update(){};
	void render();
};

#endif