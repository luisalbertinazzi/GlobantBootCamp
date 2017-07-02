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
	return (piece[static_cast<int>(actualRotation)][pX][pY]);
}

void TetroN::rotateRight()
{
	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 2);
}

void TetroN::rotateLeft()
{
	if (actualRotation == rotation::Nver)
		actualRotation = static_cast<rotation>(1);
	else
		actualRotation = static_cast<rotation>(static_cast<int>(actualRotation) - 1);
}
