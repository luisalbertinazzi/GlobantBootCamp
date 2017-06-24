#include "stdafx.h"
#include "TetroN.h"


TetroN::TetroN()
{
}


TetroN::~TetroN()
{
}

int TetroN::getPiece(int pX, int pY)
{
	switch (actualRotation)
	{
	case Nver:
		return (piece[0][pX][pY]);
		break;

	case Nhor:
		return (piece[1][pX][pY]);
		break;
	}
}

void TetroN::rotateRight()
{
	switch (actualRotation)
	{
	case Nhor: actualRotation = Nver;
		break;
	case Nver:actualRotation = Nhor;
		break;
	}
}

void TetroN::rotateLeft()
{
	switch (actualRotation)
	{
	case Nhor: actualRotation = Nver;
		break;
	case Nver:actualRotation = Nhor;
		break;
	}
}
