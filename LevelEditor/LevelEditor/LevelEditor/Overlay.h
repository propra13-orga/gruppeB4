#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Editor.h"
#include "LevelEditor.h"
#include "Timer.h"

class S_Overlay
{
private:
	bool b_nothingSelected;
	bool b_startSelected;
	bool b_choiceSelected;
	S_Overlay():b_nothingSelected(1),b_choiceSelected(0),b_startSelected(0){p_PopUpTimer = new Timer();}
	~S_Overlay(){delete p_PopUpTimer;}
	Timer * p_PopUpTimer;
	bool b_popUpisActive;
	POPUPTYPE POPUP;
public:
	static S_Overlay & get_Overlay(){static S_Overlay Instance; return Instance;}
	void render(Editor*);
	void handle_Events(SDL_Event even,bool & quitgame);
	void debugFunctionShow();
	void initialize_PopUp(POPUPTYPE tempPOPUP);
};

#endif