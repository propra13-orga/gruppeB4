#pragma once

#include "S_ResourceManager.h"
#include "Gamer.h"

class Lobby;

namespace MultiplayerHighClass
{
	class S_Eventhandler
	{
	public:
		enum EventHandlerMode {LOBBY,GAME};
	private:
		S_Eventhandler(){}
		~S_Eventhandler(){}
		S_Eventhandler(const S_Eventhandler &){CURRENTMODE = LOBBY;}
		S_Eventhandler & operator=(const S_Eventhandler &){}
		EventHandlerMode CURRENTMODE;


	public:

		static S_Eventhandler * get_Instance(){static S_Eventhandler Instance; return &Instance;}
		bool is_GameToQuit(SDL_Event & TempEvent);
		void screenResize(SDL_Event & Event);
		void initialize(){}
		void HandleInputEvents(SDL_Event & Event,MultiplayerLowClass::Player * tempPlayer,MultiplayerLowClass::Player * tempPlayer2);
		EventHandlerMode get_CurrentMode(){return CURRENTMODE;}
		void set_CurrentMode(EventHandlerMode TempMode){this->CURRENTMODE = TempMode;}

	};






}