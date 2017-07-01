#pragma once
#include "Tetromino.h" // We need to include the piece that we'll store

//  Board is a class that just knows how to STORE values, checks collisions and deletes lines. Note that this class has lots of comments, that's just for this class
// all the other classes will follow the same ordering of data and methods so we won't need such comments
 unsigned const short BoardWidht = 10;
 unsigned const short  BoardHeight = 20;


class Board
{
public:
	Board(); // The constructor will implement initializate
	~Board();

	
	void Store(Tetromino * const tetro, unsigned short int x, unsigned short int y); //It takes the tetromino array and the position where we need to store it

	void CheckAndDelete();// checks lines that need to be erased (bc they're occupied)

	bool Collision(Tetromino * const tetro, unsigned short int x, unsigned short int y);//checks collisions

	
	

private:
	
	enum vFill {VACANT, OC};

	
	int ArrayBoard[BoardHeight][BoardWidht]; 
	

	
	void Initializate();// the board will be filled with "VACANT"
	void DeleteOneLine(unsigned short int y); //This method will delete only ONE line of the array, and then it will bring all the pieces one space down
	bool CheckPosition(unsigned int x, unsigned int y);// tells if the position is free or occupied

};



/*Franco Amatta*/