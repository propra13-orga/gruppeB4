#ifndef GLOBALS_H_
#define GLOBALS_H_

//Eine Datei, die alle Global bekannten Daten enthält

const int  PLAYER_HEIGHT = 60;
const int  PLAYER_WIDTH  = 60;

enum RENDERTYPE {MONEY};
enum status {PSY_RIGHT,PSY_LEFT,PSY_UP,PSY_DOWN};
enum WEAPON_TYPE {NONE,MELEE};
enum LEVEL_LOADED {LEVEL1,LEVEL2,LEVEL3};//Hier entsteht eine Enumeration die gesetzt wird um zu überprüfen, welches Level geladen ist
enum ITEM_TYPE {HEAL,MANA};
enum ARMOR_TYPE{HEAVY,MID,WEAK};

#endif