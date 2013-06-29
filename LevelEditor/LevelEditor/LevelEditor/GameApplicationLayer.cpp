#include "GameApplicationLayer.h"


void GameApplicationLayer::initialize_GameResources()
{
	S_Resourcemanager::get_Resourcemanager().initializeSurfaces();
}



void GameApplicationLayer::game_Loop()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//Beginn der eigentlichen Schleife
	while(this->b_quitgame == false)
	{

		if(SDL_PollEvent(&even))
		{
			//In diesen Block kommen alle Sachen, die das Spiel unterbrechen, also auch Menue u.ä.
			if(even.type == SDL_QUIT)
			{
				b_quitgame = true;
			}
		}
	
	SDL_FillRect(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->format,0xFF,0xFF,0xFF));

	S_Resourcemanager::get_Resourcemanager().apply_Surface(0,0,S_Resourcemanager::get_Resourcemanager().get_Surface("100x100Block"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));

	S_Resourcemanager::get_Resourcemanager().updateScreen();

	}

	
	

	SDL_Quit();
}