#include "Overlay.h"


void Overlay::render(Player * p_TempPlayer)
{
	if(p_TempPlayer->get_Health() >= 300)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else if (p_TempPlayer->get_Health() >= 200 && p_TempPlayer->get_Health() < 300)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else if (p_TempPlayer->get_Health() >= 100 && p_TempPlayer->get_Health() < 200)
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		}
		else
		{
			apply_Image(850,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("hirn4"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}


}