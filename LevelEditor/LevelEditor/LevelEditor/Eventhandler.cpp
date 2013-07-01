#include "EventHandler.h"

void S_EventHandler::handle_events(SDL_Event even)
{
	if (even.type == SDL_MOUSEBUTTONDOWN)
	{
		if(even.button.button == SDL_BUTTON_LEFT)
		{
			cout << "Linker Button" << endl;
			this->x = even.button.x;
			this->y = even.button.y;

			S_CollisibalObjectManager::get_CManager().set_Object(Block100x100,x,y);
			S_CollisibalObjectManager::get_CManager().show_Insertions();
		}
	}

	if(even.type == SDL_KEYDOWN)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_s):S_LevelEditor::get_LevelEditor().swap_Selection();break;
		case(SDLK_UP):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y - 10);break;
		case(SDLK_DOWN):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y + 10);break;
		case(SDLK_RIGHT):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x + 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);break;
		case(SDLK_LEFT):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x - 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);break;
		case(SDLK_SPACE):S_CollisibalObjectManager::get_CManager().set_Object(Block100x100,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);break;
		}
	}
	
	
}