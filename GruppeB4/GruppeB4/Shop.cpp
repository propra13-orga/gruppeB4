#include "Shop.h"







void Shop::handle_Input(SDL_Event &even,bool * quitshop,bool *b_shopisopen,Player * temp){

	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_e)
		{
			*b_shopisopen = false;
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
		
				cout << "Heiltrank gekauft" << endl;
		}
		if(even.button.x >=278 && even.button.x <=350 && even.button.y >=82 && even.button.y <=117){
		
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(5);

			cout << "Manatrank geklickt" << endl;
		}
	}
	}

}
void Shop::render(){

	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Shop"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}


