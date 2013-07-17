#pragma once

#include "Gamer.h"
#include "CollidableObjectManager.h"

namespace MultiplayerHighClass
{
	class S_CollisionManager
	{
	private:
		S_CollisionManager(){}
		~S_CollisionManager(){}
	public:
		bool collisionOfTwoPlayerLocal(MultiplayerLowClass::Player * tempPlayer1);
		static S_CollisionManager & get_Instance(){static S_CollisionManager Instance;return Instance;}

	};





}