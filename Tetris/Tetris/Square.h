#pragma once
#include "Tetromino.h"
class Square : public Tetromino

{
public:
	int getPiece(int pX, int pY);
	void rotateRight();
	void rotateLeft();

	Square();
	~Square();
private:
	char piece[TetroHAndW][TetroHAndW]{                  //It doesn't have rotations
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 2, 1, 0 },
			{ 0, 0, 0, 0 }
			};

};

