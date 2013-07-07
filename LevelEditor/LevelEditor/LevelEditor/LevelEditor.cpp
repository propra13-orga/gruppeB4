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

void S_LevelEditor::load_Level()
{
	SaveAndLoad * p_GameLoad = new SaveAndLoad();
	p_GameLoad->load_LevelData();
	delete p_GameLoad;
}

void S_LevelEditor::save_Level()
{
	SaveAndLoad * p_GameSave = new SaveAndLoad();
	p_GameSave->save_LevelData();
	delete p_GameSave;
}