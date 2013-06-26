#include "Skilltree.h"







int Skilltree::get_skillpoint(){



	return i_skillpoint;



}





void Skilltree::render(){


apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


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


	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	


		if(even.button.x >= 121 && even.button.x <= 200 && even.button.y >=51 && even.button.y <=116)
		{

			if(i_skillpoint >= 1)
			{
				
				if(b_t11 == false)
				{
					i_skillpoint = i_skillpoint -1;
					cout << "t1/1 true" << endl;
					cout << i_skillpoint << endl;
					b_t11 = true;
				}
				
				
			}
				
				
		}

	}

		//weiter bedingungen für jedes feld folgen

	}

		}