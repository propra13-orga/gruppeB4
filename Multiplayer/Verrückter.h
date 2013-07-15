#include "Enemy.h"
#ifndef CRAZY_ENEMY_H
#define CRAZY_ENEMY_H

#include "Timer.h"
#include "globals.h"

class Crazy_enemy: public Enemy{
private:
	s_Vector * p_S_SafePosition;
	Timer * AnimationTimer;
	int frames;
	status WALK_STATUS;
	int health;



public:
	
	Crazy_enemy():Enemy(){}
	Crazy_enemy(int x, int y):Enemy(x,y){p_S_SafePosition = new s_Vector; p_S_SafePosition->i_x = x;p_S_SafePosition->i_y = y;AnimationTimer = new Timer(); AnimationTimer->start();frames = 0;health = 100;}
	~Crazy_enemy(){}

	int get_Health(){return health;} ///<Fragt Gesundheit ab
	void set_health(int t){health = t;} ///<Setzt die Gesundheit
	void render(SDL_Rect camera);///<Siehe Verrückter.cpp
	void update();///<Siehe Verrückter.cpp
};

#endif
