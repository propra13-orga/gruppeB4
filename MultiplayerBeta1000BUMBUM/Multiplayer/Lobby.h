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

	bool b_player2;			//Bools zur Netzwerk-Simulation
	bool b_player1_rdy;
	bool b_player2_rdy;
	bool b_player1_rdy_overlay;	// Overlay Bool für die SDL
	bool b_player2_rdy_overlay;
	Timer * OverlayTimer;

	S_Lobby():b_isLobbyRequested(1),b_quitLobby(0){b_player1_rdy = false;b_player2_rdy = true;b_player2 = true;OverlayTimer = new Timer;}
		~S_Lobby(){}
		

	public:
		bool get_isLobbyRequested(){return b_isLobbyRequested;}
		void set_isLobbyRequested(bool b){b_isLobbyRequested = b;}
		
		bool get_quitLobby(){return b_quitLobby;}
		void set_quitLobby(bool b){b_quitLobby = b;}
		void Lobby_Loop(SDL_Event & Event);
		void render();
		void start_OverlayTimer(){OverlayTimer->start();}

		//bool Funktionen für ausserhalb der Klasse(Eventmanager)
		bool get_b_player2(){return b_player2;}
		void set_b_player2(bool b){b_player2 = b;}

		bool get_b_player1_rdy(){return b_player1_rdy;}
		void set_b_player1_rdy(bool b){b_player1_rdy = b;}

		bool get_b_player2_rdy(){return b_player2_rdy;}
		void set_b_player2_rdy(bool b){b_player2_rdy = b;}

		bool get_b_player1_rdy_overlay(){return b_player1_rdy_overlay;}
		void set_b_player1_rdy_overlay(bool b){b_player1_rdy_overlay = b;}

		bool get_b_player2_rdy_overlay(){return b_player2_rdy_overlay;}
		void set_b_player2_rdy_overlay(bool b){b_player2_rdy_overlay = b;}


		
		
		static S_Lobby * get_Instance(){static S_Lobby Instance;return &Instance;}
	};




}