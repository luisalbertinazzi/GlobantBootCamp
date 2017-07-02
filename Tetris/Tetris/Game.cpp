#include "stdafx.h"
#include "Game.h"


Game::Game(Tetromino *piece, Tetromino *nextpiece, Board *board) :
	pPiece(piece), pNextPiece(nextpiece), pBoard(board)
{
	Init();
	Lvl = 0;
	WaitTime = 1500;
	
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

void Game::drawAll(Rect &rect, Rect &BG, Rect &rect2)
{
	BG.draw();
	int mPixelsX = xInPixels(xOfThePieceInTheBoard);
	int mPixelsY = yInPixels(yOfThePieceInTheBoard);
	for (size_t x = 0; x < TetroHAndW; ++x)
	{
		for (size_t y = 0; y < TetroHAndW; ++y)
		{
			if (pPiece->getPiece(x, y) != 0)
			{
				rect.changeXandYto( mPixelsX + ((x)*tileHeightAndWidht), (mPixelsY + ((y)*tileHeightAndWidht)));
				rect.draw();
			}
			if (pNextPiece->getPiece(x, y) != 0)
			{
				rect2.changeXandYto((x*tileHeightAndWidht) + xPositionNewPiece, (y*tileHeightAndWidht) + yPositionNewPiece);
				rect2.draw();
			}
		}

	}

	for (size_t i = 0; i <BoardHeight; ++i)
	{
		for (size_t j = 0; j <  BoardWidht; ++j)
		{
			if (pBoard->returnPosition(j, i)!=0)
			{
				//std::cout <<"\n"<< pBoard->returnPosition(j, i)<< "Array filled with that \n" ;
				rect2.changeXandYto(xInPixels(j), xInPixels(i));
				//std::cout << "\n" << j << "   " << xInPixels(j) << "   Rendered tile2 here   x  ";
				//std::cout << "\n" << i << "   " << xInPixels(i) << "   Rendered tile2 here  y   ";
				rect2.draw();
				
			}
		}
		
	}
	
	
}

void Game::getNextPiece()
{
	pPiece = pNextPiece;
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
	xOfThePieceInTheBoard = initialPositionX;
	yOfThePieceInTheBoard = 0;	
}



int Game::xInPixels(int x)
{
	
	int xPixels = x * tileHeightAndWidht + offSetBoard;
	
	return xPixels;
}

int Game::yInPixels(int y)
{
	int yPixels = (y) * tileHeightAndWidht+ offSetBoard;
	
	return yPixels;
}

int Game::RandNumber()
{
	srand(time(NULL));
	return rand() % 6 + 0;
}
