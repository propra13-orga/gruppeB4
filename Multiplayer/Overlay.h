#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Player.h"
#include "MoneyManager.h"
#include <string>
#include <sstream>

/// Hier wird der gesamte status des Spielers auf den screen gebracht
class Overlay
{
private:
	Overlay(){OverlayTimer = new Timer();};
	~Overlay(){};
	Timer * OverlayTimer;
	bool b_lvl_up;
public:
	void render(Player * p_TempPlayer);
	void check_lvl_up();
	static Overlay  &get_Instance()
	{
		static Overlay Instance;
		return Instance;
	}
};







#endif