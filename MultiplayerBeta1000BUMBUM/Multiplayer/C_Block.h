#include "Collidable Object.h"
#include "S_Resourcemanager.h"

class C_Block: public MultiplayerLowClass::CollisibalObject
{
private:
public:
	C_Block(int x,int y):CollisibalObject(x,y){}
	void update(){};
	void render();
};