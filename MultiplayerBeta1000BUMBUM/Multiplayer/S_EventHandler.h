#pragma once

#include "S_ResourceManager.h"

namespace MultiplayerHighClass
{
	class S_Eventhandler
	{
	private:
		S_Eventhandler(){}
		~S_Eventhandler(){}
		S_Eventhandler(const S_Eventhandler &){}
		S_Eventhandler & operator=(const S_Eventhandler &){}



	public:

		static S_Eventhandler * get_Instance(){static S_Eventhandler Instance; return &Instance;}
		bool is_GameToQuit(SDL_Event & TempEvent);
		void screenResize(SDL_Event & Event);
		void initialize(){}
		void HandleInputEvents(SDL_Event & Event){}

	};






}