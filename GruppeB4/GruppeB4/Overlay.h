#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Player.h"

class Overlay
{
private:
	Overlay(){};
	~Overlay(){};
public:
	void render(Player * p_TempPlayer);
	static Overlay  &get_Instance()
	{
		static Overlay Instance;
		return Instance;
	}
};







#endif