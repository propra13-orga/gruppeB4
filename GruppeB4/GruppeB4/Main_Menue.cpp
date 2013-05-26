#include "MainMenue.h"

void Main_Menue::initialize_Game()
{
	S_Resourcemanager::get_Resourcemanager()->initialize();
}

void Main_Menue::handle_Events(SDL_Event & even,bool &game,bool & menue)
{
	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
		if(even.button.button == SDL_BUTTON_LEFT)
		{
			if(even.button.x >= 444 && even.button.x <= 696 && even.button.y >= 245 && even.button.y <= 325)
			{
				menue = false;
				game = false;
			}
			else if(even.button.x >= 444 && even.button.x <= 696 && even.button.y >= 339 && even.button.y <= 417)
			{
			}
			 if(even.button.x >= 444 && even.button.x <= 696 && even.button.y >= 428 && even.button.y <= 511)
			{
				menue = true;
				game = false;
				cout << "Feld wurde geklickt" << endl;
			}
			
		}
	}

}

void Main_Menue::render()
{
	apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("MainMenue"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}

void Main_Menue::Menue_Loop(SDL_Event & even, bool & game, bool & menue)
{
	if(SDL_PollEvent(&even))
	{
		this->handle_Events(even,game,menue);
	}
	this->render();
	SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
}

