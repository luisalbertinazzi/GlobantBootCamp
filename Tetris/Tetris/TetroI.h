#pragma once
#include "Tetromino.h"
class TetroI : public Tetromino
{
public:
	int getPiece(int pX, int pY);
	void rotateRight();
	void rotateLeft();
	TetroI();
	~TetroI();
private:
	enum rotation { Iver, Ihor };   // "I" just has 2 possible positions
	rotation actualRotation = Ihor;
	char piece[2][4][4]{
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 2, 1, 1 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 2, 0, 0 },
			{ 0, 1, 0, 0 }
		}

		};

};

