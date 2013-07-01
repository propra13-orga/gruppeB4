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
		if(even.key.keysym.sym == SDLK_s)
		{
			S_LevelEditor::get_LevelEditor().swap_Selection();
		}
	}
	else
	{
		return;
	}
}