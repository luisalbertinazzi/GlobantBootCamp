#include "stdafx.h"
#include "TetroLMirror.h"


TetroLMirror::TetroLMirror()
{
}


TetroLMirror::~TetroLMirror()
{
}

int TetroLMirror::getPiece(int pX, int pY) {
	return (piece[static_cast<int>(actualRotation)][pY][pX]);
}
void TetroLMirror::rotateRight() {

	actualRotation = static_cast<rotation>((static_cast<int>(actualRotation) + 1) % 4);
}

void TetroLMirror::rotateLeft()
{
	actualRotation = static_cast<rotation>(static_cast<int>(actualRotation) - 1);

	if (static_cast<int>(actualRotation) == -1)
		actualRotation = Ldown;
}


