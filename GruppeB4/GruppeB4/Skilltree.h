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
	bool b_t15;					// Bools für die einezelnen Talente
	bool b_t1_5_over;
	bool b_skilled;
	bool b_t2_1_over;
	bool b_t21;
	bool b_t2_2_over;
	bool b_t22;
	bool b_t2_3_over;
	bool b_t23;
	bool b_t3_1_over;
	bool b_t31;
	bool b_t3_2_over;
	bool b_t32;
	bool b_t4_1_over;
	bool b_t41;
	SDL_Event even;
	Player * p_Player;
	Timer * overlayTimer;
	bool b_nopoints;
	bool b_not_yet_t2_1;
	bool b_not_yet_t2_2;
	bool b_not_yet_t2_3;// Bool zur Überprüfung der Reihenfolge der einzelnen Talente
	bool b_not_yet_t3_1;
	bool b_not_yet_t3_2;
	bool b_lvl_up;


public:
	
	static Skilltree & get_Skilltree(){static Skilltree Instance;return Instance;}
	void set_skillpoint(){i_skillpoint++; cout << "LVL UP" << endl; cout << i_skillpoint << endl; overlayTimer->start(); b_lvl_up = true;}
	int get_skillpoint();
	void handleInput(SDL_Event &even,bool *skilltreeisopen);
	void administrate_skills(Player *p_Player,bool b_t11);
	bool t1_1(){return b_t11;}
	bool t1_2(){return b_t12;}
	bool t1_3(){return b_t13;}
	bool t1_4(){return b_t14;}
	bool t1_5(){return b_t15;}
	bool t2_1(){return b_t21;}		//Funktionen um einfach aus anderen Funktionen Zugriff auf die Talente zu nehmen
	bool t2_2(){return b_t22;}
	bool t2_3(){return b_t23;}
	bool t3_1(){return b_t31;}
	bool t3_2(){return b_t32;}
	

	
	void render(SDL_Event &even); //Standard render()
	void render2();
	void check_skilled();





};







#endif