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
	char piece[4][TetroHAndW][TetroHAndW]{
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 1, 0, 0 }
		}
	};

};

