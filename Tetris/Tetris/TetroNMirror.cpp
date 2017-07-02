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
	return (piece[actualRotation][pX][pY]);
}

void TetroNMirror::rotateRight()
{
	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 2);
}

void TetroNMirror::rotateLeft()
{
	if (actualRotation == rotation::Nver)
		actualRotation = static_cast<rotation>(1);
	else
		actualRotation = static_cast<rotation>(static_cast<int>(actualRotation) - 1);
	
}
