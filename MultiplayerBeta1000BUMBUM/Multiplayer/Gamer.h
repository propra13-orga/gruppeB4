#pragma once

#include "Vector2D.h"
#include "A_Animation.h"
#include "S_ResourceManager.h"

class S_CollisionManager;

namespace MultiplayerEnumerations
{
	enum WALKINGSTATS {PSY_DOWN,PSY_RIGHT,PSY_LEFT,PSY_UP};
	enum TYPE {ELECTRIC,FIRE,WATER};
}

namespace MultiplayerLowClass
{
	class Player: public MultiplayerLowClass::A_Animation
	{
	public:
		bool directionDown;
		bool directionUp;
		bool directionLeft;
		bool directionRight;
	private:
		MultiplayerStructs::Vector2D * p_s_Position;
		MultiplayerStructs::Vector2D * p_s_Velocity;
		MultiplayerEnumerations::WALKINGSTATS CURRENTWALKINGSTAT;
		MultiplayerEnumerations::TYPE CURRENTTYPE;
	public:

		Player():CURRENTWALKINGSTAT(MultiplayerEnumerations::PSY_DOWN){this->p_s_Position = new MultiplayerStructs::Vector2D;p_s_Velocity = new MultiplayerStructs::Vector2D;p_s_Velocity->X = 0;p_s_Velocity->Y = 0; p_s_Position->X = 0;p_s_Position->Y = 0;}
		Player(int x, int y,MultiplayerEnumerations::TYPE tempType):CURRENTWALKINGSTAT(MultiplayerEnumerations::PSY_DOWN){this->p_s_Position = new MultiplayerStructs::Vector2D;p_s_Velocity = new MultiplayerStructs::Vector2D;p_s_Velocity->X = 0;p_s_Velocity->Y = 0;p_s_Position->X = x;p_s_Position->Y = y;CURRENTTYPE = tempType;this->p_AnimationTimer = new MultiplayerHighClass::Timer(); this->p_AnimationTimer->start();}
		MultiplayerStructs::Vector2D * get_Position(){return p_s_Position;}
		void set_Position(int x, int y){this->p_s_Position->X = x;this->p_s_Position->Y = y;}
		void set_Velocity(int x, int y){this->p_s_Velocity->X = x;this->p_s_Velocity->Y = y;}
		MultiplayerStructs::Vector2D * get_Velocity(){return p_s_Velocity;}
		void render();
		void update();
		void show_Position(){cout << "X:    " << this->get_Position()->X << "Y:      " << this->get_Position()->Y << "   " << endl;}
	};




}