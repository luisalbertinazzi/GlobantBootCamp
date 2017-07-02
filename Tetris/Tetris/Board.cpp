#include "stdafx.h"
#include "Board.h"
#include <iostream>

Board::Board()
{
	Initializate();
}


Board::~Board()
{
}

void Board::Store( Tetromino* const tetro, unsigned short int x, unsigned short int y)
{
	for (int i = 0; i < TetroHAndW; ++i)
	{
		for (int j = 0; j < TetroHAndW; ++j) // we move the other axis
		{
			if (tetro->getPiece(i, j) !=0 ) //checks the position in the array of the piece
			{
				ArrayBoard[x+i-1][y+j-1] = OC;
				std::cout<<"\n" << x+i-1 <<"   "<< y+j-1 << "    Here is where i stored the piece      ";
			}
		}
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

bool Board::CanThePieceMove( Tetromino * const tetro, unsigned short int x, unsigned short int y)
{


	for (int i = 0; i <  TetroHAndW; ++i)//rows on the piece array
	{
		for (int j = 0; j < TetroHAndW; ++j) // we move the other axis, collumns on the piece array
		{
			/* Is the piece outside the limit*/

			if ((i +x )< 0 || (i + x)> BoardWidht - 1 || (j+y) > BoardHeight - 1)
			{
				if (tetro->getPiece(i, j) == 1)
				{
					return false;
				}
			}

			if (j >= 0) //collision with something stored
			{
				if ((tetro->getPiece(i, j) ==1 ) && (returnPosition(x+1, y+1) ==1  ))
				{
					return false;
				}
			}
		}		
	}

	return true;//There was no collision
}

int Board::returnPosition(int x, int y)
{
	
	return ArrayBoard[x][y];
}






bool Board::IsThisOC(unsigned int x, unsigned  int y)
{
	if (ArrayBoard[x][y] == VACANT)
	{
		return false;
	}
	if(ArrayBoard[x][y] == OC)
	{
		return true;
	}
}



void Board::Initializate()
{
	for (int y = 0; y < BoardHeight; ++y)
	{
		for (int x = 0; x < BoardWidht; ++x)
		{
			ArrayBoard[x][y] == 0;
			
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
