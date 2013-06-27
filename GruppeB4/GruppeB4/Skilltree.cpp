#include "Skilltree.h"







int Skilltree::get_skillpoint(){



	return i_skillpoint;



}





void Skilltree::render(){


apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


if(overlay_t1_1 == true)
{
	if(t1_1Timer->Getticks() >= 500)
		{
			t1_1Timer->stop();
			overlay_t1_1 = false;
			cout << "test1" << endl;
			apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));

		}

}

}



void Skilltree::handleInput(SDL_Event &even,bool *b_skilltreeisopen)
{

	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_n)
		{
			*b_skilltreeisopen = false;
			
		}
	
	
	}

}
/*	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	

				
				 if(even.button.x >= 295 && even.button.x <= 389 && even.button.y >=25 && even.button.y <=108)
				{
					
					
					overlay_t1_1 = true;
					
				}



			


	}
	}
}*/