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
			overlayTimer->start();
			
			
		}
	

		if(even.button.x >= 180 && even.button.x <= 245 && even.button.y >=100 && even.button.y <=114)
		{
			//if(i_skillpoint >=1){
				b_t11 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_1 ausgew�hlt" << endl;
			cout << b_t11 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			//}
		}

		if(even.button.x >= 295 && even.button.x <= 360 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_2 true" << endl;
			b_t1_2_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 295 && even.button.x <= 360 && even.button.y >=100 && even.button.y <=114)
		{
			//if(i_skillpoint >=1){
				b_t12 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_2 ausgew�hlt" << endl;
			cout << b_t12 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			//}
		}


		if(even.button.x >= 411 && even.button.x <= 478 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_3 true" << endl;
			b_t1_3_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 410 && even.button.x <= 478 && even.button.y >=100 && even.button.y <=114)
		{
			//if(i_skillpoint >=1){
				b_t13 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_3 ausgew�hlt" << endl;
			cout << b_t13 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			//}
		}

			if(even.button.x >= 524 && even.button.x <= 592 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_4 true" << endl;
			b_t1_4_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 524 && even.button.x <= 592 && even.button.y >=100 && even.button.y <=114)
		{
			//if(i_skillpoint >=1){
				b_t14 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_4 ausgew�hlt" << endl;
			cout << b_t14 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			//}
		}

			if(even.button.x >= 640 && even.button.x <= 708 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_5 true" << endl;
			b_t1_5_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 640 && even.button.x <= 708 && even.button.y >=100 && even.button.y <=114)
		{
			//if(i_skillpoint >=1){
				b_t15 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_5 ausgew�hlt" << endl;
			cout << b_t15 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			//}
		}

		}
	}
	
}
	



void Skilltree::render(SDL_Event &even){


apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


if(b_t1_1_over == true){ 
		
		if(overlayTimer->Getticks() >= 2000){
			t1_1Timer->stop();
			b_t1_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
	}

	if(b_t1_2_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			t1_2Timer->stop();
			b_t1_2_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}
	if(b_t1_3_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t1_3_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}

	if(b_t1_4_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t1_4_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_4"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}
	if(b_t1_5_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t1_5_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_5"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}

	Skilltree::get_Skilltree().check_skilled();
}
void Skilltree::administrate_skills(Player *p_Player,bool b_t11)
{
	if(b_t11 == true)
	{
		p_Player->heal(100);
	}
}

void Skilltree::check_skilled()
{

	if(b_t11 == true)
	{
		apply_Image(180,26,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}

	if(b_t12 == true)
	{
		apply_Image(295,26,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}

	if(b_t13 == true)
	{
		apply_Image(412,26,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}

	if(b_t14 == true)
	{
		apply_Image(524,26,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}
	if(b_t15 == true)
	{
		apply_Image(640,26,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	}
}