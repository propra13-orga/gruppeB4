#pragma once

///////////////////////////////////////////////////////////////////////////////////
//Die Klasse Update ist ein Teil des ApplicationLayers und enth�lt alle          //
//�bergeordneten UpdateFUnktion. Sie selbst enth�lt aber immer die h�chste Update//
//Funktion.Neben ihr gibt es keine!												 //
///////////////////////////////////////////////////////////////////////////////////

#include "S_ResourceManager.h"
#include "S_EventHandler.h"
#include "CollidableObjectManager.h"
#include "Gamer.h"

namespace MultiplayerLowClass
{
	class Update
	{
	private:
	public:
		Update(){}
		~Update(){}
		Update(const Update & that){}
		Update& operator=(const Update & that){}
		void render_AllFilesRenderFunctions(Player * p_TempPlayer,Player * p_TempPlayer2);//Hierein kommen s�mtliche render Funktionen aller Klassen
		void update_AllFilesUpdateFunctions(SDL_Event & tempEvent,Player * p_TempPlayer,Player * p_TempPlayer2);//HIerein kommen alle update Funktionen s�mtlicher Klassen
	};

}

//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------