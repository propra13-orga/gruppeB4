#include "GameApplicationLayer.h"

void MultiplayerHighClass::GameApplicationLayer::main_Loop()
{
	while(!b_GameShutDown)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			// Poll for quit button being clicked
			if(MultiplayerHighClass::S_Eventhandler::get_Instance()->is_GameToQuit(GameMainEvent))
			{
				b_GameShutDown = true;
			}
			// Poll for screen resize event
			MultiplayerHighClass::S_Eventhandler::get_Instance()->screenResize(GameMainEvent);
		}

		this->p_GameUpdateSource->update_AllFilesUpdateFunctions(this->GameMainEvent);
		this->p_GameUpdateSource->render_AllFilesRenderFunctions();
	}
}


void MultiplayerHighClass::GameApplicationLayer::initialize_GameResources()
{
	S_ResourceManager::get_Instance()->SetScreen( 900,600 );
	S_ResourceManager::get_Instance()->SetCaption( "Multiplayer" );
	S_ResourceManager::get_Instance()->SetTextColor( 255,255,255 );
	S_ResourceManager::get_Instance()->LoadContent();
	MultiplayerHighClass::S_Eventhandler::get_Instance()->initialize();
}

void MultiplayerHighClass::GameApplicationLayer::close_GameResources()
{
}