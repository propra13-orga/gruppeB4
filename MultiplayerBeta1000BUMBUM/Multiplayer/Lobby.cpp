#include "Lobby.h"

void MultiplayerHighClass::S_Lobby::Lobby_Loop(SDL_Event & Event)
{
	while(this->b_quitLobby != true)
	{
		this->render();
		if(SDL_PollEvent(&Event))
		{
			if(Event.type == SDL_QUIT)
			{
				this->b_isLobbyRequested = false;
				this->b_quitLobby = true;
				// Matthias
				this->b_quitGame = true;
			}
			S_Eventhandler::get_Instance()->HandleInputEvents(Event,NULL,NULL);
		}

		S_ResourceManager::get_Instance()->UpadteScreen();

	};


}


void MultiplayerHighClass::S_Lobby::render()
{
S_ResourceManager::get_Instance()->ApplyPicture(0,0,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_Lobby),S_ResourceManager::get_Instance()->GetScreen());


//Overlay___________


//Player1 immer in Lobby wenn Lobby auf
	
S_ResourceManager::get_Instance()->ApplyPicture(20,20,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_electric_player_down),S_ResourceManager::get_Instance()->GetScreen(),&S_ResourceManager::get_Instance()->PlayerClips[0]);

	if(b_player2 == true) // wenn Spieler2 verbunden ist wird er in der Lobby angezeigt
	{
		S_ResourceManager::get_Instance()->ApplyPicture(20,100,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_electric_player_down),S_ResourceManager::get_Instance()->GetScreen(),&S_ResourceManager::get_Instance()->PlayerClips[0]);
	}
	
	if(b_player1_rdy == false)	// wenn nicht bereit weiße Schrift
	{
		S_ResourceManager::get_Instance()->ApplyPicture(110,20,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_not_rdy),S_ResourceManager::get_Instance()->GetScreen());
	}
	
	if(b_player1_rdy == true)	// wenn bereit rote Schrift
	{
		S_ResourceManager::get_Instance()->ApplyPicture(110,20,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_rdy),S_ResourceManager::get_Instance()->GetScreen());
	}
	
	if(b_player2_rdy == false) // wenn nicht bereit weiße Schrift
	{
		S_ResourceManager::get_Instance()->ApplyPicture(110,100,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_not_rdy),S_ResourceManager::get_Instance()->GetScreen());
	}
	
	
	
	if(b_player2_rdy == true) // wenn bereit rote Schrift
	{
		S_ResourceManager::get_Instance()->ApplyPicture(110,100,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_rdy),S_ResourceManager::get_Instance()->GetScreen());
	}
	
	if(b_player1_rdy_overlay == true)
	{
		if(OverlayTimer->Getticks() >= 2000)
		{
			OverlayTimer->stop();
			b_player1_rdy_overlay = false;

		}
		S_ResourceManager::get_Instance()->ApplyPicture(400,400,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_player1_not_rdy),S_ResourceManager::get_Instance()->GetScreen());
	
	}
	
	if(b_player2_rdy_overlay == true)
	{
		if(OverlayTimer->Getticks() >= 2000)
		{
			OverlayTimer->stop();
			b_player2_rdy_overlay = false;

		}
		S_ResourceManager::get_Instance()->ApplyPicture(400,400,S_ResourceManager::get_Instance()->GetPicture(S_ResourceManager::e_Image::key_player2_not_rdy),S_ResourceManager::get_Instance()->GetScreen());
	
	}
	

	/*
	if(b_gamestart == true)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("gamestart"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	*/
}
