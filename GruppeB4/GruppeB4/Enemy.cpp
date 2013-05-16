
#include <iostream>
#include <string>
#include "Enemy.h"


using namespace std;




void Enemy::update(){


	this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
	cout << "Position: " << this->get_Position()->i_y << "    " << this->get_Position()->i_x << endl;
}





                                                  //Position des Gegners anzeigen


	

//void Enemy::show_enemyStats(int i_health, int i_damage){

	//cout << "Der Gegner hat" <<i_health <<" Lebenspunkte ";    //nur zur Überprüfung! Nicht in der Form integrieren!
	
															

//}



//void Enemy:: get_health(int i_health){




//}



//void Enemy::set_health(int i_health){



//}

//void Enemy:: get_enemy(bool b_enemy){



//}


//void Enemy:: set_enemy(bool b_enemy){





//}




