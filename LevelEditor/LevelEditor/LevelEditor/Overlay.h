#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Editor.h"
#include "LevelEditor.h"

class S_Overlay
{
private:
	S_Overlay(){}
	~S_Overlay(){}
public:
	static S_Overlay & get_Overlay(){static S_Overlay Instance; return Instance;}
	void render(Editor*);
};

#endif