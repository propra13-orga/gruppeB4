#include "Overlay.h"
#include "ArmorManager.h"


void Overlay::render(Player * p_TempPlayer)
{
	//Malen die Leben des Spielers auf den Bildschirm
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
		apply_Image(125,550,S_Resourcemanager::get_Resourcemanager()->get_Surface("Heiltrank"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		apply_Image(225,550,S_Resourcemanager::get_Resourcemanager()->get_Surface("Mana_Spritze"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		if(ArmorManager::get_ArmorManager().get_Armor())
		{
			apply_Image(800,550,S_Resourcemanager::get_Resourcemanager()->get_Surface("weak"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}

		std::stringstream money;

		money << MoneyManager::get_MoneyManager().get_Money();

		std::stringstream heal;
		std::stringstream mana;

		heal << ItemManager::get_ItemManager().get_Amount(HEAL);
		mana << ItemManager::get_ItemManager().get_Amount(MANA);
		EPManager::get_EPManager().render();


		S_Resourcemanager::get_Resourcemanager()->HealDisplay = TTF_RenderText_Solid(S_Resourcemanager::get_Resourcemanager()->font,heal.str().c_str(),S_Resourcemanager::get_Resourcemanager()->TextColor);
		S_Resourcemanager::get_Resourcemanager()->MoneyDisplay = TTF_RenderText_Solid(S_Resourcemanager::get_Resourcemanager()->font,money.str().c_str(),S_Resourcemanager::get_Resourcemanager()->TextColor);
		S_Resourcemanager::get_Resourcemanager()->ManaDisplay = TTF_RenderText_Solid(S_Resourcemanager::get_Resourcemanager()->font,mana.str().c_str(),S_Resourcemanager::get_Resourcemanager()->TextColor);
	
		apply_Image(50,0,S_Resourcemanager::get_Resourcemanager()->MoneyDisplay,S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		apply_Image(150,550,S_Resourcemanager::get_Resourcemanager()->HealDisplay,S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		apply_Image(250,550,S_Resourcemanager::get_Resourcemanager()->ManaDisplay,S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

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

		// EP_OVERLAY________________

		if(EPManager::get_EPManager().get_Ep() <10)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_empty"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	
		
		else if(EPManager::get_EPManager().get_Ep() <20)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_10"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <30)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_20"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <40)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_30"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <50)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_40"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <60)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_50"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <70)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_60"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <80)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_70"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <90)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_80"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <100)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_90"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <110)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_100"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}	

		else if(EPManager::get_EPManager().get_Ep() <120)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_110"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		}

		else if(EPManager::get_EPManager().get_Ep() <125)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_120"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}

		else if(EPManager::get_EPManager().get_Ep() >=125)
		{
		apply_Image(50,590,S_Resourcemanager::get_Resourcemanager()->get_Surface("ep_125"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		

		if(EPManager::get_EPManager().get_level() == 0)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 1)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 2)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 3)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl4"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 4)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl5"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 5)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl6"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 6)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl7"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 7)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl8"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 8)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl9"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		if(EPManager::get_EPManager().get_level() == 9)
		{
		
			apply_Image(750,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl10"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		}
		

	
		

}



void Overlay::check_lvl_up()
{

		if(Skilltree::get_Skilltree().get_skillpoint() == 2)
	{
			OverlayTimer->start();
			b_lvl_up = true;
			cout << "neues level" << endl;
	}
	else if(Skilltree::get_Skilltree().get_skillpoint() == 3)
	{
			OverlayTimer->start();
			b_lvl_up = true;
	}
	else if(Skilltree::get_Skilltree().get_skillpoint() == 4)
	{
			OverlayTimer->start();
			b_lvl_up = true;
	}
	else if(Skilltree::get_Skilltree().get_skillpoint() == 5)
	{
			OverlayTimer->start();
			b_lvl_up = true;
	}
	else if(Skilltree::get_Skilltree().get_skillpoint() >5)
	{
			OverlayTimer->start();
			b_lvl_up = true;
	}

	





}