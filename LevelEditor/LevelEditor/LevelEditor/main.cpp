#include "GameApplicationLayer.h"




int main(int argv,char ** argc)
{
	
	GameApplicationLayer Game;

	Game.initialize_GameResources();

	Game.game_Loop();

	




	return 0;
}