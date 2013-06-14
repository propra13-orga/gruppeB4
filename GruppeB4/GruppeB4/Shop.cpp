#include "Shop.h"







void Shop::handle_Input(SDL_Event &even){

	if(even.button.button == SDL_BUTTON_LEFT){
	
	
		if(even.button.x >=278 && even.button.x <=350 && even.button.y >=82 && even.button.y <=117){

			cout << "Manatrank geklickt" << endl;
			
			
			
			}
			
		}
		else if(even.button.x >= 278 && even.button.x <= 350 && even.button.y >=129 && even.button.y <=166){
		
		cout << "Heiltrank geklickt" << endl;

		if(MoneyManager::get_MoneyManager().get_Money()>= 15){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
			
		}
	}


}



void Shop::render(){

	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Shop"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}


