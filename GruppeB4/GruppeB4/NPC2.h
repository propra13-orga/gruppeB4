
#include "Vektor.h"
#include<iostream>
#include<string>
#include "Player.h"
#include "Resourcemanager.h"
#include "Timer.h"

#ifndef NPC2_H
#define NPC2_H

class Player;

class NPC2 
{

private:

	s_Vector* p_s_baerposition;
	s_Vector* p_s_Position;
	bool b_questanfang;
	bool b_questende;
	Timer * p_QuestTimer;

public:

	static NPC2 & get_NPC2()
	{
		static NPC2 Instance;
		return Instance;
	}

	NPC2(){p_s_Position = new s_Vector;p_s_baerposition = new s_Vector;p_s_baerposition->i_x = 1850;p_s_baerposition->i_y = 1100; p_s_Position->i_x = 120; p_s_Position->i_y = 450;p_QuestTimer = new Timer();b_questanfang = false;b_questende = false;}
	~NPC2(){delete p_s_Position;delete p_QuestTimer;}

	s_Vector* get_Position()
	{
		return this->p_s_Position;
	}

	void set_Position(int i_x,int i_y)
	{
		this->p_s_Position->i_x=i_x;this->p_s_Position->i_y=i_y;
	}

	void render(SDL_Rect camera,Player * p_TempPlayer);
	bool PlayCloseToBot(Player * p_TempPlayer);
	void questanfrage(Player * p_TempPlayer,SDL_Event even);
	void questloeschen();
	void set_QuestEnde(bool b);
	void playerclosetobaer(Player *);
	bool PlayerCloseToBaer(Player *);
	bool get_questende(){return b_questende;}	
};

#endif