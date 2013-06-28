#ifndef SKILLTREE_H_
#define SKILLTREE_H_

#include "Weapon.h"

using namespace std;


class Player;

class Skilltree
{


private:
	Skilltree(){overlayTimer = new Timer();b_t11 = false; b_t12 = false; b_t13 = false; b_t14 = false; b_t15 = false;}
	~Skilltree(){}

	
	int i_skillpoint;
	bool b_t11;
	bool b_t1_1_over;
	bool b_t1_2_over;
	bool b_t12;
	bool b_t13;
	bool b_t1_3_over;
	bool b_t14;
	bool b_t1_4_over;
	bool b_t15;
	bool b_t1_5_over;
	SDL_Event even;
	Player * p_Player;
	Timer * overlayTimer;
	bool b_nopoints;


public:
	
	static Skilltree & get_Skilltree(){static Skilltree Instance;return Instance;}
	void set_skillpoint(){i_skillpoint++; cout << "LVL UP" << endl; cout << i_skillpoint << endl;}
	int get_skillpoint();
	void handleInput(SDL_Event &even,bool *skilltreeisopen);
	void administrate_skills(Player *p_Player,bool b_t11);

	
	void render(SDL_Event &even);
	void check_skilled();





};







#endif