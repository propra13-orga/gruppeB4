#include "C_Block.h"


void C_Block::render()
{
	MultiplayerHighClass::S_ResourceManager::get_Instance()->ApplyPicture(this->get_Position()->X,this->get_Position()->Y,MultiplayerHighClass::S_ResourceManager::get_Instance()->GetPicture(MultiplayerHighClass::S_ResourceManager::key_CBlock),MultiplayerHighClass::S_ResourceManager::get_Instance()->GetScreen());
}