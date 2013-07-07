#include "Skilltree.h"







int Skilltree::get_skillpoint(){



	return i_skillpoint;



}





void Skilltree::handleInput(SDL_Event &even, bool *b_skilltreeisopen)
{
	
	
	if(even.type == SDL_KEYDOWN)
	{
		if(even.key.keysym.sym == SDLK_n || even.key.keysym.sym == SDLK_ESCAPE)
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
				b_nopoints = true;   //da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
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
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
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
				b_nopoints = true;				//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
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
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
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


			//___________________T2_____________
		}

				if(even.button.x >= 228 && even.button.x <= 316 && even.button.y >=142 && even.button.y <= 210)
		{
			cout << "t2_1 true" << endl;
			b_t2_1_over = true;
			overlayTimer->start();
			
			
		}

				
		if(even.button.x >= 228 && even.button.x <= 316 && even.button.y >=219 && even.button.y <=335)
		{
			if(Skilltree::get_Skilltree().t1_1() == false || Skilltree::get_Skilltree().t1_2() == false)
			{
			b_not_yet_t2_1 = true;
			overlayTimer->start();
			
			}
			if(Skilltree::get_Skilltree().t1_1() == true && Skilltree::get_Skilltree().t1_2() == true)
				{
			
			if(b_t21 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t21 == false)
			{
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t21 == false){
				b_t21 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t2_1 ausgewählt" << endl;
			cout << b_t21 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);

			}	
			
			}

			else{
			
				cout << "t1_1 und/oder t1_2 fehlt!" << endl;
			}
			}
			
		if(even.button.x >= 411 && even.button.x <= 478 && even.button.y >=144 && even.button.y <=211)
		{
			cout << "t2_2 true" << endl;
			b_t2_2_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 410 && even.button.x <= 478 && even.button.y >=215 && even.button.y <=234)
		{

			if(Skilltree::get_Skilltree().t1_3() == false)
			{
			b_not_yet_t2_2 = true;
			overlayTimer->start();
			
			}
			if(Skilltree::get_Skilltree().t1_3() == true)
			{
			if(b_t22 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t22 == false)
			{
				b_nopoints = true;		//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t22 == false){
				b_t22 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t2_2 ausgewählt" << endl;
			cout << b_t22 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}
			}
			else
			{
				cout << "Es fehlt t1_3" << endl;
			}
			

			
		}


		if(even.button.x >= 572 && even.button.x <= 660 && even.button.y >=144 && even.button.y <=211)
		{
			cout << "t2_3 true" << endl;
			b_t2_3_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 572 && even.button.x <= 660 && even.button.y >=215 && even.button.y <=234)
		{
			if(Skilltree::get_Skilltree().t1_4() == false || Skilltree::get_Skilltree().t1_5() == false)
			{
				overlayTimer->start();
				b_not_yet_t2_3 = true;
			}
			if(Skilltree::get_Skilltree().t1_4() == true && Skilltree::get_Skilltree().t1_5() == true)
			{
			if(b_t23 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t23 == false)
			{
				b_nopoints = true;		//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();		
			}

			if(i_skillpoint >=1 && b_t23 == false){
				b_t23 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t2_3 ausgewählt" << endl;
			cout << b_t23 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			}

			else
			{
				cout << "t1_4 und/oder t1_5 fehlt" << endl;
			}
		}


		if(even.button.x >= 296 && even.button.x <= 428 && even.button.y >=286 && even.button.y <=352)
		{
			cout << "t3_1 true" << endl;
			b_t3_1_over = true;
			overlayTimer->start();
			
			
		}

		if(even.button.x >= 296 && even.button.x <= 428 && even.button.y >=356 && even.button.y <=375)
		{
			if(Skilltree::get_Skilltree().t2_1() == false)
			{
				overlayTimer->start();
				b_not_yet_t3_1 = true;
			}

			if(Skilltree::get_Skilltree().t2_1() == true){	
			if(b_t31 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t31 == false)
			{
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t31 == false){
				b_t31 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t3_1 ausgewählt" << endl;
			cout << b_t31 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}
			}
			else
			{
				cout << "t2_1 ist nicht ausgewählt!" << endl;
			}
			
		}

		if(even.button.x >= 457 && even.button.x <= 593 && even.button.y >=287 && even.button.y <=350)
		{
			cout << "t3_2 true" << endl;
			b_t3_2_over = true;
			overlayTimer->start();
			
			
		}

			if(even.button.x >= 457 && even.button.x <= 593 && even.button.y >=357 && even.button.y <=376)
		{
			if(Skilltree::get_Skilltree().t2_3() == false)
			{
				overlayTimer->start();
				b_not_yet_t3_2 = true;
			}

			if(Skilltree::get_Skilltree().t2_3() == true){
			if(b_t32 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t32 == false)
			{
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t32 == false){
				b_t32 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t3_1 ausgewählt" << endl;
			cout << b_t31 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}
			}
			else
			{
				cout << "t2_3 nicht ausgewählt!" << endl;
			}
			
		}

			if(even.button.x >= 410 && even.button.x <= 430 && even.button.y >=430 && even.button.y <=492)
		{
			cout << "t4_1 true" << endl;
			b_t3_2_over = true;
			overlayTimer->start();
			
			
		}

			if(even.button.x >= 410 && even.button.x <= 430 && even.button.y >=499 && even.button.y <=517)
		{
			
			if(b_t41 == true)
			{
				cout << "skilled" << endl;
				b_skilled = true;
				overlayTimer->start();
			}

			if(i_skillpoint < 1 && b_t41 == false)
			{
				b_nopoints = true;	//da nicht genug Talentpunkte, wird nun entprechendes Feedback gegeben!
				overlayTimer->start();
			}

			if(i_skillpoint >=1 && b_t41 == false){
				b_t41 = true;
			i_skillpoint = i_skillpoint -1;
			cout << "t4_1 ausgewählt" << endl;
			cout << b_t41 << endl;
				cout << i_skillpoint << endl;
				Skilltree::get_Skilltree().administrate_skills(p_Player, b_t11);
			}

			
		}





		}
	}
	
}
	



