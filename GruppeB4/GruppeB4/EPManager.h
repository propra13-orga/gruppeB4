#ifndef EPMANAGER_H_
#define EPMANAGER_H_



#include "Skilltree.h"




class EPManager
{

private:
	EPManager(){}
	~EPManager(){}


	int i_ep;
	int i_lvl;

public:
	static EPManager & get_EPManager(){static EPManager Instance;return Instance;}
	void clear_Ep();
	int get_Ep(){return i_ep;}
	void Set_Ep(int specep);
	int get_level();
	
	void carry_point();






};

















#endif