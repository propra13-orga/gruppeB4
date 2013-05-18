#include "Verrückter.h"
#include "Resourcemanager.h"

using namespace std;



//void Crazy_enemy::update(){


	//this->set_Position(this->get_Position()->i_x + this->get_Velocity()->i_x, this->get_Position()->i_y + get_Velocity()->i_y);
	//cout << "Position: " << this->get_Position()->i_y << "    " << this->get_Position()->i_x << endl;
//}



void Crazy_enemy::render()
{
	apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Verrückter"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
} 



