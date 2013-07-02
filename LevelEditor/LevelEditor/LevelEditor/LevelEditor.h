#ifndef LEVELEDITOR_H_
#define LEVELEDITOR_H_

#include "globals.h"
#include <iostream>
#include "Editor.h"
#include "Resourcemanager.h"
#include "CollisibalObjectManager.h"

class S_Overlay;

using namespace std;


/* Die Klasse LevelEditor ist da um sämtliche Daten im Level zu verwalten, sowie auswahlen des Spielers zu bearbeiten und zu verarbeiten
sie ist eine übergeordnete Klasse, die alle anderen render und updateFunktionen in ihren eigenen Update und Render funktionen enthalten sollte*/
class S_LevelEditor
{
private:
	OBJECTTYPE SELECTEDOBJECT;
	S_LevelEditor():SELECTEDOBJECT(Block100x100){MainEditorSource = new Editor(0,0);}
	~S_LevelEditor(){}
	S_LevelEditor(const S_LevelEditor &){}
	Editor * MainEditorSource;//Dies ist der Bearbeiter selbst.
public:

	static S_LevelEditor & get_LevelEditor(){static S_LevelEditor Instance; return Instance;}
	void save_Level();//speichert das Level in einer Datei mit dem Namen map.Klinik
	void load_Level();//läd das Level aus der Datei map.Klinik
	OBJECTTYPE get_SelectedObjectType(){return SELECTEDOBJECT;}
	Editor *  get_MainEditorSource(){return MainEditorSource;}

	void swap_Selection();

	void render();// enthält alle weiteren render Funktionen des Editors
	void update();// enthält alle weiteren update Funktionen des Editors

};




#endif