#include "stdafx.h"
#include "TetroL.h"


TetroL::TetroL()
{
}


TetroL::~TetroL()
{
}
int TetroL::getPiece(int pX, int pY) {
	switch (actualRotation)
	{
	case L: 
		return (piece [0][pX][pY]);
		break;
	case Lup:return (piece[1][pX][pY]);
		break;
	case Lleft:return (piece[2][pX][pY]);
		break;
	case Ldown: return (piece[3][pX][pY]);
		break;
	}

}
void TetroL::rotateRight() { 
	switch (actualRotation)
	{
	case L: actualRotation = Ldown;
		break;
	case Lup:actualRotation = L;
		break;
	case Lleft:actualRotation = Lup;
		break;
	case Ldown: actualRotation = Lleft;
		break;
	}
}

void TetroL::rotateLeft()
{
	switch (actualRotation)
	{
	case L: actualRotation = Lup;
		break;
	case Lup:actualRotation = Lleft;
		break;
	case Lleft:actualRotation = Ldown;
		break;
	case Ldown: actualRotation = L;
		break;
	}
}


