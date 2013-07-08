#ifndef LEVELSEGMENT_H_
#define LEVELSEGMENT_H_

#include "Resourcemanager.h"
/**Hier werden die einzelnen Level eingeführt*/

class LevelSegmente
{
public:
	SDL_Rect SegmentRect11[2];
	SDL_Rect SegmentRect12[2];
	SDL_Rect SegmentRect13[5];
	SDL_Rect SegmentRect14[1];
	SDL_Rect SegmentRect21[2];
	SDL_Rect SegmentRect22[1];
	SDL_Rect SegmentRect31[2];
	SDL_Rect SegmentRect32[2];
	SDL_Rect SegmentRect33[6];
	void init_Segmente();
};

#endif