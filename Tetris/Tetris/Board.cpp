#include "stdafx.h"
#include "Board.h"


Board::Board()
{
	Initializate();
}


Board::~Board()
{
}

void Board::Store( Tetromino* const tetro, unsigned short int x, unsigned short int y)
{
	for (int i = x, t = 0; i < x + TetroHAndW; i++, t++) 
	{/*  This was a tricky one for me to understand. It was necessary to get the position of the TETROMINO array to start where we needed to store it,
	     so "i" will be the BOARD position and "t" the TETROMINO position. 4 is the number of rows and columns of the TETROMINO (it'd be better if
		 you draw it to understand it)*/

		for (int i2 = y, t2 = 0; i2 < y + TetroHAndW; i2++, t2++) // we move the other axis
		{
			if (tetro->getPiece(t, t2) != 0) //checks the position in the array of the piece
				ArrayBoard[i][i2] = OC;
		}
		/*ironically in the board array "x" is the Y axis and "y" is the X axis. This happens bc we have a 20x10 array and 20 are the rows (Y axis) and 10 the collumns (X axis)*/
	}
}

void Board::CheckAndDelete()
{
	/* this method works with "DeleteOneLine", so it can delete as many lines as necessary*/

	for (int i = 0; i < BoardHeight; i++) // we move through the ROWS
	{
		int j = 1;
		while (j <= BoardRealWidht)   // we need to see if all the positions in the row we are looking are filled
		{
			if (ArrayBoard[i][j] != OC) 
					break; //if ONE position isnt filled we just skip the addition on the accumulator "j" and breaks the loop. This is VERY important, if we don't break the loop it would continue for ever
			
			j++;
		}
		

		if (j == 11) //this means all positions were "OC"
		{
			DeleteOneLine(i); //we delete that line
			i = i - 1; //this iterates the method to check the line that we deleted again
		}
	}

}

bool Board::Collision( Tetromino * const tetro, unsigned short int x, unsigned short int y)
{
	for (int i = x, t = 0; i < x + TetroHAndW; ++i, ++t)
	{/* We use the same logic that the "store" method*/

		for (int i2 = y, t2 = 0; i2 < y + TetroHAndW; ++i2, ++t2) // we move the other axis
		{ 			
			if ((tetro->getPiece(t, t2) != 0) && (CheckPosition(i, i2) != 0)) 
				return false;
		}
	}
}







bool Board::CheckPosition(unsigned int x, unsigned  int y)
{
	if (static_cast<vFill>(ArrayBoard[y][x]) == VACANT) return true;

	else return false;
}



void Board::Initializate()
{
	for (int i = 1; i < 11; i++)
		for (int j = 0; j < BoardHeight; j++)
			ArrayBoard[j][i] = VACANT;

	for (int i = 0; i < BoardHeight; i++) 
	{
		ArrayBoard[i][0] = OC;  //the first column (and the last two) will be filled with OCUPPIED so then we can check for collisions with the limit of the board
		ArrayBoard[i][11] = OC; 
		ArrayBoard[i][12] = OC;
		
	}

	

	
}

void Board::DeleteOneLine(unsigned short int y)
{ 
	for (int i = y; i > 0 ; i--)
	{
		for (int j = 1; j < 11; j++)
		{
			ArrayBoard[i][j] = ArrayBoard[i - 1][j];/*Okay, lets read this. We start on the line we need to erase (i), and we go through that line equating values with the previous line  */
		}

	}

}
