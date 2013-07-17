#include "Update.h"
#include "Lobby.h"

void MultiplayerLowClass::Update::render_AllFilesRenderFunctions(MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2)
{
	MultiplayerHighClass::S_ResourceManager::get_Instance()->ApplyPicture(0,0,MultiplayerHighClass::S_ResourceManager::get_Instance()->GetPicture(MultiplayerHighClass::S_ResourceManager::key_background),MultiplayerHighClass::S_ResourceManager::get_Instance()->GetScreen());

	S_CollisibalObjectManager::get_CManager().render();

	p_TempPlayer->render();
	p_TempPlayer2->render();

	MultiplayerHighClass::S_ResourceManager::get_Instance()->UpadteScreen();

}

void MultiplayerLowClass::Update::update_AllFilesUpdateFunctions(SDL_Event & tempEvent,MultiplayerLowClass::Player * p_TempPlayer,MultiplayerLowClass::Player * p_TempPlayer2)
{
	
	
	if(MultiplayerHighClass::S_Lobby::get_Instance()->get_isLobbyRequested() == true)
	{
			MultiplayerHighClass::S_Lobby::get_Instance()->Lobby_Loop(tempEvent);
	}
	else
	{
		p_TempPlayer->update();
		p_TempPlayer2->update();
	}

}