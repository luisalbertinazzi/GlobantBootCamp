#pragma once
#include "Tetromino.h" // We need to include the piece that we'll store

//  Board is a class that just knows how to STORE values, checks collisions and deletes lines. Note that this class has lots of comments, that's just for this class
// all the other classes will follow the same ordering of data and methods so we won't need such comments

class Board
{
public:
	Board(int ScrHeight); // The constructor will take with it the height of the screen
	~Board();

	
	void Store(Tetromino *tetro, int x, int y); //It takes the tetromino array and the position where we need to store it
	void CheckAndDelete();// checks lines that need to be erased (bc they're occupied)

	bool Collision(Tetromino *tetro, int x, int y);//checks collisions

	

private:
	
	enum {OC, VACANT};

	
	int ArrayBoard[20][12]; // You'll notice that the board is actully 20x10, that's because we need the extra line tobe filled so the pieces have a limit
	int Screen;

	
	void Initializate();// the board will be filled with "VACANT"
	void DeleteOneLine(int y); //This method will delete only ONE line of the array, and then it will bring all the pieces one space down
	bool CheckPosition(int x, int y);// tells if the position is free or occupied

};



/*Franco Amatta*/