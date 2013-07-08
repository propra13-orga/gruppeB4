#ifndef SPRITZE_H_
#define SPRITZE_H_

#include "Vektor.h"
#include "Resourcemanager.h"

///Dieses Klasse wird vom Pfleger benutzt
/**Es ist kein! Objekt, dass man haben kann oder kaufen kann.
 *Die Spritze testet selber ob sie mit der Welt oder mit dem Spieler kollidiert*/
class Spritze
{
private:
	s_Vector * p_s_Position;
	s_Vector * p_s_Velocity;
	s_Vector * p_s_StartPosition;
	bool isactive;
public:
	Spritze(int x, int y){p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;p_s_Velocity = new s_Vector;p_s_Velocity->i_x = 0;p_s_Velocity->i_y = 4;p_s_StartPosition = new s_Vector;p_s_StartPosition->i_x = x;p_s_StartPosition->i_y = y; isactive = false;}
	Spritze(){p_s_Position = new s_Vector;p_s_Velocity = new s_Vector;p_s_Velocity->i_x = 0;p_s_Velocity->i_y = 4;}
	~Spritze(){}
	s_Vector * get_Position(){return this->p_s_Position;}
	s_Vector * get_Velocity(){return this->p_s_Velocity;}
	void set_Position(int x,int y){p_s_Position->i_x = x;p_s_Position->i_y = y;}
	void set_Velocity(int x,int y){p_s_Velocity->i_x = x;p_s_Velocity->i_y = y;}
	s_Vector * get_StartPosition(){return p_s_StartPosition;}

	void update();
	void render(SDL_Rect camera);

};


#endif