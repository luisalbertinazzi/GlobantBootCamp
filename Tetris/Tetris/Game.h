#pragma once

#include "Board.h"
#include "SDLImplementation.h"
#include <time.h>

/*tetrominos*/
#include "Tetromino.h"
#include  "Square.h"
#include  "TetroI.h"
#include  "TetroL.h"
#include  "TetroLMirror.h"
#include  "TetroN.h"
#include  "TetroNMirror.h"
#include  "TetroT.h"


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

	int X, Y;
	const int initialPositionX = 3, initialPositionY = 1;


private:
	Board *pBoard;
	Tetromino *pPiece, *pNextPiece;
	SDLImplementation *pVentana;

	int Lvl=0, WaitTime=800;
	
	void Init();
	void DrawTetro();
	void DrawBoard();

	int RandNumber();
	
};

