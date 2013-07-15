#ifndef MONEYMANAGER_H_
#define MONEYMANAGER_H_

#include "RendableObject.h"
#include "list"
#include "Vektor.h"
#include "Resourcemanager.h"
#include "EPManager.h"

using namespace std;

class MoneyManager
{
private:
	int money;
	list<RenableObject> uncatchedmoney;
	MoneyManager(){}
	~MoneyManager(){}
public:
	static MoneyManager & get_MoneyManager(){static MoneyManager Instance;return Instance;}
	void set_Coin(s_Vector * p_TempPosition);
	void set_Coin(int x, int y);
	void render(SDL_Rect camera);
	void update(s_Vector * p_TempPosition);
	void reinitialize(){uncatchedmoney.clear();}
	void show(){cout << money << endl;}
	int get_Money(){return money;}
	int refreshMoney(int i_bill);
};



#endif