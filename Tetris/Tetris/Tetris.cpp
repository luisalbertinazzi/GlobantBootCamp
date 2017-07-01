

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

	Board board;
	
	Tetromino *tetro = nullptr, *newTetro = nullptr;
	Game game(tetro, newTetro, &board);

	unsigned long mTime1 = SDL_GetTicks();

	while (!window.isClosed())
	{
		BG.draw();
		unsigned long mTime2 = SDL_GetTicks();
		rect.draw();
		window.clear();
		window.event();
		if (800< (mTime2 - mTime1)) //if wait time passed
		{

			rect.changeXandYto(game.xInPixels(game.X), game.yInPixels(game.Y));
			game.Y++;

			/*if (board.CanIMove(game.pPiece, game.X, game.Y))
			{
				game.Y++;
			}
			else
			{
				board.Store(game.pPiece, game.X, game.Y);
				board.CheckAndDelete();
				game.getNextPiece();
				game.NewTetro(game.RandNumber(0, 6));
				game.Y = 0;
				game.X = initialPositionX;

			}*/
			mTime1 = SDL_GetTicks();
			std::cout << game.Y << "    paso el tiempo";
		}


	}

	

    return 0;
}

