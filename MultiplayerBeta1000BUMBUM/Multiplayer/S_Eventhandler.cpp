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
			case(SDLK_ESCAPE):S_Lobby::get_Instance()->set_isLobbyRequested(true);this->CURRENTMODE = LOBBY;S_Lobby::get_Instance()->set_quitLobby(false);cout << "I Am Here" << endl;break;
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
			case(SDLK_w): tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_s):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_a):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			case(SDLK_d):tempPlayer2->set_Velocity(0,0);tempPlayer2->directionUp = false;tempPlayer2->directionDown = false;tempPlayer2->directionRight = false;tempPlayer2->directionLeft = false;break;
			}
		}
	}
	else if(this->CURRENTMODE == LOBBY)
	{
		if(Event.type == SDL_KEYDOWN)
		{
			switch(Event.key.keysym.sym)
			{
			case(SDLK_ESCAPE):S_Lobby::get_Instance()->set_isLobbyRequested(false);this->CURRENTMODE = GAME;S_Lobby::get_Instance()->set_quitLobby(true);break;
			}
		}
	}
}