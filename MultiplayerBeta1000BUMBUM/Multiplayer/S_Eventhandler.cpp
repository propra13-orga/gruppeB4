#include "S_EventHandler.h"

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

void MultiplayerHighClass::S_Eventhandler::HandleInputEvents(SDL_Event & Event)
{
	//Behandle die Events des Spielers

	if(Event.type == SDL_KEYDOWN)
	{
		switch(Event.key.keysym.sym)
		{
		case(SDLK_UP): break;
		case(SDLK_DOWN):break;
		case(SDLK_LEFT):break;
		case(SDLK_RIGHT):break;
		}
	}

	if(Event.type == SDL_KEYUP)
	{
		switch(Event.key.keysym.sym)
		{
		case(SDLK_UP):break;
		case(SDLK_DOWN):break;
		case(SDLK_LEFT):break;
		case(SDLK_RIGHT):break;
		}
	}



}