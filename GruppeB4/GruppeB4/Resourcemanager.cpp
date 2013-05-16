#include "Resourcemanager.h"

S_Resourcemanager * S_Resourcemanager::get_Resourcemanager()
{
		// hier wird eine statische Instanz erzeugt, die sich auf grund ihrer statischen Eigenschaft nur einmal beim ersten funktionsaufruf erzeugt wird.
		static S_Resourcemanager Instance;
		return &Instance;
	}

void S_Resourcemanager::initialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	this->p_screen = SDL_SetVideoMode(1250,800,32,SDL_SWSURFACE);

	this->p_player = IMG_Load("player.png");

	if(p_player == NULL)
	{
		std::cout << "Initialisierung des Players ist fehlgeschlagen" << std::endl;
	}

	SDL_Surface * LoadedImage = IMG_Load("level1.bmp");
	 SDL_Surface * OptimizedImage = NULL;

	  OptimizedImage = SDL_DisplayFormat(LoadedImage);

	  this->p_background = OptimizedImage;

	if(p_background == NULL)
	{
		std::cout << "initzialisierung des Levels  ist fehlgeschlagen" << std::endl;
	}

	this->p_Menue = IMG_Load("mainmenu_raw.png");
}
void apply_Image(int i_x, int i_y,SDL_Surface * source, SDL_Surface * destination)
{
	SDL_Rect offset;
	offset.x = i_x;
	offset.y = i_y;

	SDL_BlitSurface(source,NULL,destination,&offset);

}

SDL_Surface * S_Resourcemanager::get_Surface(string key)
{
	if(key == "Player")
	{
		return p_player;
	}
	else if(key == "Screen")
	{
		return p_screen;
	}
	else if(key == "Level1")
	{
		return this->p_background;
	}
	else if(key == "Menue")
	{
		return p_Menue;
	}
	else
	{
		std::cout << "Zugriff nicht m�glich" << std::endl;
	}
}
