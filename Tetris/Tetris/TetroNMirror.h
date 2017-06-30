#pragma once
#include "Tetromino.h"
class TetroNMirror : public Tetromino
{
public:
	TetroNMirror();
	~TetroNMirror();
	int getPiece(int pX, int pY);
	void rotateRight();
	void rotateLeft();
private:
	enum rotation { Nver, Nhor };
	rotation actualRotation = Nver;
	char piece[2][4][4]{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 2, 1, 0 },
			{ 0, 0, 1, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 2, 1, 0 },
			{ 1, 1, 0, 0 }
		},
	};

};

