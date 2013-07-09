#include "Shop.h"







void Shop::handle_Input(SDL_Event &even,bool * quitshop,bool *b_shopisopen,Player * temp){


	/// Verwaltet den UserInput
	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_e)		///<Wenn 'e' gedrückt wird schließt sich der shop(siehe main.cpp, da dort die Funktion aufgerufen wird.)
		{
			*b_shopisopen = false;
			renderbuy = false;
			nomoney = false;
		}
	
	
	}


	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	


		if(even.button.x >= 278 && even.button.x <= 350 && even.button.y >=129 && even.button.y <=166)// Wenn bei diesen Coords geklickt wird wird abgefragt:
		
			/**Wenn genug Geld vorhanden + Talente im Skilltree abgefragt( da diese auf den Shop Auswirkungen haben)
			 *	Gibt mehrere Varianten für einen Kaufe im Shop, je nachdem ob oder wieviele Talente true sind.*/
			if(MoneyManager::get_MoneyManager().get_Money()>= 5 && Skilltree::get_Skilltree().t1_3() == false && Skilltree::get_Skilltree().t2_2() == false ){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
				MoneyManager::get_MoneyManager().refreshMoney(5);
				renderbuy = true;
				BuyTimer->start();
				cout << "Heiltrank gekauft" << endl;
			}
			else if(MoneyManager::get_MoneyManager().get_Money()>= 3 && Skilltree::get_Skilltree().t1_3() == true && Skilltree::get_Skilltree().t2_2() == false ){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
				MoneyManager::get_MoneyManager().refreshMoney(3);
				renderbuy = true;
				BuyTimer->start();
				cout << "Heiltrank gekauft" << endl;
		}

			else if(MoneyManager::get_MoneyManager().get_Money()>= 2 && Skilltree::get_Skilltree().t1_3() == true && Skilltree::get_Skilltree().t2_2() == true){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
				MoneyManager::get_MoneyManager().refreshMoney(2);
				renderbuy = true;
				BuyTimer->start();
				cout << "Heiltrank gekauft" << endl;
		}

			else if(MoneyManager::get_MoneyManager().get_Money()>= 2 && Skilltree::get_Skilltree().t1_3() == false && Skilltree::get_Skilltree().t2_2() == true){
			
				ItemManager::get_ItemManager().insert_item(HEAL);
				MoneyManager::get_MoneyManager().refreshMoney(2);
				renderbuy = true;
				BuyTimer->start();
				cout << "Heiltrank gekauft" << endl;
		}

		else if(MoneyManager::get_MoneyManager().get_Money() <5)
			{
				nomoney = true;
				NoMoneyTimer->start();
			}

		if(even.button.x >=278 && even.button.x <=350 && even.button.y >=82 && even.button.y <=117){
		
			if(MoneyManager::get_MoneyManager().get_Money()>= 5 && Skilltree::get_Skilltree().t1_3() == false && Skilltree::get_Skilltree().t2_1() == false)
			{
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(5);
			renderbuy = true;
			BuyTimer->start();
			cout << "Manatrank geklickt" << endl;
		
			}
			else if(MoneyManager::get_MoneyManager().get_Money()>= 3 && Skilltree::get_Skilltree().t1_3() == true && Skilltree::get_Skilltree().t2_1() == false)
			{
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(3);
			renderbuy = true;
			BuyTimer->start();
			cout << "Manatrank geklickt" << endl;
		
			}
			else if(MoneyManager::get_MoneyManager().get_Money()>= 2 && Skilltree::get_Skilltree().t1_3() == true && Skilltree::get_Skilltree().t2_2() == true)
			{
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(2);
			renderbuy = true;
			BuyTimer->start();
			cout << "Manatrank geklickt" << endl;
		
			}
			

			else if(MoneyManager::get_MoneyManager().get_Money()>= 2 && Skilltree::get_Skilltree().t2_2() == true && Skilltree::get_Skilltree().t1_3() == false)
			{
			ItemManager::get_ItemManager().insert_item(MANA);
			MoneyManager::get_MoneyManager().refreshMoney(2);
			renderbuy = true;
			BuyTimer->start();
			cout << "Manatrank geklickt" << endl;
		
			}

			else if(MoneyManager::get_MoneyManager().get_Money() <5)
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


