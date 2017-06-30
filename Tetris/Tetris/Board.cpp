#include "stdafx.h"
#include "Board.h"


Board::Board(int ScrHeight)
{
	Screen = ScrHeight;

}

Board::~Board()
{
}

void Board::Store(Tetromino *tetro, int x, int y)
{
	for (int i = x, t = 0; i < x + 4; i++, t++) 
	{/*  This was a tricky one for me to understand. It was necessary to get the position of the TETROMINO array to start where we needed to store it,
	     so "i" will be the BOARD position and "t" the TETROMINO position. 4 is the number of rows and columns of the TETROMINO (it'd be better if
		 you draw it to understand it)*/

		for (int i2 = y, t2 = 0; i2 < y + 4; i2++, t2++) // we move the X axis
		{
			if (tetro->getPiece(t, t2) != 0) //checks the position in the array of the piece
				ArrayBoard[i][i2] = OC;
		}

	}
}



void Board::Initializate()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			ArrayBoard[i][j] = FREE;

	for (int i = 0; i < 20; i++) //the last column will be filled with OCUPPIED so then we can check for collisions with the limit of the board
		ArrayBoard[i][10] = OC;

	
}
