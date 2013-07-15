#ifndef EPMANAGER_H_
#define EPMANAGER_H_



#include "Skilltree.h"




class EPManager
{

private:
	EPManager(){bool lvl_up = true; OverlayTimer = new Timer;}
	~EPManager(){}

	Timer * OverlayTimer;
	int i_ep;
	int i_lvl;
	bool lvl_up;
	
	
public:
	static EPManager & get_EPManager(){static EPManager Instance;return Instance;}
	void clear_Ep();
	void render();
	int get_Ep(){return i_ep;}
	void Set_Ep(int specep);
	int get_level();
	bool level_up(){return lvl_up;}
	


	void carry_point();






};

















#endif