#include "stdafx.h"
#include "TetroI.h"





TetroI::TetroI()
{
}


TetroI::~TetroI()
{
}

int TetroI::getPiece(int pX, int pY)
{
	switch (actualRotation)
	{
	case Ihor:
		return (piece[0][pX][pY]);
		break;
	case Iver:return (piece[1][pX][pY]);
		break;
	
	}

}
void TetroI::rotateRight() {
	switch (actualRotation)
	{
	case Ihor: actualRotation = Iver;
		break;
	case Iver:actualRotation = Ihor;
		break;
	
	}
}

void TetroI::rotateLeft()
{
	switch (actualRotation)
	{
	case Ihor: actualRotation = Iver;
		break;
	case Iver:actualRotation = Ihor;
		break;
	}
}
