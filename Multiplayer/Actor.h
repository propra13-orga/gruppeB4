#ifndef ACTOR_H_
#define ACTOR_H_
// Oberklasse für Enemy und Player ,ist eine abstrakte Klasse
class Actor
{

virtual void get_Position() = 0; 
virtual void set_Position() = 0;
};#endif