void Skilltree::render(SDL_Event &even){

	//Renderfunktion fuer den Talentbaum
apply_Image(0,0,S_Resourcemanager::get_Resourcemanager()->get_Surface("skilltree"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));


// Skill-Erklaerungen werden gerendert für 2 Sekunden via Timer(gilt für alles Nachfolgende!)

if(b_t1_1_over == true){	
		
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

	if(b_t2_1_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t2_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t2_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}
	if(b_t2_2_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t2_2_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t2_2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}

	if(b_t2_3_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t2_3_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t2_3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}

	if(b_t3_1_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t3_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t3_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}
	if(b_t3_2_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t3_2_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t3_2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
}

	if(b_t4_1_over == true){
		
		if(overlayTimer->Getticks() >= 2000){
			overlayTimer->stop();
			b_t4_1_over = false;
		}
		apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("t3_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
	
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
	if(b_not_yet_t2_1 == true)
	{
		if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_not_yet_t2_1 = false;
		}
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_yet"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}

	if(b_not_yet_t2_2 == true)
	{
		if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_not_yet_t2_2 = false;
		}
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_yet"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
	if(b_not_yet_t2_3 == true)
	{
		if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_not_yet_t2_3 = false;
		}
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_yet"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
	if(b_not_yet_t3_1 == true)
	{
		if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_not_yet_t3_1 = false;
		}
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_yet"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}

	if(b_not_yet_t3_2 == true)
	{
		if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_not_yet_t3_2 = false;
		}
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_yet"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		}
	if(b_lvl_up == true)
	{
	if(overlayTimer->Getticks() >=2000)
		{
			overlayTimer->stop();
			b_lvl_up = false;
		}
		apply_Image(200,200,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl_up"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
		
		
	}
	


	// Anzeige im Overlay des Talentbaumes zum Anzeigen der aktuell verfuegbaren Skillpunkte.

	if(Skilltree::get_Skilltree().get_skillpoint() == 0)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_0"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}

	if(Skilltree::get_Skilltree().get_skillpoint() == 1)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_1"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	if(Skilltree::get_Skilltree().get_skillpoint() == 2)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_2"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	if(Skilltree::get_Skilltree().get_skillpoint() == 3)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_3"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	if(Skilltree::get_Skilltree().get_skillpoint() == 4)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_4"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	if(Skilltree::get_Skilltree().get_skillpoint() == 5)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_5"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	if(Skilltree::get_Skilltree().get_skillpoint() >5)
	{
		apply_Image(40,430,S_Resourcemanager::get_Resourcemanager()->get_Surface("tp_gt5"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
			
	}
	
	

	Skilltree::get_Skilltree().check_skilled();
}
void Skilltree::administrate_skills(Player *p_Player,bool b_t11)
{/*

	Mittlerweile unwichtig(habe diese Funktionen anders verwendet -> in anderen Klassen, wie im Player,Shop etc. )
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
	// Es wird ueberprueft ob das besagte Talent bereits ausgewaehlt wurden, wenn dies der Fall ist wird es mit einem Symbol "gesperrt"
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

	if(b_t21 == true)
	{
		apply_Image(245,160,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(b_t22 == true)
	{
		apply_Image(410,145,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	
	if(b_t23 == true)
	{
		apply_Image(590,145,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(b_t31 == true)
	{
		apply_Image(332,306,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}
	if(b_t32 == true)
	{
		apply_Image(481,306,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(b_t41 == true)
	{
		apply_Image(481,306,S_Resourcemanager::get_Resourcemanager()->get_Surface("check"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(Skilltree::get_Skilltree().t1_1() == false || Skilltree::get_Skilltree().t1_2() == false)
	{
		apply_Image(245,160,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_skillable"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(Skilltree::get_Skilltree().t1_3() == false )
	{
		apply_Image(410,145,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_skillable"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(Skilltree::get_Skilltree().t1_4() == false || Skilltree::get_Skilltree().t1_5() == false)
	{
		apply_Image(590,145,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_skillable"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}

	if(Skilltree::get_Skilltree().t2_1() == false)
	{
		apply_Image(332,306,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_skillable"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	
	}

	if(Skilltree::get_Skilltree().t2_3() == false)
	{
		apply_Image(481,306,S_Resourcemanager::get_Resourcemanager()->get_Surface("not_skillable"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	}


	
	
}

void Skilltree::render2()
	{
	
		if(b_lvl_up == true)
		{
			if(overlayTimer->Getticks() >= 2000)
			{
				overlayTimer->stop();
				b_lvl_up = false;
			
			}		
			apply_Image(400,400,S_Resourcemanager::get_Resourcemanager()->get_Surface("lvl_up"),S_Resourcemanager::get_Resourcemanager()->get_Surface("Screen"));
	
		}
	
	
	}


