#ifndef PFLEGER_H
#define PFLEGER_H

#include "Resourcemanager.h"
#include "Vektor.h"
#include "Timer.h"
#include "Spritze.h"

//Diese Klasse erstellt einen Spritzenschießenden Gegner, die Spritze ist dabei ein eigenes Objekt und testet KOllision selbst

class Pfleger_H
{
private:
	s_Vector * p_s_Position;
	Timer * p_AnimationTimer;
	Spritze * p_Weapon;
public:
	s_Vector * get_Position(){return this->p_s_Position;}
	void set_Position(int x, int y){this->p_s_Position->i_x = x; this->p_s_Position->i_y = y;}
	Timer * get_Timer(){return p_AnimationTimer;}
	void update();
	void render();
};
#endif