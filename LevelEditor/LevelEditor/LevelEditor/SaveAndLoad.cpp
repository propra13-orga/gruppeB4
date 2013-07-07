#include "SaveAndLoad.h"

void SaveAndLoad::save_LevelData()
{
	try
	{
	ofstream DATASTREAMSOURCE;

	DATASTREAMSOURCE.open("Map.level",ios::out);

	if(DATASTREAMSOURCE.is_open() != true)
	{
		throw "Map.level konnte nicht erstellt werden oder ist schreibgeschützt.";
	}

	DATASTREAMSOURCE << "<CollisibalObjects>: " << "\n";
	DATASTREAMSOURCE << "   <C_Block>: " << "\n";

	for(list<C_Block>::iterator myIter = S_CollisibalObjectManager::get_CManager().get_BlockList().begin();myIter != S_CollisibalObjectManager::get_CManager().get_BlockList().end();++myIter)
	{
		DATASTREAMSOURCE << "        " << myIter->get_Position()->x << "\n";
		DATASTREAMSOURCE << "        " << myIter->get_Position()->y << "\n";
	}

	

	DATASTREAMSOURCE.close();

	S_Overlay::get_Overlay().initialize_PopUp(SAVE);

	}
	catch(char * SaveFail)
	{
		cerr << "Error: " << SaveFail << "\n";
	}
}

void SaveAndLoad::load_LevelData()
{
	try
	{
	ifstream DATASTREAMSOURCE;
	DATASTREAMSOURCE.open("map.level",ios::in);

	if(DATASTREAMSOURCE.is_open() != true)
		{
			throw "Kann map.level nicht finden. Eventuell schreibgeschützte Datei. Überprüfen sie, ob der Name korrekt ist";
		}

	string s_temporaryX;
	string s_temporaryY;
	int temporaryX;
	int temporaryY;

	while(DATASTREAMSOURCE.eof() != true)
	{
		getline(DATASTREAMSOURCE,s_temporaryX);
		if(s_temporaryX == "   <C_Block>: ")
		{
			while(DATASTREAMSOURCE.eof() != true)
			{
				cout << "i am here" << endl;
				getline(DATASTREAMSOURCE,s_temporaryX);
				getline(DATASTREAMSOURCE,s_temporaryY);
				temporaryX = atoi(s_temporaryX.c_str());
				temporaryY = atoi(s_temporaryY.c_str());
				S_CollisibalObjectManager::get_CManager().set_Object(Block100x100,temporaryX,temporaryY);
			}
		}
	}

	S_CollisibalObjectManager::get_CManager().delete_lastMember();

	cout << "erfolgreich geladen" << endl;
	}
	catch(char * LoadingFail)
	{
		cerr << "Error" << LoadingFail << "\n";
	}
}
