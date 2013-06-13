#ifndef MONEYMANAGER_H_
#define MONEYMANAGER_H_

#include "RendableObject.h"
#include "list"
#include "Vektor.h"
#include "Resourcemanager.h"

using namespace std;

class MoneyManager
{
private:
	int money;
	list<RenableObject> uncatchedmoney;
	MoneyManager(){this->uncatchedmoney.push_back(RenableObject(800,900,MONEY));}
	~MoneyManager(){}
public:
	static MoneyManager & get_MoneyManager(){static MoneyManager Instance;return Instance;}
	void set_Coin(s_Vector * p_TempPosition);
	void render(SDL_Rect camera);
	void update(s_Vector * p_TempPosition);
	void clear(){uncatchedmoney.clear();money = 0;}
	void show(){cout << money << endl;}
};



#endif