#include "Skilltree.h"







int Skilltree::get_skillpoint()
{
	return i_skillpoint;
}





void Skilltree::set_skillpoint()
{
	
	if(EPManager::get_EPManager().get_Ep() >= 100)
	{
		EPManager::get_EPManager().clear_Ep();
		i_skillpoint++;
	}
}