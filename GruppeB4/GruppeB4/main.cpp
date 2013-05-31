#include "Resourcemanager.h"
#include "World.h"
#include "Timer.h"
#include "Menue.h"
#include "MainMenue.h"

SDL_Event even;

int counter = 0;



int main(int argc ,char ** argv)
{
	//verschiedene Bools, die alle ben�tigt werden um die while schleife zu verwalten
	bool b_quit = false;
	bool b_cap = true;
	bool b_menueistoggled = false;
	bool b_firstmenue = true;



	//Instanz des Hauptmenues
	Main_Menue StartMenue;
	StartMenue.initialize_Game();
	/*while(b_firstmenue == true)
	{
		StartMenue.Menue_Loop(even,b_firstmenue,b_quit);
	}
	*/
	//Instanz des Resourcemanagers wird erzeugt
	
	//S_Resourcemanager::get_Resourcemanager()->initialize();
	//erzeugung der Klassen 
	World * p_World = new World(320,200);
	p_World->get_LevelSegmente()->init_Segmente();
	Timer Fps;
	Timer Frames;
	Frames.start();
	int counter = 0;
	//Einstieg der while Schleife
		Timer * deltaTime = new Timer();
		deltaTime->start();
	while(b_quit == false)
	{
		//nur tempor�r! �berpr�fung der Frames per Seconds
		if(Frames.Getticks() >= 1000)
	{
		Frames.start();
		cout << counter << endl;
		counter = 0;

	}
		//Das folgende passiert, falls ein Event behandelt werden muss
		if(SDL_PollEvent(&even))
		{
			//Wenn der SPieler das Spiel beendet
			if(even.type == SDL_QUIT)
			{
				b_quit = true;
			}
			//Wenn der Spieler Escape dr�ckt
			if(even.type == SDL_KEYDOWN)
			{
				if(even.key.keysym.sym == SDLK_ESCAPE)
				{
					b_menueistoggled = true;
				}
			}
			//Der SPieler wird bewegt
			p_World->handle_Event(even);
		}
		//Menue einschlaten, die geschiet, falls Escape gedr�ckt wurde. Die whileschleife wird erst wieder beendet, wenn der Spieler
		//
		if(b_menueistoggled == true)
		{
			while(b_menueistoggled == true)
			{
				apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Menue"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
				if(SDL_PollEvent(&even))
				{
				Menue::get_Menue().handle_Input(even,&b_quit,&b_menueistoggled,p_World->get_Player());
				}
				SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			}
		}
		p_World->update();
		p_World->set_Camera();
		//SDL_FillRect(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->clip_rect,SDL_MapRGB(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen")->format,0,0xFF,0xFF));
		apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&p_World->get_Camera());
		p_World->render(&b_menueistoggled,deltaTime);
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		if( ( b_cap == true ) && ( Fps.Getticks() < 1000 / 100 ) ) 
		{
			//Sleep the remaining frame time
			SDL_Delay( ( 1000 / 100) - Fps.Getticks() ); 
		}
		Fps.start();
		counter++;
	}

	
	return 0;

}
