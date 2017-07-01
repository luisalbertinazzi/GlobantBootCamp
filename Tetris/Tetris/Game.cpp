#include "stdafx.h"
#include "Game.h"


Game::Game(Tetromino *piece, Tetromino *nextpiece, Board *board) :
	pPiece(piece), pNextPiece(nextpiece), pBoard(board)
{
	Init();
	Lvl = 0;
	WaitTime = 800;
	
}


Game::~Game()
{

}

void Game::LvlUp()
{
	Lvl++;

	WaitTime = 800 - (30 * Lvl);
}

void Game::NewTetro(int rand)
{
	switch (rand)
	{
	case 0:
		pNextPiece = new Square;
		break;
	case 1:
		pNextPiece = new TetroI;
		break;
	case 2:
		pNextPiece = new TetroL;
		break;
	case 3:
		pNextPiece = new TetroLMirror;
		break;
	case 4:
		pNextPiece = new TetroN;
		break;
	case 5:
		pNextPiece = new TetroNMirror;
		break;
	case 6:
		pNextPiece = new TetroT;
		break;
	}

}


int Game::getLvl()
{
	return Lvl;
}

int Game::getWaitTime()
{
	return WaitTime;
}

void Game::Init() //Selects the new tetromino
{
	int a = RandNumber(), b;
	NewTetro(a);
	pPiece = pNextPiece;
	do
	{
		b = RandNumber();
	} while (b == a);

	NewTetro(b);
	X = initialPositionX;
	Y = initialPositionY;	
}



int Game::xInPixels(int x)
{
	int xPixels = x * tileHeightAndWidht + offSetBoard;
	return xPixels;
}

int Game::yInPixels(int y)
{
	int yPixels = y * tileHeightAndWidht+ offSetBoard;
	return yPixels;
}

int Game::RandNumber()
{
	srand(time(NULL));
	return rand() % 6 + 0;
}
