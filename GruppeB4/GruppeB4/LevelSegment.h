#ifndef LEVELSEGMENT_H_
#define LEVELSEGMENT_H_

#include "Resourcemanager.h"

class LevelSegmente
{
public:
	SDL_Rect SegmentRect11[2];
	SDL_Rect SegmentRect12[2];
	SDL_Rect SegmentRect13[5];
	SDL_Rect SegmentRect14[1];
	void init_Segmente();
};

#endif