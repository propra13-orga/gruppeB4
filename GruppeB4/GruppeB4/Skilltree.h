#ifndef SKILLTREE_H_
#define SKILLTREE_H_

#include "Weapon.h"

using namespace std;


class Player;

class Skilltree
{


private:
	Skilltree(){t1_1Timer = new Timer();t1_2Timer = new Timer();t1_3Timer = new Timer;t1_4Timer = new Timer();t1_5Timer = new Timer();overlayTimer = new Timer();}
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
	Timer * t1_1Timer;
	Timer * t1_2Timer;
	Timer * t1_3Timer;
	Timer * t1_4Timer;
	Timer * t1_5Timer;
	Timer * overlayTimer;


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