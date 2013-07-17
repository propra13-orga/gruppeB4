#pragma once

#include "S_ResourceManager.h"
#include "S_EventHandler.h"

namespace MultiplayerHighClass
{
	class S_Lobby
	{
	private:
		bool b_isLobbyRequested;
		bool b_quitLobby;
		S_Lobby():b_isLobbyRequested(1),b_quitLobby(0){}
		~S_Lobby(){}

	public:
		bool get_isLobbyRequested(){return b_isLobbyRequested;}
		void set_isLobbyRequested(bool b){b_isLobbyRequested = b;}
		bool get_quitLobby(){return b_quitLobby;}
		void set_quitLobby(bool b){b_quitLobby = b;}
		void Lobby_Loop(SDL_Event & Event);
		static S_Lobby * get_Instance(){static S_Lobby Instance;return &Instance;}
	};




}