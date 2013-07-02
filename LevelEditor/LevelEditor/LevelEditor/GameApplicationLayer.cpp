#include "GameApplicationLayer.h"


void GameApplicationLayer::initialize_GameResources()
{
	S_Resourcemanager::get_Resourcemanager().initializeSurfaces();
	S_EventHandler::get_EventHandler().initialize();
}



void GameApplicationLayer::game_Loop()
{
	//erstellen der Anfangsinstanzen
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
			else
			{
				S_EventHandler::get_EventHandler().handle_events(this->even);
			}
		}
	
		S_LevelEditor::get_LevelEditor().render();

	S_Resourcemanager::get_Resourcemanager().updateScreen();

	}

	
	

	SDL_Quit();
}