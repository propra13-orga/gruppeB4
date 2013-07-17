#include "EventHandler.h"

void S_EventHandler::handle_events(SDL_Event even,bool & quitgame)
{
	S_Overlay::get_Overlay().handle_Events(even,quitgame);

	if(S_LevelEditor::get_LevelEditor().get_ChoiceMode() == true)
	{
		if(even.type == SDL_MOUSEBUTTONDOWN)
		{
			if(even.button.button == SDL_BUTTON_LEFT)
			{
			S_CollisibalObjectManager::get_CManager().find(even.button.x,even.button.y);
			}
		}

		if(even.type == SDL_KEYDOWN)
		{
			if(even.key.keysym.sym == SDLK_n)
			{
				if(S_CollisibalObjectManager::get_CManager().get_WorkingListsFirstMember() != NULL)
				{
					S_CollisibalObjectManager::get_CManager().get_WorkingListsFirstMember()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
				}
			}
		}
	}

	if(S_LevelEditor::get_LevelEditor().get_BlockSetMode() == true)
	{
		if(even.type == SDL_KEYDOWN)
		{
			if(even.key.keysym.sym == SDLK_SPACE)
			{
			S_CollisibalObjectManager::get_CManager().set_Object(Block100x100,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
			}
		}
	}

	if(even.type == SDL_KEYDOWN)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_s):S_LevelEditor::get_LevelEditor().swap_Selection();break;
		case(SDLK_UP):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y - 10);KeyPressTimer->start();b_Up = true; break;
		case(SDLK_DOWN):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y + 10);KeyPressTimer->start();b_Down = true;break;
		case(SDLK_RIGHT):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x + 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);KeyPressTimer->start();b_Right = true;break;
		case(SDLK_LEFT):S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x - 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);KeyPressTimer->start();b_Left = true;break;
		}
	}

	if(even.type == SDL_KEYUP)
	{
		switch(even.key.keysym.sym)
		{
		case(SDLK_UP):b_Up = false; break;
		case(SDLK_DOWN):b_Down = false;break;
		case(SDLK_RIGHT):b_Right = false;break;
		case(SDLK_LEFT):b_Left = false;break;
		}
	}
	
}

void S_EventHandler::updateEditorsEvents()
{
	if(b_Down == true)
	{
		if(KeyPressTimer->Getticks() >= 60)
		{
			S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y + 10);
			KeyPressTimer->start();
		}
	}
	else if(b_Up == true)
	{
		if(KeyPressTimer->Getticks() >= 60)
		{
			S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y - 10);
			KeyPressTimer->start();
		}
	}
	else if(b_Right == true)
	{
		if(KeyPressTimer->Getticks() >= 60)
		{
			S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x + 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
			KeyPressTimer->start();
		}
	}
	else if(b_Left == true)
	{
		if(KeyPressTimer->Getticks() >= 60)
		{
			S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x - 10,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
			KeyPressTimer->start();
		}
	}

	if(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x <= 0)
	{
		S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(0,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
	}
	 if(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x >= 900 - 100)
	{
		S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(900 - 100,S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y);
	}
	 if(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y <= 0)
	{
		S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,0);
	}
	 if(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->y >= 600 - 100)
	{
		S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(S_LevelEditor::get_LevelEditor().get_MainEditorSource()->get_Position()->x,600 - 100);
	}

}