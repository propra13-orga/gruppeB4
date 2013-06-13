#ifndef PFLEGER_H
#define PFLEGER_H

#include "Resourcemanager.h"
#include "Vektor.h"
#include "Timer.h"
#include "Spritze.h"
#include "Player.h"

//Diese Klasse erstellt einen Spritzenschießenden Gegner, die Spritze ist dabei ein eigenes Objekt und testet KOllision selbst

class Pfleger
{
private:
	s_Vector * p_s_Position;
	Timer * p_AnimationTimer;
	Spritze * p_Spritze;
	bool shootisactive;
public:
	Pfleger(int x, int y){this->p_s_Position = new s_Vector();this->p_s_Position->i_x = x; this->p_s_Position->i_y = y;this->p_AnimationTimer = new Timer(); this->p_AnimationTimer->start();this->p_Spritze = new Spritze(this->p_s_Position->i_x,this->p_s_Position->i_y);}
	~Pfleger(){delete p_s_Position;delete p_AnimationTimer;delete p_Spritze;}
	s_Vector * get_Position(){return this->p_s_Position;}
	void set_Position(int x, int y){this->p_s_Position->i_x = x; this->p_s_Position->i_y = y;}
	Timer * get_Timer(){return p_AnimationTimer;}
	void update(Player * p_TempPlayer);
	void render(SDL_Rect camera);
};
#endif