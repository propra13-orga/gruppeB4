#include "Enemy.h"
#ifndef CRAZY_ENEMY_H
#define CRAZY_ENEMY_H

class Crazy_enemy: public Enemy{
private:

	


public:
	
	Crazy_enemy():Enemy(){}
	Crazy_enemy(int x, int y):Enemy(x,y){}
	~Crazy_enemy(){}



	void render();
	void update();

	//void show_enemyStats(int ,int);

	//void set_health(int i_health);

	//void get_health(int i_health);

	//void get_enemy(bool b_enemy);

	//void set_enemy(bool b_enemy);

};

#endif
