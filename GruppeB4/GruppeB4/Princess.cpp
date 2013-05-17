#include "Princess.h"











void Princess::render(){

apply_Image(this->get_Position()->i_x,this->get_Position()->i_y,S_Resourcemanager::get_Resourcemanager()->get_Surface("Prinzessin"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}