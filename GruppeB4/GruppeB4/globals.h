#ifndef GLOBALS_H_
#define GLOBALS_H_

//Eine Datei, die alle Global bekannten Daten enth�lt

const int  PLAYER_HEIGHT = 60;
const int  PLAYER_WIDTH  = 60;

enum WEAPON_TYPE {KNIFE,PISTOL};
enum LEVEL_LOADED {LEVEL1,LEVEL2,LEVEL3};//Hier entsteht eine Enumeration die gesetzt wird um zu �berpr�fen, welches Level geladen ist
enum ITEM_TYPE {HEAL,MANA};

#endif