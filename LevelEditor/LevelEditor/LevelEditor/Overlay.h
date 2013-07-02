#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Editor.h"
#include "LevelEditor.h"

class S_Overlay
{
private:
	bool b_nothingSelected;
	bool b_startSelected;
	bool b_choiceSelected;
	S_Overlay():b_nothingSelected(1),b_choiceSelected(0),b_startSelected(0){}
	~S_Overlay(){}
public:
	static S_Overlay & get_Overlay(){static S_Overlay Instance; return Instance;}
	void render(Editor*);
	void handle_Events(SDL_Event even);
	void debugFunctionShow();
};

#endif