#include "stdafx.h"
#include "Game.h"


Game::Game()
{


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

void Game::setImages()
{
	Window.loadImg("Img/bg.png");

	tTile1.loadImg("Img/1.png");
	tTile2.loadImg("Img/1.png");
	tTile3.loadImg("Img/1.png");
	tTile4.loadImg("Img/1.png");

	nextTile1.loadImg("Img/1.png");
	nextTile2.loadImg("Img/1.png");
	nextTile3.loadImg("Img/1.png");
	nextTile4.loadImg("Img/1.png");


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
	int a = RandNumber();
	NewTetro(a);
	pPiece = pNextPiece;
	NewTetro(a);
	X = initialPositionX;
	Y = initialPositionY;
	
}

void Game::DrawTetro()
{
	for (size_t i = X, t = 0; i <= X + TetroHAndW; ++i, ++t)
	{
		for (size_t j = Y, t2 = 0; j <= Y + TetroHAndW; ++j, ++t2)
		{
			if (pPiece->getPiece[t][t2] != 0)
			{
				if (pPiece->getPiece[t][t2] == 2)
						tTile1.render(i, j);

			}
		}

	}

}

int Game::RandNumber()
{
	int randNum = rand() % 7; //random number beetween 0 and 6
	return randNum;
}
