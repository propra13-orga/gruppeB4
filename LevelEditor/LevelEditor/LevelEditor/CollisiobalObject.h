#ifndef COLLISIBALOBJECT_H_
#define COLLISIBALOBJECT_H_

#include "Vector.h"

class CollisibalObject
{
private:
	Vector2D * p_CurrentPosition;
public:
	CollisibalObject(){p_CurrentPosition = new Vector2D;p_CurrentPosition->x = 0;p_CurrentPosition->y = 0;}
	CollisibalObject(int x, int y){p_CurrentPosition = new Vector2D;p_CurrentPosition->x = x;p_CurrentPosition->y = y;}
	~CollisibalObject(){delete p_CurrentPosition;}
	CollisibalObject(const CollisibalObject & that){p_CurrentPosition = new Vector2D;p_CurrentPosition->x = that.p_CurrentPosition->x;p_CurrentPosition->y = that.p_CurrentPosition->y;}
	CollisibalObject & operator=(const CollisibalObject & that){p_CurrentPosition = new Vector2D;p_CurrentPosition->x = that.p_CurrentPosition->x;p_CurrentPosition->y = that.p_CurrentPosition->y;}
	void collision_detection(/*Player*/){};
	Vector2D * get_Position(){return  this->p_CurrentPosition;}
	void set_Position(int x, int y){p_CurrentPosition->x = x;p_CurrentPosition->y = y;}

};


#endif