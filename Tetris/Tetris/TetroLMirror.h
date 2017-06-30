#pragma once
#include "Tetromino.h"
class TetroLMirror : public Tetromino
{
public:
	TetroLMirror();
	~TetroLMirror();
	int getPiece(int pX, int pY);
	void rotateRight();
	void rotateLeft();
private:
	enum rotation { L, Lup, Lleft, Ldown };
	rotation actualRotation = L;
	char piece[4][4][4]{
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 2, 0, 0 },
			{ 1, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 1, 0, 0, 0 },
			{ 1, 2, 1, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 2, 0, 0 },
			{ 0, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 2, 1, 0 },
			{ 0, 0, 1, 0 }
		}
	};


};

