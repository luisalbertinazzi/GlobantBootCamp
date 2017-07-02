

#include "stdafx.h"
#include "Window.h"
#include "Rect.h"
#include "Game.h"
#include "Tetromino.h"
#include "Board.h"
#undef main

unsigned short int windowW = 455;
unsigned short int windowH = 621;
unsigned short int pieceInitPosX = 10;
unsigned short int pieceInitPosY = 10;


int main()
{

	Window window(windowW, windowH, 100, 150);
	
	Rect BG(window, windowW, windowH, 0, 0, "Images/BG.png");
	Rect rect(window, 30, 30, "2.png");
	Rect rect2(window, 30, 30, "Images/2_1.png");
	Board board;
	
	Tetromino *tetro = nullptr, *newTetro = nullptr;
	Game game(tetro, newTetro, &board);
	
	unsigned long mTime1 = SDL_GetTicks();

	while (!window.isClosed())
	{
		/*Draw scene*/
		unsigned long mTime2 = SDL_GetTicks();
		game.drawAll(rect, BG, rect2 );
		window.clear();
		window.event();

		/* Store o move the piece down when time is over*/
		if (game.getWaitTime() < (mTime2 - mTime1)) //if wait time passed
		{

			rect.changeXandYto(game.xInPixels(game.xOfThePieceInTheBoard), game.yInPixels(game.yOfThePieceInTheBoard)); //changes the rectangle's position 
			

			if (board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard)) //can the piece move there?
			{
				game.yOfThePieceInTheBoard += 1;
			}
			else
			{
				board.Store(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard);
				board.CheckAndDelete();
				game.getNextPiece();
				game.NewTetro(game.RandNumber());
				game.yOfThePieceInTheBoard = initialPositionY;
				game.xOfThePieceInTheBoard = initialPositionX;	

			}
			
			mTime1 = SDL_GetTicks();
			std::cout << game.yOfThePieceInTheBoard << "    paso el tiempo";
		}


	}

	

    return 0;
}

