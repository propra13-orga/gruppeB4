#include "CBlock.h"

void C_Block::render()
{
	S_Resourcemanager::get_Resourcemanager().apply_Surface(this->get_Position()->x,this->get_Position()->y,S_Resourcemanager::get_Resourcemanager().get_Surface("100x100Block"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));
}