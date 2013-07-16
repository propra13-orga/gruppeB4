#include "Update.h"

void MultiplayerLowClass::Update::render_AllFilesRenderFunctions()
{

}

void MultiplayerLowClass::Update::update_AllFilesUpdateFunctions(SDL_Event & tempEvent)
{
	MultiplayerHighClass::S_Eventhandler::get_Instance()->HandleInputEvents(tempEvent);
}