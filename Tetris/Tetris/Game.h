#pragma once

#include "Board.h"
#include "SDLImplementation.h"
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

Graphs Window;

Graphs tTile1, tTile2, tTile3, tTile4;

Graphs nextTile1, nextTile2, nextTile3, nextTile4;


class Game
{
public:
	Game();
	~Game();
	void LvlUp();
	void NewTetro( int rand );
	void DrawAll();

	int getLvl();
	int getWaitTime();

	int X, Y;//this is where the piece is falling

	const short int initialPositionX = 3, initialPositionY = 1;
	const  int xPositionNewPiece = 0, yPositionNewPiece = 0;

private:
	Board *pBoard;
	Tetromino *pPiece, *pNextPiece;
	
	int Lvl=0, WaitTime=800;
	
	void Init();
	void DrawTetro();
	void DrawBoard();

	int RandNumber();
	
};

