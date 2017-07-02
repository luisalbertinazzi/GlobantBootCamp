#include "stdafx.h"
#include "TetroL.h"


TetroL::TetroL()
{
}


TetroL::~TetroL()
{
}
int TetroL::getPiece(int pX, int pY) {
	return (piece[static_cast<int>(actualRotation)][pX][pY]);
}
void TetroL::rotateRight() { 

	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 4);

}

void TetroL::rotateLeft()
{

	actualRotation = static_cast<rotation>(static_cast<int>(actualRotation) - 1);

	if (static_cast<int>(actualRotation) == -1)
		actualRotation = Ldown;
}


