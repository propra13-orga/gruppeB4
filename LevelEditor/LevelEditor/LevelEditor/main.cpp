#include "Resourcemanager.h"




int main(int argv,char ** argc)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	S_Resourcemanager::get_Resourcemanager().initializeSurfaces();

	SDL_FillRect(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager().get_Surface("Screen")->format,0xFF,0xFF,0xFF));

	S_Resourcemanager::get_Resourcemanager().apply_Surface(0,0,S_Resourcemanager::get_Resourcemanager().get_Surface("100x100Block"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));

	S_Resourcemanager::get_Resourcemanager().updateScreen();

	


	SDL_Delay(4000);

	SDL_Quit();




	return 0;
}