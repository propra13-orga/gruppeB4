#ifndef EDITOR_H_
#define EDITOR_H_

#include "Vector.h"
/* Aus dieser Klasse können verschiedene Instanzen für den Bearbeiter des Levels erstellt werden*/

class Editor
{
private:
	Vector2D * p_CurrentPosition;
public:
	Editor(int x, int y){p_CurrentPosition = new Vector2D;p_CurrentPosition->x = x; p_CurrentPosition->y = y;}
	~Editor(){delete p_CurrentPosition;}
	Vector2D * get_Position(){return p_CurrentPosition;}
	void set_Position(int x, int y){p_CurrentPosition->x = x;p_CurrentPosition->y = y;}

};

#endif
