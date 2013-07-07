#include "GameApplicationLayer.h"




int main(int argv,char ** argc)
{
	
	GameApplicationLayer Game;

	Game.initialize_GameResources();

	Game.game_Loop();

	Game.close_Game();

	system("PAUSE");

	




	return 0;
}