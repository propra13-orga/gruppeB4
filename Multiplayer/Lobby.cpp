#include "Lobby.h"

void Lobby::initialize_Game()
{
	S_Resourcemanager::get_Resourcemanager()->initialize();			// Hier wird der Multiplayer mit der passenden Map initialisiert
}

void Lobby::handle_Events(SDL_Event & even,bool &game,bool & lobby)
{
	
	

	//Netzwerk input wird gebraucht um b_player2 auf true zusetzen(ist eher ein Platzhalter bis Architektur steht!!!!)
	
	
	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	
		// Der Spieler(ich) wird bei klicken auf bereit auf ready gesetzt

		if(even.button.x >= 110 && even.button.x <= 230 && even.button.y >=20 && even.button.y <=80) 
		{
			b_player1_rdy = true;
			
		}




	}

	
}


	if(even.type == SDL_MOUSEBUTTONDOWN)			// Abfrage für Maus-Koords um  zu sehen was geklickt wurde(welcher Button)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	
			if(even.button.x >= 400 && even.button.x <= 800 && even.button.y >=50 && even.button.y <=150) 
		{

		
		if(b_player1_rdy == true && b_player2_rdy == true)
		{
			cout << "Spiel wird gestartet" << endl;
			b_gamestart = true;
		}

		else if(b_player1_rdy == true && b_player2_rdy == false)
		{
		cout << "Spieler2 nicht bereit!" << endl;
		
		b_player2_rdy_overlay = true;
		OverlayTimer->start();
	
		}

		else if(b_player1_rdy == false && b_player2_rdy == true)
		{
		cout << "Du bist nicht bereit!!" << endl;
		
		b_player1_rdy_overlay = true;
		OverlayTimer->start();
		
		}

	}
	}
	
}

}
void Lobby::render()		//render() für die Lobby
{
	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Lobby"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


	if(b_lobby == true) // Standard, da Spieler 1 immer im Spiel ist, bzw. der Player1 den Multiplayer geöffnet hat
	{
	apply_Image(20,20,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	if(b_player2 == true) // wenn Spieler2 verbunden ist wird er in der Lobby angezeigt
	{
	apply_Image(20,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("Player"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	if(b_player1_rdy == false)	// wenn nicht bereit weiße Schrift
	{
		apply_Image(110,20,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(b_player1_rdy == true)	// wenn bereit rote Schrift
	{
		apply_Image(110,20,S_Resourcemanager::get_Resourcemanager()->get_Surface("rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	if(b_player2_rdy == false) // wenn nicht bereit weiße Schrift
	{
		apply_Image(110,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	
	
	if(b_player2_rdy == true) // wenn bereit rote Schrift
	{
		apply_Image(110,100,S_Resourcemanager::get_Resourcemanager()->get_Surface("rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	if(b_player1_rdy_overlay == true)
	{
		if(OverlayTimer->Getticks() >= 2000)
		{
			OverlayTimer->stop();
			b_player1_rdy_overlay = false;

		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("player1_not_rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	
	}

	if(b_player2_rdy_overlay == true)
	{
		if(OverlayTimer->Getticks() >= 2000)
		{
			OverlayTimer->stop();
			b_player2_rdy_overlay = false;

		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("player2_not_rdy"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	
	}
	

	
	if(b_gamestart == true)
	{
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("gamestart"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
}



void Lobby::Lobby_Loop(SDL_Event & even, bool & game, bool & menue)
{
	// Schleife via main.cpp gestartet wenn Multiplayer ausgeführt wird!
	if(SDL_PollEvent(&even))
	{
		this->handle_Events(even,game,menue);
	}
	this->render();
	SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

	
}

