#pragma once
#include "Tetromino.h"
class TetroT : public Tetromino
{
public:
	TetroT();
	~TetroT();
	int getPiece(int pX, int pY);
	void rotateRight();
	void rotateLeft();
	
private:
	enum rotation { T, Tright, Tup, Tleft };
	rotation actualRotation = Tleft;
	char piece[4][4][4]{
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 2, 1, 0 },
			{ 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 2, 1, 0 },
			{ 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 2, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 2, 0, 0 },
			{ 0, 1, 0, 0 }
		}
	};

};

