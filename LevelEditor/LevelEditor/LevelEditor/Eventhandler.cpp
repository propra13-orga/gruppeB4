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

			S_CollisibalObjectManager::get_CManager().set_Object(C_BLOCK,x,y);
			S_CollisibalObjectManager::get_CManager().show_Insertions();
		}
	}
	else
	{
		return;
	}

}