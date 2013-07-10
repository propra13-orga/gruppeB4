#include "Resourcemanager.h"
#include "World.h"
#include "Timer.h"
#include "Menue.h"
#include "MainMenue.h"

SDL_Event even;

int counter = 0;



int main(int argc ,char ** argv)
{
	/**verschiedene Bools, die alle benoetigt werden um die while schleife zu verwalten*/
	bool b_quit = false;
	bool b_cap = true;
	bool b_menueistoggled = false;
	bool b_firstmenue = true;
	bool b_shopisopen =false;
	bool b_skilltreeisopen = false;
	


	///Instanz des Hauptmenues
	Main_Menue StartMenue;
	StartMenue.initialize_Game();
	while(b_firstmenue == true)
	{
		StartMenue.Menue_Loop(even,b_firstmenue,b_quit);
	}
	///Instanz des Resourcemanagers wird erzeugt
	
	///S_Resourcemanager::get_Resourcemanager()->initialize();
	///erzeugung der Klassen 
	World * p_World = new World(648,795);
	p_World->get_LevelSegmente()->init_Segmente();
	S_Resourcemanager::get_Resourcemanager()->play_GameBackgroundMusic();///<Hintergrundmusik wird abgespielt
	Timer Fps;
	Timer Frames;
	Frames.start();
	int counter = 0;
	///Einstieg der while Schleife
		Timer * deltaTime = new Timer();
		deltaTime->start();
	while(b_quit == false)
	{
		///nur temporaer! ueberpruefung der Frames per Seconds
		if(Frames.Getticks() >= 1000)
	{
		Frames.start();
		cout << counter << endl;
		counter = 0;

	}
		/**Das folgende passiert, falls ein Event behandelt werden muss*/
		if(SDL_PollEvent(&even))
		{
			///Wenn der SPieler das Spiel beendet
			if(even.type == SDL_QUIT)
			{
				b_quit = true;
			}




			///Skilltree_________________________________________Anfang_____________________________________________________________

			

			if(even.type == SDL_KEYDOWN)
			{
				if(even.key.keysym.sym == SDLK_n)			///<wird n gedrueckt geht der skilltree auf
				{
					
					b_skilltreeisopen = true;
					
					
				}
			}

			

			if(b_skilltreeisopen == true)
			{
			cout << "skilltree true" << endl;
			while(b_skilltreeisopen == true)
			{
				
															///schleife zum rendern und zum kaufen so lange shop auf true ist
				
				Skilltree::get_Skilltree().render(even);
				
				if(SDL_PollEvent(&even))
				{
				Skilltree::get_Skilltree().handleInput(even,&b_skilltreeisopen);
				}
				SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			}
		}
			p_World->update();
		p_World->set_Camera();
		/**apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&p_World->get_Camera());*/
		p_World->render(&b_menueistoggled,deltaTime);
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		if( ( b_cap == true ) && ( Fps.Getticks() < 1000 / 100 ) ) 
		{
			
			SDL_Delay( ( 1000 / 100) - Fps.Getticks() ); 
		}
		Fps.start();
		counter++;
	
			///Skilltree______________________________________________ENDE_________________________________________________________

		Overlay::get_Instance().check_lvl_up();
		NPC2::get_NPC2().questanfrage(p_World->get_Player(),even);
		NPC2::get_NPC2().questloeschen();
		NPC2::get_NPC2().playerclosetobaer(p_World->get_Player());
			///SHOP_______________________________________________Anfang________________________________________________________________

			


		if(even.type == SDL_KEYDOWN)
			{
				if(even.key.keysym.sym == SDLK_e)			///<wird e gedrueckt geht der shop auf(spaeter nur wenn npc in range ist)
				{
					if(NPC1::get_NPC1().PlayCloseToBot(p_World->get_Player()) == true)
					{
					b_shopisopen = true;
					}
				}
			}

		

	if(b_shopisopen == true)
		{
			cout << "Shop true" << endl;
			while(b_shopisopen == true)
			{
				
															///schleife zum rendern und zum kaufen so lange shop auf true ist
				
				Shop::get_Shop().render();
				
				if(SDL_PollEvent(&even))
				{
					Shop::get_Shop().handle_Input(even,&b_quit,&b_shopisopen,p_World->get_Player());
					
				}
				SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			}
		}






		p_World->update();
		p_World->set_Camera();
		/**apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("Level1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"),&p_World->get_Camera());*/
		p_World->render(&b_menueistoggled,deltaTime);
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		if( ( b_cap == true ) && ( Fps.Getticks() < 1000 / 100 ) ) 
		{
			
			SDL_Delay( ( 1000 / 100) - Fps.Getticks() ); 
		}
		Fps.start();
		counter++;
	
///________________________________________Shop_Ende_________________________________________________________________




		/// MENUE_______________________________________________________________________


			///Wenn der Spieler Escape drueckt
		if(even.type == SDL_KEYDOWN )
			{
				if(even.key.keysym.sym == SDLK_ESCAPE)
				{
					b_menueistoggled = true;
					
				}
			}
			///Der SPieler wird bewegt
			p_World->handle_Event(even);
		}
		/**Menue einschalten, die geschiet, falls Escape gedrueckt wurde. Die whileschleife wird erst wieder beendet, wenn der Spieler*/
		
		if(b_menueistoggled == true && b_shopisopen ==false)
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
		
		
		p_World->render(&b_menueistoggled,deltaTime);
		SDL_Flip(S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		if( ( b_cap == true ) && ( Fps.Getticks() < 1000 / 100 ) ) 
		{
			///Sleep the remaining frame time
			SDL_Delay( ( 1000 / 100) - Fps.Getticks() ); 
		}
		Fps.start();
		counter++;
	}






	
	return 0;

}
