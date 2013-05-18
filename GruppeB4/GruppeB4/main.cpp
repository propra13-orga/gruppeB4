#include "Resourcemanager.h"
#include "World.h"
#include "Timer.h"
#include "Menue.h"

SDL_Event even;

int counter = 0;



int main(int argc ,char ** argv)
{
	//verschiedene Bools, die alle benötigt werden um die while schleife zu verwalten
	bool quit = false;
	bool cap = true;
	bool menueistoggled = false;
	
	//Instanz des Resourcemanagers wird erzeugt
	S_Resourcemanager::get_Resourcemanager()->initialize();
	//erzeugung der Klassen 
	World * p_world = new World(250,600);
	p_world->get_LevelSegmente()->init_Segmente();
	Timer fps;
	Timer frames;
	frames.start();
	int counter = 0;
	//Einstieg der while Schleife
	while(quit == false)
	{
		//nur temporär! überprüfung der Frames per Seconds
		if(frames.Getticks() >= 1000)
	{
		frames.start();
		cout << counter << endl;
		counter = 0;

	}
		//Das folgende passiert, falls ein Event behandelt werden muss
		if(SDL_PollEvent(&even))
		{
			//Wenn der SPieler das Spiel beendet
			if(even.type == SDL_QUIT)
			{
				quit = true;
			}
			//Wenn der Spieler Escape drückt
			if(even.type == SDL_KEYDOWN)
			{
				if(even.key.keysym.sym == SDLK_ESCAPE)
				{
					menueistoggled = true;
				}
			}
			//Der SPieler wird bewegt
			p_world->handle_event(even);
		}
		//Menue einschlaten, die geschiet, falls Escape gedrückt wurde. Die whileschleife wird erst wieder beendet, wenn der Spieler
		//
		if(menueistoggled == true)
		{
			while(menueistoggled == true)
			{
				apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Menue"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
				if(SDL_PollEvent(&even))
				{
				Menue::get_Menue().handle_imput(even,&quit,&menueistoggled,p_world->get_Player());
				}
				SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			}
		}
		p_world->update();
		//SDL_FillRect(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->format,0,0xFF,0xFF));
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		p_world->render();
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		if( ( cap == true ) && ( fps.Getticks() < 1000 / 100 ) ) 
		{
			//Sleep the remaining frame time
			SDL_Delay( ( 1000 / 100) - fps.Getticks() ); 
		}
		fps.start();
		counter++;
	}

	
	return 0;

}
