#ifndef SKILLTREE_H_
#define SKILLTREE_H_

#include "Weapon.h"

using namespace std;



class Skilltree
{


private:
	Skilltree(){}
	~Skilltree(){}

	Timer * t1_1Timer;
	int i_skillpoint;
	bool b_t11;
	bool overlay_t1_1;


public:
	
	static Skilltree & get_Skilltree(){static Skilltree Instance;return Instance;}
	void set_skillpoint(){i_skillpoint++; cout << "LVL UP" << endl; cout << i_skillpoint << endl;}
	int get_skillpoint();
	void handleInput(SDL_Event &even,bool *skilltreeisopen);
	


	void render();





};







#endif