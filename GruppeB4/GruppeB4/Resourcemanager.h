#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <SDL_image.h>
#include "globals.h"

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
public:
	SDL_Rect PlayerDownClips[6];
	SDL_Rect PlayerUpClips[6];
	SDL_Rect PlayerRightClips[6];
	SDL_Rect PlayerLeftClips[6];
	static S_Resourcemanager * get_Resourcemanager();
	
	void initialize();
	//Rückgabe der Bilder , die in einer map gespeichert werden
	SDL_Surface * get_Surface(string key);
};

void apply_Image(int i_x,int i_y,SDL_Surface * source, SDL_Surface * destination,SDL_Rect * clip = NULL);


#endif