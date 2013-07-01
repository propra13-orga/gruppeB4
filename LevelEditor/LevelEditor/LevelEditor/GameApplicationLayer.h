#ifndef GAMEAPPLICATIONLAYER_H_
#define GAMEAPPLICATIONLAYER_H_

#include "Resourcemanager.h"
#include "CollisibalObjectManager.h"
#include "CBlock.h"
#include "EventHandler.h"



class GameApplicationLayer
{
private:
	SDL_Event even;
	bool b_quitgame;
public:
	GameApplicationLayer():b_quitgame(false){}
	~GameApplicationLayer(){}
	void initialize_GameResources();
	void game_Loop();
	void close_Game(){}


};


#endif