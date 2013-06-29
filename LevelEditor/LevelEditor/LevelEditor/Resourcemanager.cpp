#include "Resourcemanager.h"



S_Resourcemanager::S_Resourcemanager()
{

	//Generelle Initalisierung-----------------------------------------------------------------------



	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("LevelEditor fuer Orpheus the patient",NULL);

	//Bilderzuweisungsteil---------------------------------------------------------------------------



	this->SurfacesMap["Screen"] = SDL_SetVideoMode(900,600,32,SDL_SWSURFACE);
	this->SurfacesMap["100x100Block"] = IMG_Load("100x100Block.png");

	//Bilderprüfungsteil-----------------------------------------------------------------------------

	if(this->SurfacesMap["100x100Block"] == NULL)
	{
		cout << "Fehler beim Initialisieren des 100x100 Blocks. Vermutlich fehlt das Bild, oder es wurde Umbenannt" << endl;
	}
	else
	{
		cout << "100x100Block erfolgreich geladen" << endl;
	}

	if(this->SurfacesMap["Screen"] == NULL)
	{
		cout << "Fehler Fehler beim Initialisieren des Screens. Stellen sie sicher, dass sie die aktuelle Version der SDL verwenden" << endl;
	}
	else
	{
		cout << "Screen erfolgreich geladen" << endl;
	}


}

void S_Resourcemanager::apply_Surface(int x, int y, SDL_Surface * source,SDL_Surface * destination,SDL_Rect * clip)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source,clip,destination,&offset);

}
