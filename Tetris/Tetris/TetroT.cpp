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
	return (piece[static_cast<int>(actualRotation)][pY][pX]);
}

void TetroT::rotateRight()
{
	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 4);
}

void TetroT::rotateLeft()
{
	
		actualRotation = static_cast<rotation>(static_cast<int>(actualRotation) - 1);

		if (static_cast<int>(actualRotation) == -1)
			actualRotation = Tleft;

}
