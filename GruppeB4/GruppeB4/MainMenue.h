#ifndef MAIN_MENUE_
#define MAIN_MENUE_

#include "Resourcemanager.h"

class Main_Menue
{
private:
public:
	void Menue_Loop(SDL_Event & even, bool &game,bool &menue);
	void handle_Events(SDL_Event & even,bool &game,bool &menue);
	void initialize_Game();
	void render();
};



#endif