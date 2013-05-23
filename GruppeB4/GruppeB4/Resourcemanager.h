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
	//Singleton Prinzip: KOnstruktoren im privaten Bereich, sodass erzeugung des Objektes au�erhalb der Klasse verboten wird
	S_Resourcemanager(){}
	S_Resourcemanager(const S_Resourcemanager&){}
	S_Resourcemanager& operator= (const S_Resourcemanager&) {return *this;}
	~S_Resourcemanager(){}
	//Bilder, die geladen werden m�ssen, to do: das ganze als map implementieren.
	SDL_Surface * p_screen;
	SDL_Surface * p_player;
	SDL_Surface * p_background;
	SDL_Surface * p_Menue;
	SDL_Surface * p_crazy_Enemy;
	SDL_Surface * p_princess;
	SDL_Surface * p_game_over;
	SDL_Surface * p_win;
	SDL_Surface * p_MainMenue;
public:
	SDL_Rect PlayerDownClips[6];
	SDL_Rect PlayerUpClips[6];
	static S_Resourcemanager * get_Resourcemanager();
	
	void initialize();
	//R�ckgabe der Bilder , die in einer map gespeichert werden
	SDL_Surface * get_Surface(string key);
};

void apply_Image(int i_x,int i_y,SDL_Surface * source, SDL_Surface * destination,SDL_Rect * clip = NULL);


#endif