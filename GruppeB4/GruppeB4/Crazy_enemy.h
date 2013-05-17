#include <iostream>
#include <string>
#include "Crazy_enemy.h"
#include "Resourcemanager.h"

using namespace std;



//void Crazy_enemy::update(){


	//this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
	//cout << "Position: " << this->get_Position()->i_y << "    " << this->get_Position()->i_x << endl;
//}



void Crazy_enemy::render()
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Crazy_enemy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
} 










//void Crazy_enemy::show_enemyStats(int i_health, int i_damage){

//	cout << "Der Gegner hat" <<i_health <<" Lebenspunkte ";    //nur zur Überprüfung! Nicht in der Form integrieren!
	
															

//}



//void Crazy_enemy:: get_health(int i_health){


	

//}



//void Crazy_enemy::set_health(int i_health){


	//i_health = 10;
//}

//void Crazy_enemy:: get_enemy(bool b_enemy){


	
//}


//void Crazy_enemy:: set_enemy(){





//}




