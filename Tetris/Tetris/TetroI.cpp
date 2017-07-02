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
	return (piece[static_cast<int>(actualRotation)][pX][pY]);
}

void TetroI::rotateRight() {
	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 2);
	}

void TetroI::rotateLeft(){
	if (actualRotation == rotation::Ihor)
	{
		actualRotation = Iver;
	}
	else
	{
		actualRotation = Ihor;
	}

	
		
}
