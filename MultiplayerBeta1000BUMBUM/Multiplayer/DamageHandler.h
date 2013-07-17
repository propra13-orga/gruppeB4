#pragma once
#include "Timer.h"
#include "Gamer.h"

namespace MultiplayerLowClass
{
	class DamageHandler
	{
	private:
		int healthPlayer1;
		int healthPlayer2;
		bool PlayerOneIsAttacking;
		bool PlayerTwoIsAttacking;
		MultiplayerHighClass::Timer * AttackTimerPlayer1;
		MultiplayerHighClass::Timer * AttackTimerPlayer2;
		DamageHandler():healthPlayer1(400),healthPlayer2(400),PlayerOneIsAttacking(0),PlayerTwoIsAttacking(0){AttackTimerPlayer1 = new MultiplayerHighClass::Timer();AttackTimerPlayer2 = new MultiplayerHighClass::Timer();}
		~DamageHandler(){delete AttackTimerPlayer1;delete AttackTimerPlayer2;}

	public:
		static DamageHandler & get_Instance(){static DamageHandler Instance;return Instance;}
		int get_PlayerHealth1(){return healthPlayer1;}
		void set_PlayerHealth1(int a){healthPlayer1 = a;}
		int get_PlayerHealth(){return healthPlayer2;}
		void set_PlayerHealth(int a){healthPlayer2 = a;}
		void PlayerOneAttack(MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2);
		void PlayerTwoAttack(MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2);
		void render();
		void update();

	};
}