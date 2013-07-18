#include "DamageHandler.h"

void MultiplayerLowClass::DamageHandler::update()
{

}

void MultiplayerLowClass::DamageHandler::render()
{

}


void MultiplayerLowClass::DamageHandler::PlayerOneAttack(MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2)
{
	// Abstand überprüfen
	if(p_TempPlayer->get_Position()->X > p_TempPlayer2->get_Position()->X -60 && p_TempPlayer->get_Position()->X < p_TempPlayer2->get_Position()->X +60
		&& p_TempPlayer->get_Position()->Y > p_TempPlayer2->get_Position()->Y -60 && p_TempPlayer->get_Position()->Y < p_TempPlayer2->get_Position()->Y +50) {
			// Richtung überprüfen
			if((p_TempPlayer->get_Position()->X < p_TempPlayer2->get_Position()->X && p_TempPlayer->get_Direction() == 4) ||
				(p_TempPlayer->get_Position()->X > p_TempPlayer2->get_Position()->X && p_TempPlayer->get_Direction() == 3) ||
				(p_TempPlayer->get_Position()->Y < p_TempPlayer2->get_Position()->Y && p_TempPlayer->get_Direction() == 1) ||
				(p_TempPlayer->get_Position()->Y > p_TempPlayer2->get_Position()->Y && p_TempPlayer->get_Direction() == 2)) {
					this->set_PlayerHealth1(this->get_PlayerHealth1() - 40);
					this->PlayerOneIsAttacking = true;
					cout << "Player 2 health: " << this->get_PlayerHealth1() << endl;
		}
	}
}

void MultiplayerLowClass::DamageHandler::PlayerTwoAttack(MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2)
{
	if(p_TempPlayer->get_Position()->X > p_TempPlayer2->get_Position()->X -60 && p_TempPlayer->get_Position()->X < p_TempPlayer2->get_Position()->X +60
		&& p_TempPlayer->get_Position()->Y > p_TempPlayer2->get_Position()->Y -60 && p_TempPlayer->get_Position()->Y < p_TempPlayer2->get_Position()->Y +60) {
			if((p_TempPlayer2->get_Position()->X < p_TempPlayer->get_Position()->X && p_TempPlayer2->get_Direction() == 4) ||
				(p_TempPlayer2->get_Position()->X > p_TempPlayer->get_Position()->X && p_TempPlayer2->get_Direction() == 3) ||
				(p_TempPlayer2->get_Position()->Y < p_TempPlayer->get_Position()->Y && p_TempPlayer2->get_Direction() == 1) ||
				(p_TempPlayer2->get_Position()->Y > p_TempPlayer->get_Position()->Y && p_TempPlayer2->get_Direction() == 2)) {
					this->set_PlayerHealth(this->get_PlayerHealth() - 20);
					this->PlayerTwoIsAttacking = true;
					cout << "Player 1 health: " << this->get_PlayerHealth() << endl;
			}
	}
}

