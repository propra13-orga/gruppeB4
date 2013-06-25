#ifndef SKILLTREE_H_
#define SKILLTREE_H_

#include "Weapon.h"

using namespace std;



class Skilltree
{


private:
	Skilltree(){}
	~Skilltree(){}

	int i_skillpoint;

public:
	
	static Skilltree & get_Skilltree(){static Skilltree Instance;return Instance;}
	void set_skillpoint(){i_skillpoint++; cout << "LVL UP" << endl; cout << i_skillpoint << endl;}
	int get_skillpoint();


	void render(){cout <<"da"<< endl;}





};







#endif