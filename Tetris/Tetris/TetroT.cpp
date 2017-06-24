#include "stdafx.h"
#include "TetroT.h"


TetroT::TetroT()
{
}


TetroT::~TetroT()
{
}

int TetroT::getPiece(int pX, int pY)
{
	switch (actualRotation)
	{
	case T:
		return (piece[0][pX][pY]);
		break;
	case Tright:return (piece[1][pX][pY]);
		break;
	case Tup:return (piece[2][pX][pY]);
		break;
	case Tleft: return (piece[3][pX][pY]);
		break;
	}
}

void TetroT::rotateRight()
{
	switch (actualRotation)
	{
	case T: actualRotation = Tleft;
		break;
	case Tright:actualRotation = T;
		break;
	case Tup:actualRotation = Tright;
		break;
	case Tleft: actualRotation = Tup;
		break;
	}

}

void TetroT::rotateLeft()
{
	switch (actualRotation)
	{
	case T: actualRotation = Tright;
		break;
	case Tright:actualRotation = Tup;
		break;
	case Tup:actualRotation = Tleft;
		break;
	case Tleft: actualRotation = T;
		break;
	}
}
