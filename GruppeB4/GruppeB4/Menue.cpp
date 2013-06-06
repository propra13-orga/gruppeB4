#include "Menue.h"

Menue & Menue::get_Menue()
{
	static Menue m;
	return m;
}

void Menue::handle_Input(SDL_Event &even,bool * quitgame,bool * quitmenue,Player * temp)
{
	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
		if(even.button.button == SDL_BUTTON_LEFT)
		{
			if(even.button.x >= 600)
			{
				cout << "shutdown has been pressed" << endl;
				cout << even.button.x << endl;
				*quitgame = true;
				*quitmenue = false;
			}
			else if(even.button.x < 600)
			{
				*quitmenue = false;
				cout << "start has been pressed" << endl;
				temp->set_Velocity(0,0);
			}
		}
	}
	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_ESCAPE)
		{
			*quitmenue = false;
		}
	}
	cout << even.button.x << endl;


}