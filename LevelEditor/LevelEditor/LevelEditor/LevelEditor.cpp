#include "LevelEditor.h"
#include "Overlay.h"
#include "EventHandler.h"


void S_LevelEditor::swap_Selection()
{
	if(SELECTEDOBJECT == Block100x100)
	{
		cout << "swap" << endl;
	}

}

void S_LevelEditor::render()
{
	SDL_FillRect(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->format,0xFF,0xFF,0xFF));

	S_CollisibalObjectManager::get_CManager().render();
	S_Overlay::get_Overlay().render(this->MainEditorSource);
}

void S_LevelEditor::update()
{
	S_EventHandler::get_EventHandler().updateEditorsEvents();
}