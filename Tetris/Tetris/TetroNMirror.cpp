#include "stdafx.h"
#include "TetroNMirror.h"


TetroNMirror::TetroNMirror()
{
}


TetroNMirror::~TetroNMirror()
{
}

int TetroNMirror::getPiece(int pX, int pY)
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

void TetroNMirror::rotateRight()
{
	switch (actualRotation)
	{
	case Nhor: actualRotation = Nver;
		break;
	case Nver:actualRotation = Nhor;
		break;
	}
}

void TetroNMirror::rotateLeft()
{
	switch (actualRotation)
	{
	case Nhor: actualRotation = Nver;
		break;
	case Nver:actualRotation = Nhor;
		break;
	}
}
