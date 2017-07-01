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
const  int xPositionNewPiece = 0, yPositionNewPiece = 0;

class Game
{
public:
	Game(Tetromino *piece, Tetromino *nextpiece, Board *board);
	~Game();
	void LvlUp();
	void NewTetro( int rand );
	

	int getLvl();
	int getWaitTime();

	
	int X, Y;//this is where the piece is falling


    int xInPixels(int x);
	int yInPixels(int y);
	
	

private:
	Board *pBoard;
	Tetromino *pPiece, *pNextPiece;
	
	int Lvl, WaitTime;
	
	void Init();
	
	

	
	int RandNumber();
	
};

