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
	int t = 0;//rows on the piece array

	for (int i = x; i < x + TetroHAndW; ++i)
	{

		int t2 = 0;//collumns on the piece array

		for (int i2 = y; i2 < y + TetroHAndW; ++i2) // we move the other axis
		{
			if (tetro->getPiece(t, t2) == 1) //checks the position in the array of the piece
			{
				ArrayBoard[i][i2] = OC;
			}
			++t2;
		}

		++t;

	}
}

void Board::CheckAndDelete()
{
	/* this method works with "DeleteOneLine", so it can delete as many lines as necessary*/

	for (int i = 0; i < BoardHeight; i++) // we move through the ROWS
	{
		int j = 1;
		while (j <= BoardWidht)   // we need to see if all the positions in the row we are looking are filled
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
	int t = 0;//rows on the piece array

	for (int i = x; i < x + TetroHAndW; ++i)
	{
		int t2 = 0;//collumns on the piece array

		for (int i2 = y; i2 < y + TetroHAndW; ++i2) // we move the other axis
		{
			/* Is the piece outside the limit*/
			if (i < 0 ||
				i > BoardWidht - 1 ||
				i2 > BoardHeight - 1)
			{
				if (tetro->getPiece(t, t2) != 0)
					return false;
			}

			if (i2 >= 0)
			{
				if ((tetro->getPiece(t, t2) != 0) && (CheckPosition(i, i2) != 0))
					return false;
			}

			++t2;
		}
		++t;
	}

	return true;//There was no collision
}







bool Board::CheckPosition(unsigned int x, unsigned  int y)
{
	if (static_cast<vFill>(ArrayBoard[y][x]) == VACANT) return true;

	else return false;
}



void Board::Initializate()
{
	for (size_t x = 0; x < BoardWidht; ++x)
	{
		for (size_t y = 0; y < BoardHeight; ++y)
		{
			ArrayBoard[x][y] == VACANT;
		}

	}
	
}

void Board::DeleteOneLine(unsigned short int y)
{ 
	for (int j = y; j > 0; --j)
	{
		for (int i = 0; i < 11; ++i)
		{
			ArrayBoard[i][j] = ArrayBoard[i - 1][j];/*We start on the line we need to erase (j),
													and we go through that line equating values with the previous line  */
		}

	}

}
