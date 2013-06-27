#include "Skilltree.h"







int Skilltree::get_skillpoint(){



	return i_skillpoint;



}





void Skilltree::handleInput(SDL_Event &even, bool *b_skilltreeisopen)
{
	
	
	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_n)
		{
			*b_skilltreeisopen = false;
			b_t1_1_over = false;
			
		}

}

	if(even.type == SDL_MOUSEBUTTONDOWN)
	{
	

	if(even.button.button == SDL_BUTTON_LEFT)
	{
	


		if(even.button.x >= 180 && even.button.x <= 245 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_1 true" << endl;
			b_t1_1_over = true;
			t1_1Timer->start();
			
			
		}
	



		


		}
	}
}
	



void Skilltree::render(SDL_Event &even){


apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


	if(b_t1_1_over == true){
		
		if(t1_1Timer->Getticks() >= 2000){
			t1_1Timer->stop();
			b_t1_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
	}

}


