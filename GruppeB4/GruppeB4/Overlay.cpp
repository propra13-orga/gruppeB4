#include "Overlay.h"


void Overlay::render(Player * p_TempPlayer)
{
	//Malen der Leben des Spielers auf den Bildschirm
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

		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Pille"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		std::stringstream money;

		money << MoneyManager::get_MoneyManager().get_Money();

		S_Resourcemanager::get_Resourcemanager()->MoneyDisplay = TTF_RenderText_Solid(S_Resourcemanager::get_Resourcemanager()->font,money.str().c_str(),S_Resourcemanager::get_Resourcemanager()->TextColor);
	
		apply_Image(50,0,S_Resourcemanager::get_Resourcemanager()->MoneyDisplay,S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		if(WeaponManager::get_WeaponManager().CURRENT_WEAPON2 == MELEE)
		{
			apply_Image(850,550,S_Resourcemanager::get_Resourcemanager()->get_Surface("Elektrode"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}

		if(p_TempPlayer->get_Mana() >= 100){
		
		apply_Image(850,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("mana_voll"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
		else if(p_TempPlayer->get_Mana() >=50 && p_TempPlayer->get_Mana() <=100){
		
			apply_Image(850,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("mana_halbvoll"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		else if(p_TempPlayer->get_Mana() >=0 &&p_TempPlayer->get_Mana() <=49)
		{
		
		apply_Image(850,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("mana_leer"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
}