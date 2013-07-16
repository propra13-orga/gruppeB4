#ifndef MAIN_MENUE_
#define MAIN_MENUE_

#include "Resourcemanager.h"
#include "Timer.h"

/* Diese Klasse verwaltet die Multiplayer-Lobby und zeigt an wieviele Spieler verbunden sind. Im Moment ist dies für zwei Spieler ausgelegt.
*/

class Lobby
{
private:
	bool b_lobby;
	bool b_player2;			//Bools zur Netzwerk-Simulation
	bool b_player1_rdy;
	bool b_player2_rdy;
	bool b_player1_rdy_overlay;	// Overlay Bool für die SDL
	bool b_player2_rdy_overlay;
	bool b_gamestart;
	Timer * OverlayTimer;
public:
	Lobby(){b_player1_rdy = false;b_player2_rdy = true;b_player2 = true;b_lobby = true; OverlayTimer = new Timer;}
	~Lobby(){}
	void Lobby_Loop(SDL_Event & even, bool &game,bool &lobby);
	void handle_Events(SDL_Event & even,bool &game,bool &lobby);
	void initialize_Game();
	void render();
};



#endif