#include "GameApplicationLayer.h"


int main(int arg, char ** argv)
{Mix_PlayChannel(-1, S_Resourcemanager::get_Resourcemanager()->get_SoundEffect("background"),0);
	MultiplayerHighClass::GameApplicationLayer * p_GameInstance = new MultiplayerHighClass::GameApplicationLayer();

	p_GameInstance->initialize_GameResources();

	p_GameInstance->main_Loop();

	p_GameInstance->close_GameResources();

	delete p_GameInstance;

	return 0;
}