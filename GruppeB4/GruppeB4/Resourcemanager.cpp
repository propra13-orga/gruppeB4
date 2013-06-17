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
	TTF_Init();

	TextColor.r = 255;
	TextColor.g = 255;
	TextColor.b = 255;

	this->p_screen = SDL_SetVideoMode(900,600,32,SDL_SWSURFACE);

	SDL_Surface * LoadedImage1 = IMG_Load("player_walk_down.png");

	SDL_Surface * OptimizedImage1 = NULL;

	OptimizedImage1 = SDL_DisplayFormatAlpha(LoadedImage1);

	font = TTF_OpenFont( "ZIPERHEA.ttf", 28 );

	if(font == NULL)
	{
		cout << "Laden des Fonts fehlgeschlagen" << endl;
	}

	this->p_player = OptimizedImage1;

	this->p_game_over = IMG_Load("game_over_raw.png");
	this->p_win = IMG_Load("win_proto.png");
	this->p_main_menue = IMG_Load("MainMenue.png");
	this->p_player_up = IMG_Load("Player_walk_up.png");
	this->p_player_right = IMG_Load("Player_walk_right.png");
	this->p_player_left = IMG_Load("Player_walk_left.png");
	this->p_hirn1 = IMG_Load("hirn1.png");
	this->p_hirn2 = IMG_Load("hirn2.png");
	this->p_hirn3 = IMG_Load("hirn3.png");
	this->p_hirn4 = IMG_Load("hirn4.png");
	this->p_Pfleger = IMG_Load("Pfleger.png");
	this->p_tot = IMG_Load("tot.png");
	this->p_pille = IMG_Load("pille.png");
	this->p_heiltrank = IMG_Load("Heal_Spritze.png");
	this->p_crazy_enemy_up = IMG_Load("PATIENToben.png");
	this->p_crazy_enemy_right = IMG_Load("PATIENTrechts.png");
	this->p_crazy_enemy_left = IMG_Load("PATIENTlinks.png");
	this->p_elektrode = IMG_Load("Elektrode.png");
	this->p_spritze = IMG_Load("Spritze.png");
	this->p_shop = IMG_Load("shop.png");
	this->p_npc1 = IMG_Load("npc1.png");
	if(p_spritze == NULL)
	{
		cout << "keine SPritze" << endl;
	}

	SDL_Surface * LoadedImage2 = IMG_Load("Licht_thronsaal.png");

	SDL_Surface * OptimizedImage2 = NULL;

	OptimizedImage2 = SDL_DisplayFormatAlpha(LoadedImage2);

	this->p_trans = OptimizedImage2;



	if(p_player == NULL)
	{
		std::cout << "Initialisierung des Players ist fehlgeschlagen" << std::endl;
	}

	SDL_Surface * LoadedImage = IMG_Load("map.png");
	 SDL_Surface * OptimizedImage = NULL;

	  OptimizedImage = SDL_DisplayFormat(LoadedImage);

	  this->p_background = OptimizedImage;

	  //SDL_FreeSurface(OptimizedImage);

	if(p_background == NULL)
	{
		std::cout << "initzialisierung des Levels  ist fehlgeschlagen" << std::endl;
	}

	this->p_menue = IMG_Load("mainmenu_raw.png");
	this->p_crazy_enemy = IMG_Load("patient_walk.png");
	this->p_princess = IMG_Load("Prinzessin.png");

	this->PlayerDownClips[0].x = 0;
	this->PlayerDownClips[0].y = 0;
	this->PlayerDownClips[0].w = PLAYER_WIDTH;
	this->PlayerDownClips[0].h = PLAYER_HEIGHT;

	this->PlayerDownClips[1].x = 60;
	this->PlayerDownClips[1].y = 0;
	this->PlayerDownClips[1].w = PLAYER_WIDTH;
	this->PlayerDownClips[1].h = PLAYER_HEIGHT;

	this->PlayerDownClips[2].x = 120;
	this->PlayerDownClips[2].y = 0;
	this->PlayerDownClips[2].w = PLAYER_WIDTH;
	this->PlayerDownClips[2].h = PLAYER_HEIGHT;

	this->PlayerDownClips[3].x = 180;
	this->PlayerDownClips[3].y = 0;
	this->PlayerDownClips[3].w = PLAYER_WIDTH;
	this->PlayerDownClips[3].h = PLAYER_HEIGHT;

	this->PlayerDownClips[4].x = 240;
	this->PlayerDownClips[4].y = 0;
	this->PlayerDownClips[4].w = PLAYER_WIDTH;
	this->PlayerDownClips[4].h = PLAYER_HEIGHT;

	this->PlayerDownClips[5].x = 300;
	this->PlayerDownClips[5].y = 0;
	this->PlayerDownClips[5].w = PLAYER_WIDTH;
	this->PlayerDownClips[5].h = PLAYER_HEIGHT;

	this->PlayerUpClips[0].x = 0;
	this->PlayerUpClips[0].y = 0;
	this->PlayerUpClips[0].w = PLAYER_WIDTH;
	this->PlayerUpClips[0].h = PLAYER_HEIGHT;

	this->PlayerUpClips[1].x = 60;
	this->PlayerUpClips[1].y = 0;
	this->PlayerUpClips[1].w = PLAYER_WIDTH;
	this->PlayerUpClips[1].h = PLAYER_HEIGHT;

	this->PlayerUpClips[2].x = 120;
	this->PlayerUpClips[2].y = 0;
	this->PlayerUpClips[2].w = PLAYER_WIDTH;
	this->PlayerUpClips[2].h = PLAYER_HEIGHT;

	this->PlayerUpClips[3].x = 180;
	this->PlayerUpClips[3].y = 0;
	this->PlayerUpClips[3].w = PLAYER_WIDTH;
	this->PlayerUpClips[3].h = PLAYER_HEIGHT;

	this->PlayerUpClips[4].x = 240;
	this->PlayerUpClips[4].y = 0;
	this->PlayerUpClips[4].w = PLAYER_WIDTH;
	this->PlayerUpClips[4].h = PLAYER_HEIGHT;

	this->PlayerUpClips[5].x = 300;
	this->PlayerUpClips[5].y = 0;
	this->PlayerUpClips[5].w = PLAYER_WIDTH;
	this->PlayerUpClips[5].h = PLAYER_HEIGHT;


	this->PlayerRightClips[0].x = 0;
	this->PlayerRightClips[0].y = 0;
	this->PlayerRightClips[0].w = PLAYER_WIDTH;
	this->PlayerRightClips[0].h = PLAYER_HEIGHT;

	this->PlayerRightClips[1].x = 60;
	this->PlayerRightClips[1].y = 0;
	this->PlayerRightClips[1].w = PLAYER_WIDTH;
	this->PlayerRightClips[1].h = PLAYER_HEIGHT;

	this->PlayerRightClips[2].x = 120;
	this->PlayerRightClips[2].y = 0;
	this->PlayerRightClips[2].w = PLAYER_WIDTH;
	this->PlayerRightClips[2].h = PLAYER_HEIGHT;

	this->PlayerRightClips[3].x = 180;
	this->PlayerRightClips[3].y = 0;
	this->PlayerRightClips[3].w = PLAYER_WIDTH;
	this->PlayerRightClips[3].h = PLAYER_HEIGHT;

	this->PlayerRightClips[4].x = 240;
	this->PlayerRightClips[4].y = 0;
	this->PlayerRightClips[4].w = PLAYER_WIDTH;
	this->PlayerRightClips[4].h = PLAYER_HEIGHT;

	this->PlayerRightClips[5].x = 300;
	this->PlayerRightClips[5].y = 0;
	this->PlayerRightClips[5].w = PLAYER_WIDTH;
	this->PlayerRightClips[5].h = PLAYER_HEIGHT;


	this->PlayerLeftClips[0].x = 0;
	this->PlayerLeftClips[0].y = 0;
	this->PlayerLeftClips[0].w = PLAYER_WIDTH;
	this->PlayerLeftClips[0].h = PLAYER_HEIGHT;

	this->PlayerLeftClips[1].x = 60;
	this->PlayerLeftClips[1].y = 0;
	this->PlayerLeftClips[1].w = PLAYER_WIDTH;
	this->PlayerLeftClips[1].h = PLAYER_HEIGHT;

	this->PlayerLeftClips[2].x = 120;
	this->PlayerLeftClips[2].y = 0;
	this->PlayerLeftClips[2].w = PLAYER_WIDTH;
	this->PlayerLeftClips[2].h = PLAYER_HEIGHT;

	this->PlayerLeftClips[3].x = 180;
	this->PlayerLeftClips[3].y = 0;
	this->PlayerLeftClips[3].w = PLAYER_WIDTH;
	this->PlayerLeftClips[3].h = PLAYER_HEIGHT;

	this->PlayerLeftClips[4].x = 240;
	this->PlayerLeftClips[4].y = 0;
	this->PlayerLeftClips[4].w = PLAYER_WIDTH;
	this->PlayerLeftClips[4].h = PLAYER_HEIGHT;

	this->PlayerLeftClips[5].x = 300;
	this->PlayerLeftClips[5].y = 0;
	this->PlayerLeftClips[5].w = PLAYER_WIDTH;
	this->PlayerLeftClips[5].h = PLAYER_HEIGHT;
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
		return p_menue;
	}
	else if(key == "Verrückter")
	{
		return this->p_crazy_enemy;
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
	else if(key == "MainMenue")
	{
		return p_main_menue;
	}
	else if(key == "Player_Up")
	{
		return p_player_up;
	}
	else if(key == "Player Left")
	{
		return p_player_left;
	}
	else if(key == "Player Right")
	{
		return p_player_right;
	}
	else if(key == "Transthron")
	{
		return this->p_trans;
	}
	else if(key == "hirn1")
	{
		return this->p_hirn1;
	}
	else if(key == "hirn2")
	{
		return this->p_hirn2;
	}
	else if(key == "hirn3")
	{
		return this->p_hirn3;
	}
	else if(key == "hirn4")
	{
		return this->p_hirn4;
	}
	else if(key == "Pfleger")
	{
		return this->p_Pfleger;
	}
	else if(key == "tot")
	{
		return this->p_tot;
	}
	else if(key == "Pille")
	{
		return p_pille;
	}
	else if(key == "Heiltrank")
	{
		return this->p_heiltrank;
	}
	else if(key == "Verrückter_Up")
	{
		return p_crazy_enemy_up;
	}
	else if(key == "Verrückter_Right")
	{
		return p_crazy_enemy_right;
	}
	else if(key == "Verrückter_Left")
	{
		return p_crazy_enemy_left;
	}
	else if(key == "Elektrode"){
		return p_elektrode;
	}
	else if(key == "Spritze")
	{
		return p_spritze;
	}
	else if(key == "shop")
	{
		return p_shop;	
	}
	else if(key == "npc1")
	{
		return p_npc1;
	}
	else
	{
		std::cout << "Zugriff nicht möglich" << std::endl;
	}
}