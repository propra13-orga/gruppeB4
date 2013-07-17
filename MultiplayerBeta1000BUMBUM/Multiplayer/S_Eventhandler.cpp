#include "S_EventHandler.h"
#include "Lobby.h"

bool MultiplayerHighClass::S_Eventhandler::is_GameToQuit(SDL_Event & tempEvent)
{
	if(tempEvent.type == SDL_QUIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MultiplayerHighClass::S_Eventhandler::screenResize(SDL_Event& Event) 
{
	if(Event.type == SDL_VIDEORESIZE) {
		MultiplayerHighClass::S_ResourceManager::get_Instance()->SetScreen(Event.resize.w, Event.resize.h);
	}
}

void MultiplayerHighClass::S_Eventhandler::HandleInputEvents(SDL_Event & Event,MultiplayerLowClass::Player * tempPlayer,MultiplayerLowClass::Player * tempPlayer2)
{
	//Behandle die Events des Spielers
	if(this->CURRENTMODE == GAME)
	{

		if(Event.type == SDL_KEYDOWN)
		{
			switch(Event.key.keysym.sym)
			{
			case(SDLK_UP): tempPlayer->set_Velocity(0,-2);tempPlayer->directionUp = true;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_DOWN):tempPlayer->set_Velocity(0,2);tempPlayer->directionUp = false;tempPlayer->directionDown = true;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_LEFT):tempPlayer->set_Velocity(-2,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = true;break;
			case(SDLK_RIGHT):tempPlayer->set_Velocity(2,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = true;tempPlayer->directionLeft = false;break;
			case(SDLK_RCTRL):MultiplayerLowClass::DamageHandler::get_Instance().PlayerOneAttack(tempPlayer,tempPlayer2);break;
			case(SDLK_w): tempPlayer2->set_Velocity(0,-2);tempPlayer2->directionUp = true;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_s):tempPlayer2->set_Velocity(0,2);tempPlayer2->directionUp = false;tempPlayer2->directionDown = true;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_a):tempPlayer2->set_Velocity(-2,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = true;break;
			case(SDLK_d):tempPlayer2->set_Velocity(2,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = true;tempPlayer2->directionLeft = false;break;
			}
		}

		if(Event.type == SDL_KEYUP)
		{
			switch(Event.key.keysym.sym)
			{
			case(SDLK_UP): tempPlayer->set_Velocity(0,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_DOWN):tempPlayer->set_Velocity(0,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_LEFT):tempPlayer->set_Velocity(0,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_RIGHT):tempPlayer->set_Velocity(0,0);tempPlayer->directionUp = false;tempPlayer->directionDown = false;tempPlayer->directionRight = false;tempPlayer->directionLeft = false;break;
			case(SDLK_LCTRL):MultiplayerLowClass::DamageHandler::get_Instance().PlayerTwoAttack(tempPlayer,tempPlayer2);
			case(SDLK_w): tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_s):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_a):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_d):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			}
		}
	}
	else if(this->CURRENTMODE == LOBBY)
	{
		
	
	

	

//____________________________________Lobby__________

	if(Event.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(Event.button.button == SDL_BUTTON_LEFT)
	{
	
		// Der Spieler(ich) wird bei klicken auf bereit auf ready gesetzt

		if(Event.button.x >= 110 && Event.button.x <= 230 && Event.button.y >=20 && Event.button.y <=80) 
		{
			
			MultiplayerHighClass::S_Lobby::get_Instance()->set_b_player1_rdy(true);
			
		}




	}

	
}




if(Event.type == SDL_MOUSEBUTTONDOWN)			// Abfrage für Maus-Koords um  zu sehen was geklickt wurde(welcher Button)
	{
	

	if(Event.button.button == SDL_BUTTON_LEFT)
	{
	
			if(Event.button.x >= 400 && Event.button.x <= 800 && Event.button.y >=50 && Event.button.y <=150) 
		{

		
			if(MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player1_rdy() == true && MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player2_rdy() == true)
		{
			cout << "Spiel wird gestartet" << endl;
			MultiplayerHighClass::S_Lobby::get_Instance()->set_quitLobby(true);
			this->CURRENTMODE = GAME;
			MultiplayerHighClass::S_Lobby::get_Instance()->set_isLobbyRequested(false);


			//b_gamestart = true;
		}

		else if(MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player1_rdy() == true && MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player2_rdy() == false)
		{
		cout << "Spieler2 nicht bereit!" << endl;
		
		
		MultiplayerHighClass::S_Lobby::get_Instance()->set_b_player2_rdy_overlay(true);
	//	OverlayTimer->start();
		MultiplayerHighClass::S_Lobby::get_Instance()->start_OverlayTimer();
	
		}

		else if(MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player1_rdy() == false && MultiplayerHighClass::S_Lobby::get_Instance()->get_b_player2_rdy() == true)
		{
		cout << "Du bist nicht bereit!!" << endl;
		
		
		MultiplayerHighClass::S_Lobby::get_Instance()->set_b_player1_rdy_overlay(true);
		//OverlayTimer->start();
		MultiplayerHighClass::S_Lobby::get_Instance()->start_OverlayTimer();
	
		}

	}
	}
	}
}
}


	
