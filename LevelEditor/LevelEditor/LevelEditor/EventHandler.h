#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "Timer.h"
#include "Resourcemanager.h"
#include "CollisibalObjectManager.h"
#include "LevelEditor.h"
#include "Overlay.h"


class S_EventHandler
{
private:
	S_EventHandler():x(0),y(0),b_Down(0),b_Left(0),b_Right(0),b_Up(0){KeyPressTimer = new Timer();}
	~S_EventHandler(){}
	int x;
	int y;
	bool b_Down;
	bool b_Up;
	bool b_Left;
	bool b_Right;
	Timer * KeyPressTimer;
public:
	void handle_events(SDL_Event even,bool & quitgame);
	static S_EventHandler & get_EventHandler(){static S_EventHandler Instance; return Instance;}
	void initialize(){}
	void updateEditorsEvents();
};

#endif