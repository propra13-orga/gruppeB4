#pragma once

#include "Vector2D.h"

namespace MultiplayerLowClass
{
	class Player
	{
	private:
		MultiplayerStructs::Vector2D<int> * p_s_Position;
	public:
		Player(){this->p_s_Position = new MultiplayerStructs::Vector2D<int>;p_s_Position->X = 0;p_s_Position->Y = 0;}
		Player(int x, int y){this->p_s_Position = new MultiplayerStructs::Vector2D<int>;p_s_Position->X = x;p_s_Position->Y = y;}
		MultiplayerStructs::Vector2D<int> * get_Position(){return p_s_Position;}
		void set_Position(int x, int y){this->p_s_Position->X = x;this->p_s_Position->Y = y;}




}