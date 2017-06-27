#include "stdafx.h"
#include "Square.h"


int Square::getPiece(int pX, int pY)
{
	return (piece[pY][pX]);
}

void Square::rotateRight()
{
	/*no rotation*/
}

void Square::rotateLeft()
{ /*no rotation*/
}

Square::Square()
{
}


Square::~Square()
{
}
