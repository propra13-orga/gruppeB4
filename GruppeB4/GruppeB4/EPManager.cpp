#include "EPManager.h"




void EPManager::clear_Ep(){
	i_ep = 0;
	
}


void EPManager::Set_Ep(int speccep)
{

	i_ep = i_ep +speccep;
	cout <<  i_ep << endl;
	if(i_ep >=125)
	{
		EPManager::get_EPManager().clear_Ep();
		Skilltree::get_Skilltree().set_skillpoint();
		i_lvl++;
		
	}

}


int EPManager::get_level()
{

return i_lvl;
}