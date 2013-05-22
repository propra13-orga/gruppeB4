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

	SDL_Surface * LoadedImage1 = IMG_Load("player.png");

	SDL_Surface * OptimizedImage1 = NULL;

	OptimizedImage1 = SDL_DisplayFormatAlpha(LoadedImage1);

	this->p_player = OptimizedImage1;

	this->p_game_over = IMG_Load("game_over_raw.png");
	this->p_win = IMG_Load("win_proto.png");


	if(p_player == NULL)
	{
		std::cout << "Initialisierung des Players ist fehlgeschlagen" << std::endl;
	}

	SDL_Surface * LoadedImage = IMG_Load("level1.bmp");
	 SDL_Surface * OptimizedImage = NULL;

	  OptimizedImage = SDL_DisplayFormat(LoadedImage);

	  this->p_background = OptimizedImage;

	  //SDL_FreeSurface(OptimizedImage);

	if(p_background == NULL)
	{
		std::cout << "initzialisierung des Levels  ist fehlgeschlagen" << std::endl;
	}

	this->p_Menue = IMG_Load("mainmenu_raw.png");
	this->p_crazy_Enemy = IMG_Load("patient.png");
	this->p_princess = IMG_Load("Prinzessin.png");

}
void apply_Image(int i_x, int i_y,SDL_Surface * source, SDL_Surface * destination,SDL_Rect * clip)
{
	SDL_Rect offset;
	offset.x = i_x;
	offset.y = i_y;

	SDL_BlitSurface(source,clip,destination,&offset);

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
	else if(key == "Verrückter")
	{
		return this->p_crazy_Enemy;
	}
	else if(key == "Prinzessin")
	{
		return p_princess;
	}

	else if(key == "game_over_raw")
	{
		return p_game_over;
	}
	else if(key == "Win")
	{
		return this->p_win;
	}
	else
	{
		std::cout << "Zugriff nicht möglich" << std::endl;
	}
}

