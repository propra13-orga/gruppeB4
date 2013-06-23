#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <SDL_image.h>
#include "globals.h"
#include <SDL_ttf.h>

using namespace std;


class S_Resourcemanager
{
private:
	//Singleton Prinzip: KOnstruktoren im privaten Bereich, sodass erzeugung des Objektes außerhalb der Klasse verboten wird
	S_Resourcemanager(){}
	S_Resourcemanager(const S_Resourcemanager&){}
	S_Resourcemanager& operator= (const S_Resourcemanager&) {return *this;}
	~S_Resourcemanager(){}
	//Bilder, die geladen werden müssen, to do: das ganze als map implementieren.
	SDL_Surface * p_screen;
	SDL_Surface * p_player;
	SDL_Surface * p_player_up;
	SDL_Surface * p_player_left;
	SDL_Surface * p_player_right;
	SDL_Surface * p_background;
	SDL_Surface * p_menue;
	SDL_Surface * p_crazy_enemy;
	SDL_Surface * p_crazy_enemy_up;
	SDL_Surface * p_crazy_enemy_left;
	SDL_Surface * p_crazy_enemy_right;
	SDL_Surface * p_princess;
	SDL_Surface * p_game_over;
	SDL_Surface * p_win;
	SDL_Surface * p_MainMenue;
	SDL_Surface * p_main_menue;
	SDL_Surface * p_trans;
	SDL_Surface * p_hirn1;
	SDL_Surface * p_hirn2;
	SDL_Surface * p_hirn3;
	SDL_Surface * p_hirn4;
	SDL_Surface * p_Pfleger;
	SDL_Surface * p_tot;
	SDL_Surface * p_pille;
	SDL_Surface * p_heiltrank;
	SDL_Surface * p_elektrode;
	SDL_Surface * p_spritze;
	SDL_Surface * p_shop;
	SDL_Surface *p_npc1;
	SDL_Surface * p_manaspritze;
	SDL_Surface * p_map2;
	SDL_Surface * p_map3;
	SDL_Surface * p_mana_leer;
	SDL_Surface * p_mana_halbvoll;
	SDL_Surface * p_mana_voll;
	SDL_Surface * p_Aufforderung_e;
	SDL_Surface * p_gekauft;
	SDL_Surface * p_nichtgekauft;
	SDL_Surface * p_weak;
	SDL_Surface * p_tut;
	
public:
	TTF_Font * font;
	SDL_Surface * MoneyDisplay;
	SDL_Surface * HealDisplay;
	SDL_Surface * ManaDisplay;
	SDL_Color TextColor;
	SDL_Rect PlayerDownClips[6];
	SDL_Rect PlayerUpClips[6];
	SDL_Rect PlayerRightClips[6];
	SDL_Rect PlayerLeftClips[6];
	SDL_Rect EndbossClips[7];
	static S_Resourcemanager * get_Resourcemanager();
	
	void initialize();
	//Rückgabe der Bilder , die in einer map gespeichert werden
	SDL_Surface * get_Surface(string key);
};

void apply_Image(int i_x,int i_y,SDL_Surface * source, SDL_Surface * destination,SDL_Rect * clip = NULL);


#endif