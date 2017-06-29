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
	

}

int Game::RandNumber()
{
	int randNum = rand() % 7; //random number beetween 0 and 6
	return randNum;
}