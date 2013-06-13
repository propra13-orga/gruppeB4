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
	MoneyManager(){this->uncatchedmoney.push_back(RenableObject(800,900,MONEY));this->uncatchedmoney.push_back(RenableObject(1760,765,MONEY));this->uncatchedmoney.push_back(RenableObject(1760,1025,MONEY));this->uncatchedmoney.push_back(RenableObject(1260,413,MONEY));this->uncatchedmoney.push_back(RenableObject(1260,542,MONEY));this->uncatchedmoney.push_back(RenableObject(1807,116,MONEY));this->uncatchedmoney.push_back(RenableObject(1172,443,MONEY));this->uncatchedmoney.push_back(RenableObject(1020,448,MONEY));this->uncatchedmoney.push_back(RenableObject(820,118,MONEY));this->uncatchedmoney.push_back(RenableObject(842,544,MONEY));}
	~MoneyManager(){}
public:
	static MoneyManager & get_MoneyManager(){static MoneyManager Instance;return Instance;}
	void set_Coin(s_Vector * p_TempPosition);
	void render(SDL_Rect camera);
	void update(s_Vector * p_TempPosition);
	void clear(){uncatchedmoney.clear();money = 0;}
	void show(){cout << money << endl;}
	int get_Money(){return money;}
};



#endif