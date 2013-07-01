#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "Resourcemanager.h"
#include "CollisibalObjectManager.h"
#include "LevelEditor.h"

class S_EventHandler
{
private:
	S_EventHandler(){}
	~S_EventHandler(){}
	int x;
	int y;

public:
	void handle_events(SDL_Event even);
	static S_EventHandler & get_EventHandler(){static S_EventHandler Instance; return Instance;}
	void initialize(){}
};

#endif