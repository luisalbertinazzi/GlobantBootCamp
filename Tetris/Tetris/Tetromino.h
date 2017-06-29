#pragma once
/*
This is not an overcomplicated class.  It has a constructor, a destructor and 3 methods to control the piece and its rotation
The derived types of this class are: TetroL, TetroLMirror, TetroI, Square, TetroN, TetroNmirror and TetroT. 

Because this is an abstract class, all the derived types must have an implimentation of the virtual methods

*/

unsigned const short  TetroHAndW = 4;

class Tetromino
{
public:
	Tetromino();
	~Tetromino();


	virtual int getPiece(int pX, int Py) = 0;  //This we will use to get the array where the piece is stored
	virtual void rotateRight() = 0;  // The rotate methods are in charge of change the ACTUAL ROTATION of the tetromino
	virtual void rotateLeft() = 0;

private:
	
};

/*Franco Amatta*/

