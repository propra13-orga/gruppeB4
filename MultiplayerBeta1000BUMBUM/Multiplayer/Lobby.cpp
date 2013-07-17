#include "Lobby.h"

void MultiplayerHighClass::S_Lobby::Lobby_Loop(SDL_Event & Event)
{
	while(this->b_quitLobby != true)
	{
		S_ResourceManager::get_Instance()->ApplyPicture(0,0,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_Lobby),S_ResourceManager::get_Instance()->GetScreen());

		if(SDL_PollEvent(&Event))
		{
			if(Event.type == SDL_QUIT)
			{
				b_quitLobby = true;
				this->b_isLobbyRequested = false;
			}
			S_Eventhandler::get_Instance()->HandleInputEvents(Event,NULL,NULL);
		}

		S_ResourceManager::get_Instance()->UpadteScreen();

	}


};