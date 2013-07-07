#pragma once

#include "CollisibalObjectManager.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Overlay.h"

using namespace std;

class SaveAndLoad
{
public:
	SaveAndLoad(){}
	~SaveAndLoad(){}
	SaveAndLoad(const SaveAndLoad &){}
	SaveAndLoad & operator=(const SaveAndLoad &){}

	void save_LevelData();
	void load_LevelData();




};
