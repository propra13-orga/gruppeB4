#ifndef GAMEAPPLICATIONLAYER_H_
#define GAMEAPPLICATIONLAYER_H_

/////////////////////////////////////////////////////////////////////////////////////////////
// In dieser Klasse wird der MainLoop des Spiels als Funktion gespeichert. Sie ist also	   //
//  die einzige Klasse, die der Main bekannt ist. Weiter Funktionen sind das Speichern des //
// events für den Eventhandler.In der Main wird ein Objekt dieser Klasse als MainGameSource//													   //
// gespeichert.																			   //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "S_Resourcemanager.h"
#include "S_EventHandler.h"
#include "Update.h"
#include "CollidableObjectManager.h"
#include "Gamer.h"

namespace MultiplayerHighClass
{

	class GameApplicationLayer
	{
	private:
		Timer * GameFpsTimer;
		MultiplayerLowClass::Player * p_Player1;
		MultiplayerLowClass::Player * p_Player2;
		SDL_Event GameMainEvent;// Das Hauptevent des SPiels, dass an den Eventhandler als Parameter übergeben wird
		bool b_GameShutDown;// Bool ist zuständig für das Herunterfahren des Spiels
		MultiplayerLowClass::Update * p_GameUpdateSource;
	public:
		GameApplicationLayer():b_GameShutDown(false){GameFpsTimer = new Timer();GameFpsTimer->start();cout << "Here" << endl;p_GameUpdateSource = new MultiplayerLowClass::Update();p_Player1 = new MultiplayerLowClass::Player(200,200,MultiplayerEnumerations::WATER);p_Player2 = new MultiplayerLowClass::Player(200,200,MultiplayerEnumerations::FIRE);}//Der Konstruktor der GameApplicationKlasse, er tut eigentlich nichts
		~GameApplicationLayer(){delete p_GameUpdateSource;delete p_Player1,delete p_Player2;}//Der Dekonstruktor der GameApplicationKlasse, er tut eigentlich nichts
		GameApplicationLayer(const GameApplicationLayer &){p_GameUpdateSource = new MultiplayerLowClass::Update();}// Der Kopierkonstruktor der Klasse GameAppliactionLayer
		GameApplicationLayer & operator=(const GameApplicationLayer &){p_GameUpdateSource = new MultiplayerLowClass::Update();}
		void main_Loop();// Diese Funktion beinhält den Übergeordneten Verlauf des Spiels, das Spiel wird darin ausgeführt
		void initialize_GameResources();// Initialisiert alle Game relevanten Datein, ließt Spielerdaten ein und läd eventuelle Spielstände
		void close_GameResources();// Sicheres Schließen der Applikation
		int load_MapFile();

	};

}


#endif


//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------