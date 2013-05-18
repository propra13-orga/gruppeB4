#include "Menue.h"

Menue & Menue::get_Menue()
{
	static Menue m;
	return m;
}

void Menue::handle_imput(SDL_Event &even,bool * quitgame,bool * quitmenue,Player * temp)
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
				temp->set_Position(250,600);
				temp->set_Velocity(0,0);
			}
		}
	}
	cout << even.button.x << endl;


}

//iuhasjdbqajw fkqjhwf qjlwe cdlqkns dclwefc lwcjhde flwje f