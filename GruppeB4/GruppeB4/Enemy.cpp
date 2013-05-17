
#include <iostream>
#include <string>
#include "Enemy.h"


using namespace std;




void Enemy::update(){

}

void Enemy::render()
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Verrückter"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
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




