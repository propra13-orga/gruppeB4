#ifndef LEVELEDITOR_H_
#define LEVELEDITOR_H_

#include "globals.h"
#include <iostream>
#include "Editor.h"
#include "Resourcemanager.h"
#include "CollisibalObjectManager.h"
#include "SaveAndLoad.h"

class S_EventHandler;

class S_Overlay;

using namespace std;


/* Die Klasse LevelEditor ist da um s�mtliche Daten im Level zu verwalten, sowie auswahlen des Spielers zu bearbeiten und zu verarbeiten
sie ist eine �bergeordnete Klasse, die alle anderen render und updateFunktionen in ihren eigenen Update und Render funktionen enthalten sollte*/
class S_LevelEditor
{
private:
	OBJECTTYPE SELECTEDOBJECT;
	S_LevelEditor():SELECTEDOBJECT(Block100x100),b_ChoiceMode(0),b_BlockSetMode(1){MainEditorSource = new Editor(0,0);}
	~S_LevelEditor(){}
	S_LevelEditor(const S_LevelEditor &){}
	Editor * MainEditorSource;//Dies ist der Bearbeiter selbst.
	bool b_ChoiceMode;
	bool b_BlockSetMode;
public:

	static S_LevelEditor & get_LevelEditor(){static S_LevelEditor Instance; return Instance;}
	void save_Level();//speichert das Level in einer Datei mit dem Namen map.Klinik
	void load_Level();//l�d das Level aus der Datei map.Klinik
	OBJECTTYPE get_SelectedObjectType(){return SELECTEDOBJECT;}
	Editor *  get_MainEditorSource(){return MainEditorSource;}
	bool get_ChoiceMode(){return b_ChoiceMode;}
	bool get_BlockSetMode(){return b_BlockSetMode;}
	void set_ChoiceMode(bool b){b_ChoiceMode = b;}
	void setBlockSetMode(bool b){b_BlockSetMode = b;}

	void swap_Selection();

	void render();// enth�lt alle weiteren render Funktionen des Editors
	void update();// enth�lt alle weiteren update Funktionen des Editors

};




#endif