#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class S_Resourcemanager
{
private:
	map<string,SDL_Surface*> SurfacesMap;
	S_Resourcemanager();
	~S_Resourcemanager(){};
	 S_Resourcemanager(const  S_Resourcemanager & );
public:
	SDL_Surface * get_Surface(string key){return this->SurfacesMap[key];}
	void apply_Surface(int x, int y, SDL_Surface * source,SDL_Surface * destination,SDL_Rect * clip = NULL);
	static S_Resourcemanager & get_Resourcemanager(){static S_Resourcemanager Instance; return Instance;}
	void initializeSurfaces(){}
	void updateScreen(){SDL_Flip(this->SurfacesMap["Screen"]);}
};


#endif