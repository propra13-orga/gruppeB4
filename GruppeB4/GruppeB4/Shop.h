
#ifndef SHOP_H
#define SHOP_H
#include "Resourcemanager.h"
#include "World.h"
#include "ItemManager.h"
#include "WeaponManager.h"
#include "ArmorManager.h"
#include "Moneymanager.h"



class Shop {


private:
	
	Shop(){renderbuy = false;BuyTimer = new Timer();}
	~Shop(){}
	
	int money;
	bool renderbuy;
	Timer * BuyTimer;
public:

	static Shop & get_Shop()
	{
		static Shop Instance;
		return Instance;
	}

	void render();
	void handle_Input(SDL_Event &even,bool * quitshop,bool *b_shopisopen,Player * temp);

	



};


























#endif