#include "Shop.h"







void Shop::handle_Input(SDL_Event &even,bool * quitshop,bool *b_shopisopen,Player * temp){

	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_e)
		{
			*b_shopisopen = false;
			renderbuy = false;
		}
	
	
	}


	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	


		if(even.button.x >= 278 && even.button.x <= 350 && even.button.y >=129 && even.button.y <=166)
		
		if(MoneyManager::get_MoneyManager().get_Money()>= 5){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
				MoneyManager::get_MoneyManager().refreshMoney(5);
				renderbuy = true;
				BuyTimer->start();
				cout << "Heiltrank gekauft" << endl;
		}

		 if(MoneyManager::get_MoneyManager().get_Money() <5)
			{
				nomoney = true;
				NoMoneyTimer->start();
			}

		if(even.button.x >=278 && even.button.x <=350 && even.button.y >=82 && even.button.y <=117){
		
			if(MoneyManager::get_MoneyManager().get_Money()>= 5)
			{
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(5);
			renderbuy = true;
			BuyTimer->start();
			cout << "Manatrank geklickt" << endl;
		
			}

			if(MoneyManager::get_MoneyManager().get_Money() <5)
			{
				nomoney = true;
				NoMoneyTimer->start();
			}
		}
	}
	}

}
void Shop::render(){

	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("shop"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

	if(renderbuy == true){
	
		if(BuyTimer->Getticks() >= 500)
		{
			BuyTimer->stop();
			renderbuy = false;
		}
	
	apply_Image(450,300,S_Resourcemanager::get_Resourcemanager()->get_Surface("gekauft"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(nomoney == true)
	{
		if(NoMoneyTimer->Getticks() >= 500)
		{
			NoMoneyTimer->stop();
			nomoney = false;
		}
		apply_Image(450,300,S_Resourcemanager::get_Resourcemanager()->get_Surface("nichtgekauft"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
}


