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
			if(b_t11 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}
			
			 if(i_skillpoint < 1 && b_t11 == false)
			{
				b_nopoints = true;
				overlayTimer->start();
			}


			 if(i_skillpoint >=1 && b_t11 == false){
				b_t11 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_1 ausgewählt" << endl;
			cout << b_t11 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			
			}
			
			
		}

		if(even.button.x >= 295 && even.button.x <= 360 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_2 true" << endl;
			b_t1_2_over = true;
			overlayTimer->start();
			
			
		}

		
		if(even.button.x >= 295 && even.button.x <= 360 && even.button.y >=100 && even.button.y <=114)
		{

			if(b_t12 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}
			

			if(i_skillpoint < 1 && b_t12 == false)
			{
				b_nopoints = true;
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t12 == false){
				b_t12 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_2 ausgewählt" << endl;
			cout << b_t12 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			
		
		}


		if(even.button.x >= 411 && even.button.x <= 478 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_3 true" << endl;
			b_t1_3_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 410 && even.button.x <= 478 && even.button.y >=100 && even.button.y <=114)
		{
			
			if(b_t13 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t13 == false)
			{
				b_nopoints = true;
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t13 == false){
				b_t13 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_3 ausgewählt" << endl;
			cout << b_t13 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			
		}

			if(even.button.x >= 524 && even.button.x <= 592 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_4 true" << endl;
			b_t1_4_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 524 && even.button.x <= 592 && even.button.y >=100 && even.button.y <=114)
		{
			if(b_t14 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t14 == false)
			{
				b_nopoints = true;
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t14 == false){
				b_t14 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_4 ausgewählt" << endl;
			cout << b_t14 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			
		}

			if(even.button.x >= 640 && even.button.x <= 708 && even.button.y >=25 && even.button.y <=92)
		{
			cout << "t1_5 true" << endl;
			b_t1_5_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 640 && even.button.x <= 708 && even.button.y >=100 && even.button.y <=114)
		{
			
			if(b_t15 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t15 == false)
			{
				b_nopoints = true;
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t15 == false){
				b_t15 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t1_5 ausgewählt" << endl;
			cout << b_t15 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			
		
		}

		}
	}
	
}
	



void Skilltree::render(SDL_Event &even){


apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


if(b_t1_1_over == true){	// Skill-Erklärungen werden gerendert für 2 Sekunden via Timer
		
		if(overlayTimer->Getticks() >= 2000){             
			overlayTimer->stop();					
			b_t1_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t1_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
	}

	if(b_t1_2_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
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

	if(b_nopoints == true)
	{
		if(overlayTimer->Getticks() >= 2000)
		{
			overlayTimer->stop();
			b_nopoints = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("nopoints"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	
	}

	if(b_skilled == true)
	{
		if(overlayTimer->Getticks() >= 2000)
		{
			overlayTimer->stop();
			b_skilled = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilled"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	
	}

	Skilltree::get_Skilltree().check_skilled();
}
void Skilltree::administrate_skills(Player *p_Player,bool b_t11)
{/*
	//Hier werden die Auswirkungen der Talentverteilung verwaltet
	if(b_t11 == true)
	{
		p_Player->heal(100); // Heiltränke geben 100 HP mehr bei Benutzung oder 100 mehr Max HP
	}

	if(b_t12 == true)
	{
		//RageMode 10 Mana punkte billiger
	}
	if(b_t13 == true)
	{
		// Heil -und Mana Spritzen kosten im shop nun weniger
	}
	if(b_t14 == true)
	{
		//RageMode 10% schneller laufen	
	}
	if(b_t15 == true)
	{
		//Nahkampfwaffen verursacehn 10	Schadenspunkte mehr als normal
	}
*/}

void Skilltree::check_skilled()
{
	// Es wird überprüft ob das besagte Talent bereits ausgewählt wurden, wenn dies der Fall ist wird es mit einem Symbol "gesperrt"
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