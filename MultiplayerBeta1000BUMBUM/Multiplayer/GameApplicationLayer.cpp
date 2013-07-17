#include "GameApplicationLayer.h"

void MultiplayerHighClass::GameApplicationLayer::main_Loop()
{
	try
	{
		if(this->load_MapFile() == -1)
		{
			throw "MapFile konnt nicht gefunden werden: Vielleicht ist die Datei nicht vorhanden, vielleicht ist der Name verändert worden";
		}
	}
	catch( char * MapFileFailure)
	{
		cerr << MapFileFailure << "\n";
	}

	S_CollisibalObjectManager::get_CManager().show_Insertions();
	while(!b_GameShutDown)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			// Poll for quit button being clicked
			if(MultiplayerHighClass::S_Eventhandler::get_Instance()->is_GameToQuit(GameMainEvent))
			{
				b_GameShutDown = true;
			}

			MultiplayerHighClass::S_Eventhandler::get_Instance()->HandleInputEvents(GameMainEvent,this->p_Player1,this->p_Player2);
	
			// Poll for screen resize event
			MultiplayerHighClass::S_Eventhandler::get_Instance()->screenResize(GameMainEvent);
		}

		this->p_GameUpdateSource->update_AllFilesUpdateFunctions(this->GameMainEvent,p_Player1,p_Player2);
		this->p_GameUpdateSource->render_AllFilesRenderFunctions(this->p_Player1,p_Player2);

		if( ( GameFpsTimer->Getticks() < 1000 / 100 ) ) 
		{
			///Sleep the remaining frame time
			SDL_Delay( ( 1000 / 100) - GameFpsTimer->Getticks() ); 
		}
		GameFpsTimer->start();
	}
}


void MultiplayerHighClass::GameApplicationLayer::initialize_GameResources()
{
	S_ResourceManager::get_Instance()->SetScreen( 900,600 );
	S_ResourceManager::get_Instance()->SetCaption( "Multiplayer" );
	S_ResourceManager::get_Instance()->SetTextColor( 255,255,255 );
	S_ResourceManager::get_Instance()->LoadContent();
	MultiplayerHighClass::S_Eventhandler::get_Instance()->initialize();
}

void MultiplayerHighClass::GameApplicationLayer::close_GameResources()
{
}

int MultiplayerHighClass::GameApplicationLayer::load_MapFile()
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
				S_CollisibalObjectManager::get_CManager().set_Object(S_CollisibalObjectManager::Block100x100,temporaryX,temporaryY);
			}
		}
	}
	S_CollisibalObjectManager::get_CManager().delete_lastMember();

	cout << "erfolgreich geladen" << endl;
	return 0;
	}
	catch(char * LoadingFail)
	{
		cerr << "Error" << LoadingFail << "\n";return -1;
	}
}
