#ifndef EPMANAGER_H_
#define EPMANAGER_H_


#include "MoneyManager.h"





class EPManager
{

private:
	EPManager(){}
	~EPManager(){}


	int i_ep;

public:
	static EPManager & get_EPManager(){static EPManager Instance;return Instance;}

	int get_Ep(){return i_ep;}
    void Set_Ep(int specep){i_ep = i_ep +specep;cout <<  i_ep << endl;}
	void clear_Ep(){i_ep = 0;}






};

















#endif