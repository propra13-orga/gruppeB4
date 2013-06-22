#include <SDL.h>



int main(int argv,char ** argc)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface * screen = NULL;

	screen = SDL_SetVideoMode(600,600,32,SDL_SWSURFACE);

	SDL_Delay(1000);

	SDL_Quit();




	return 0;
}