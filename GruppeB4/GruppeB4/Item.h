#ifndef ITEM_H_
#define ITEM_H_

#include "globals.h"
#include "Vektor.h"

class Item
{
private:
	ITEM_TYPE CURRENTITEM;
	s_Vector * p_s_Position;
public:
	Item(int x, int y,ITEM_TYPE ITEMTOSET){CURRENTITEM = ITEMTOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}
	ITEM_TYPE get_Item(){return this->CURRENTITEM;}
	void set_Item(ITEM_TYPE TEMPITEM){this->CURRENTITEM = TEMPITEM;}
	s_Vector * get_Position(){return this->p_s_Position;}
	void set_Position(int x, int y){this->p_s_Position->i_x = x;this->p_s_Position->i_y = y;}
};





#endif