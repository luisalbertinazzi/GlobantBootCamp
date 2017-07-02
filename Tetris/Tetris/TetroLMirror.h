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
	char piece[4][TetroHAndW][TetroHAndW]{
		{
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{			
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
		},
		{
			
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 0 }
		}
	};


};

