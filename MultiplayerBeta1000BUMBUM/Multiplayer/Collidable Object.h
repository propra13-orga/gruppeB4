#pragma once

#include "Vector2D.h"

namespace MultiplayerLowClass
{

class CollisibalObject
{
private:
	MultiplayerStructs::Vector2D * p_CurrentPosition;
public:
	CollisibalObject(){p_CurrentPosition = new MultiplayerStructs::Vector2D;p_CurrentPosition->X = 0;p_CurrentPosition->Y = 0;}
	CollisibalObject(int x, int y){p_CurrentPosition = new MultiplayerStructs::Vector2D;p_CurrentPosition->X = x;p_CurrentPosition->Y = y;}
	~CollisibalObject(){delete p_CurrentPosition;}
	CollisibalObject(const CollisibalObject & that){p_CurrentPosition = new MultiplayerStructs::Vector2D;p_CurrentPosition->X = that.p_CurrentPosition->X;p_CurrentPosition->Y = that.p_CurrentPosition->Y;}
	CollisibalObject & operator=(const CollisibalObject & that){p_CurrentPosition = new MultiplayerStructs::Vector2D;p_CurrentPosition->X = that.p_CurrentPosition->X;p_CurrentPosition->Y = that.p_CurrentPosition->Y;}
	void collision_detection(/*Player*/){};
	MultiplayerStructs::Vector2D * get_Position(){return  this->p_CurrentPosition;}
	void set_Position(int x, int y){p_CurrentPosition->X = x;p_CurrentPosition->Y = y;}

};

}