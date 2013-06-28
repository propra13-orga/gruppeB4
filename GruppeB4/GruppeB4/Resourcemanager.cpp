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
	TextColor.b = 100;

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
	this->p_manaspritze = IMG_Load("Mana_Spritze.png");
	this->p_mana_leer = IMG_Load("mana_leer.png");
	this->p_mana_halbvoll = IMG_Load("mana_halbvoll.png");
	this->p_mana_voll = IMG_Load("mana_voll.png");
	this->p_Aufforderung_e = IMG_Load("inter_aufforderung.png");
	this->p_gekauft = IMG_Load("gekauft.png");
	this->p_nichtgekauft = IMG_Load("nichtgekauft.png");
	this->p_weak = IMG_Load("weak.png");
	this->p_tut = IMG_Load("tutorial_sequenz.png");
	this->p_ep_empty = IMG_Load("ep_empty.png");
	this->p_ep_10 = IMG_Load("ep_10.png");
	this->p_ep_20 = IMG_Load("ep_20.png");
	this->p_ep_30 = IMG_Load("ep_30.png");
	this->p_ep_40 = IMG_Load("ep_40.png");
	this->p_ep_50 = IMG_Load("ep_50.png");
	this->p_ep_60 = IMG_Load("ep_60.png");
	this->p_ep_70 = IMG_Load("ep_70.png");
	this->p_ep_80 = IMG_Load("ep_80.png");
	this->p_ep_90 = IMG_Load("ep_90.png");
	this->p_ep_100 = IMG_Load("ep_100.png");
	this->p_ep_110 = IMG_Load("ep_110.png");
	this->p_ep_120 = IMG_Load("ep_120.png");
	this->p_ep_125 = IMG_Load("ep_125.png");
	this->p_skilltree = IMG_Load("skilltree.png");
	this->p_t1_2 = IMG_Load("t1_mana_-10.png");
	this->p_t1_1 = IMG_Load("t1_1.png");
	this->p_t1_3 = IMG_Load("t1_shop_-2.png");
	this->p_t1_4 = IMG_Load("t1_mana_speed.png");
	this->p_t1_5 = IMG_Load("t1_dmgMelee.png");
	this->p_check = IMG_Load("check.png");
	
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

	 SDL_Surface * LoadedImageMap2 = IMG_Load("map2.png");
	 SDL_Surface * OptimizedImageMap2 = NULL;

	 SDL_Surface * LoadedImageMap3 = IMG_Load("map3.png");
	 SDL_Surface * OptimizedImageMap3 = NULL;

	  OptimizedImage = SDL_DisplayFormat(LoadedImage);
	  OptimizedImageMap2 = SDL_DisplayFormat(LoadedImageMap2);
	  OptimizedImageMap3 = SDL_DisplayFormat(LoadedImageMap3);

	  this->p_background = OptimizedImage;
	  this->p_map2 = OptimizedImageMap2;
	  this->p_map3 = OptimizedImageMap3;

	  //SDL_FreeSurface(OptimizedImage);

	if(p_background == NULL)
	{
		std::cout << "initzialisierung des Levels  ist fehlgeschlagen" << std::endl;
	}

	this->p_menue = IMG_Load("mainmenu_raw.png");
	this->p_crazy_enemy = IMG_Load("patient_walk.png");
	this->p_princess = IMG_Load("metamorphose.png");

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

	this->EndbossClips[0].x = 0;
	this->EndbossClips[0].y = 0;
	this->EndbossClips[0].w = 120;
	this->EndbossClips[0].h = 120;

	this->EndbossClips[1].x = 120;
	this->EndbossClips[1].y = 0;
	this->EndbossClips[1].w = 120;
	this->EndbossClips[1].h = 120;

	this->EndbossClips[2].x = 240;
	this->EndbossClips[2].y = 0;
	this->EndbossClips[2].w = 120;
	this->EndbossClips[2].h = 120;

	this->EndbossClips[3].x = 360;
	this->EndbossClips[3].y = 0;
	this->EndbossClips[3].w = 120;
	this->EndbossClips[3].h = 120;

	this->EndbossClips[4].x = 480;
	this->EndbossClips[4].y = 0;
	this->EndbossClips[4].w = 120;
	this->EndbossClips[4].h = 120;

	this->EndbossClips[5].x = 600;
	this->EndbossClips[5].y = 0;
	this->EndbossClips[5].w = 120;
	this->EndbossClips[5].h = 120;

	this->EndbossClips[6].x = 720;
	this->EndbossClips[6].y = 0;
	this->EndbossClips[6].w = 120;
	this->EndbossClips[6].h = 120;

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
	else if(key == "Level2")
	{
		return this->p_map2;
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
	else if(key == "Level3")
	{
		return p_map3;
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
	else if(key == "Mana_Spritze")
	{
		return p_manaspritze;
	}
	else if(key =="mana_voll"){
	
		return p_mana_voll;
	}

	else if(key == "mana_halbvoll"){
	
		return p_mana_halbvoll;
	
	}

	else if(key == "gekauft"){
	
		return p_gekauft;
	}
	else if(key == "mana_leer"){
	
		return p_mana_leer;
	
	}
	else if(key == "Aufforderung_e")
	{
		return p_Aufforderung_e;
	}
	else if(key == "nichtgekauft")
	{
		return p_nichtgekauft;
	}
	else if(key == "weak"){
	
		return p_weak;
	}

	else if(key == "tut"){
	
		return p_tut;
	}

	else if(key == "ep_empty"){
	
		return p_ep_empty;
	}
	else if(key == "ep_10"){
	
		return p_ep_10;
	}
	else if(key == "ep_20"){
	
		return p_ep_20;
	}
	else if(key == "ep_30"){
	
		return p_ep_30;
	}
	else if(key == "ep_40"){
	
		return p_ep_40;
	}
	else if(key == "ep_50"){
	
		return p_ep_50;
	}
	else if(key == "ep_60"){
	
		return p_ep_60;
	}
	else if(key == "ep_70"){
	
		return p_ep_70;
	}
	else if(key == "ep_80"){
	
		return p_ep_80;
	}
	else if(key == "ep_90"){
	
		return p_ep_90;
	}
	else if(key == "ep_100"){
	
		return p_ep_100;
	}
	else if(key == "ep_110"){
	
		return p_ep_110;
	}
	else if(key == "ep_120"){
	
		return p_ep_120;
	}
	else if(key == "ep_125"){
	
		return p_ep_125;
	}
	else if(key == "skilltree")
	{
		return p_skilltree;
	}
	else if(key == "t1_1")
	{
		return p_t1_1;
	}
	else if(key == "t1_2")
	{
		return p_t1_2;
	}
	else if(key == "t1_3")
	{
		return p_t1_3;
	}
	else if(key == "t1_4")
	{
		return p_t1_4;
	}
	else if(key == "t1_5")
	{
		return p_t1_5;
	}
	else if(key == "check")
	{
		return p_check;
	}
	else
	{
		std::cout << "Zugriff nicht möglich" << std::endl;
		return NULL;
	}
}