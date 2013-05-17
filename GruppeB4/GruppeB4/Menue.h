#ifndef MEUNE_H_
#define MENUE_H_

#include "Resourcemanager.h"
#include "World.h"

class Menue
{
private:
	Menue(){}
	~Menue(){}
	Menue(const Menue &);
public:
	static Menue & get_Menue();
	void handle_imput(SDL_Event &even,bool *,bool *,Player * temp);
};


#endif