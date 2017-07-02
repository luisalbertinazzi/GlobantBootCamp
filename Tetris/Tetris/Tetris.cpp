

#include "stdafx.h"
#include "Window.h"
#include "Rect.h"
#include "Game.h"
#include "Tetromino.h"
#include "Board.h"
#include <SDL.h>
#undef main

unsigned short int windowW = 455;
unsigned short int windowH = 621;
unsigned short int pieceInitPosX = 10;
unsigned short int pieceInitPosY = 10;

void pullEvents(Window &window, Game &game, Board &board) {

	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				if (board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard - 1, game.yOfThePieceInTheBoard))
				{
					--game.xOfThePieceInTheBoard;
				}
				break;
			case SDLK_RIGHT:
				if (board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard + 1, game.yOfThePieceInTheBoard))
				{
				++game.xOfThePieceInTheBoard;
				}
				break;
			case SDLK_DOWN:
				if (board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard + 1 ))
				{
					++game.yOfThePieceInTheBoard;
				}
				break;
			case SDLK_UP:
				
				game.pPiece->rotateRight();
				if (!board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard ))
				{
					game.pPiece->rotateLeft();
				}
				

				break;
			case SDLK_z :
				game.pPiece->rotateLeft();
				if (!board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard))
				{
					game.pPiece->rotateRight();
				}

				break;
			default:
				break;
			}
		}
	}
	window.event(event);
}


int main()
{

	Window window(windowW, windowH, 100, 150);
	
	Rect BG(window, windowW, windowH, 0, 0, "Images/BG.png");
	Rect YouLose(window, windowW, windowH, 0, 0, "Images/GO.png");
	Rect Continue(window, windowW, windowH, 0, 0, "Images/Continue.png");
	Rect rect(window, 30, 30, "2.png");
	Rect rect2(window, 30, 30, "Images/2_1.png");
	Board board;
	
	Tetromino *tetro = nullptr, *newTetro = nullptr;
	Game game(tetro, newTetro, &board);
	
	unsigned long mTime1 = SDL_GetTicks();

	while (!window.isClosed())
	{
		if (!board.CanThePieceMove(game.pPiece, initialPositionX, initialPositionY))
		{
			YouLose.draw();
			window.clear();
			SDL_Delay(1500);
			break;
		}
		/*movement*/
		pullEvents(window, game, board);
			
		/*Draw scene*/
		unsigned long mTime2 = SDL_GetTicks();
		game.drawAll(rect, BG, rect2 );
		window.clear();
		//int p = 0;
		//std::cout << "\n posicion actual:  x="<< game.xOfThePieceInTheBoard<< " y= "  << game.yOfThePieceInTheBoard ;
		/* Store o move the piece down when time is over*/
		if (game.getWaitTime() < (mTime2 - mTime1)) //if wait time passed
		{

			rect.changeXandYto(game.xInPixels(game.xOfThePieceInTheBoard), game.yInPixels(game.yOfThePieceInTheBoard)); //changes the rectangle's position to be shown
			

			if (board.CanThePieceMove(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard+1)) 
			{
				++game.yOfThePieceInTheBoard;
			}
			else
			{			
				
					board.Store(game.pPiece, game.xOfThePieceInTheBoard, game.yOfThePieceInTheBoard);
					board.CheckAndDelete();
					game.getNextPiece();
					game.NewTetro(game.RandNumber());
					game.yOfThePieceInTheBoard = initialPositionY;
					game.xOfThePieceInTheBoard = initialPositionX;
					//p++;
					//if (p == 2 || p ==1)
					//	system("PAUSE");

			}
			
			mTime1 = SDL_GetTicks();
			std::cout << game.yOfThePieceInTheBoard << "    paso el tiempo";
		}


	}

	

    return 0;
}

