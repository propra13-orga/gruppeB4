#include "Enemy.h"
#ifndef ENDBOSS_H
#define ENDBOSS_H

#include "Timer.h"
#include "globals.h"

class Endboss: public Enemy{
private:
	s_Vector * p_S_SafePosition;

	//Animation
	Timer * AnimationTimer;
	int frames;
	status WALK_STATUS;
	int health;



public:
	
	Endboss():Enemy(){}
	Endboss(int x, int y):Enemy(x,y){p_S_SafePosition = new s_Vector; p_S_SafePosition->i_x = x;p_S_SafePosition->i_y = y;AnimationTimer = new Timer(); AnimationTimer->start();frames = 0;health = 100;}
	~Endboss(){}

	int get_Health(){return health;}
	void set_health(int t){health = t;}

	void render(SDL_Rect camera);
	void update();

	//void show_enemyStats(int ,int);

	//void set_health(int i_health);

	//void get_health(int i_health);

	//void get_enemy(bool b_enemy);

	//void set_enemy(bool b_enemy);

};

#endif