#ifndef OVERLAY_H_
#define OVERLAY_H_

#include "Player.h"
#include "MoneyManager.h"
#include <string>
#include <sstream>

// Hier wird der gesamte status des Spielers auf den screen gebracht
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