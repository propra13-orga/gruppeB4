#ifndef RENDABLOBJECT_H_
#define RENDABLOBJECT_H_

#include "globals.h"
#include "Vektor.h"

class RenableObject
{
	RENDERTYPE CURRENTRENDERTYPE;
	s_Vector * p_s_Position;
public:
	RenableObject(int x, int y, RENDERTYPE RENDERTYPETOSET){CURRENTRENDERTYPE = RENDERTYPETOSET;p_s_Position = new s_Vector;p_s_Position->i_x = x;p_s_Position->i_y = y;}
	s_Vector * get_Position(){return p_s_Position;}
};



#endif