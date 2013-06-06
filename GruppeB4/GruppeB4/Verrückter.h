#include "Enemy.h"
#ifndef CRAZY_ENEMY_H
#define CRAZY_ENEMY_H

#include "Timer.h"

class Crazy_enemy: public Enemy{
private:
	s_Vector * p_S_SafePosition;
	


public:
	
	Crazy_enemy():Enemy(){}
	Crazy_enemy(int x, int y):Enemy(x,y){p_S_SafePosition = new s_Vector; p_S_SafePosition->i_x = x;p_S_SafePosition->i_y = y;}
	~Crazy_enemy(){}



	void render(SDL_Rect camera);
	void update();

	//void show_enemyStats(int ,int);

	//void set_health(int i_health);

	//void get_health(int i_health);

	//void get_enemy(bool b_enemy);

	//void set_enemy(bool b_enemy);

};

#endif
