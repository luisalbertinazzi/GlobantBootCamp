#pragma once

#include "Board.h"
#include "Rect.h"
#include <time.h>
#include <string>

/*tetrominos*/
#include "Tetromino.h"
#include  "Square.h"
#include  "TetroI.h"
#include  "TetroL.h"
#include  "TetroLMirror.h"
#include  "TetroN.h"
#include  "TetroNMirror.h"
#include  "TetroT.h"

/*Scene graphs*/



const int offSetBoard = 10 ;
const int tileHeightAndWidht = 30;
const short int initialPositionX = 3, initialPositionY = 0;
const  int xPositionNewPiece = 329, yPositionNewPiece = 45;

class Game
{
public:
	Game(Tetromino *piece, Tetromino *nextpiece, Board *board);
	~Game();
	void LvlUp();
	void NewTetro( int rand );
	

	int getLvl();
	int getWaitTime();

	void drawAll(Rect &rect, Rect &BG, Rect &rect2);
	int xOfThePieceInTheBoard, yOfThePieceInTheBoard;//this is where the piece is falling
	void getNextPiece();

    int xInPixels(int x);
	int yInPixels(int y);
	Tetromino *pPiece;
	int RandNumber();

private:
	Board *pBoard;
	Tetromino *pNextPiece;
	
	int Lvl, WaitTime;
	
	void Init();
	
	

	
	
	
};

