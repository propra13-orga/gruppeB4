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
		lvl_up = true;
		OverlayTimer->start();
		cout << "lvl jetzt rdy 4 overlay" << endl;

		i_lvl++;
		
		
	}

}


int EPManager::get_level()
{

return i_lvl;
}


void EPManager::render()
{

	if(lvl_up == true)
	{
		if(OverlayTimer->Getticks() >= 2000)
		{
			lvl_up = false;
			OverlayTimer->stop();
			
		
		}
		apply_Image(350,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl_up"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}

}


