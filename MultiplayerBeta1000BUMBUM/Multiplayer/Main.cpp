#include "GameApplicationLayer.h"


int main(int arg, char ** argv)
{
	MultiplayerHighClass::GameApplicationLayer * p_GameInstance = new MultiplayerHighClass::GameApplicationLayer();

	p_GameInstance->initialize_GameResources();

	p_GameInstance->main_Loop();

	p_GameInstance->close_GameResources();

	return 0;
}