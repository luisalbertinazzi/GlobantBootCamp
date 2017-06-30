

#include "stdafx.h"
#include "Window.h"
#include "rect.h"
#undef main

unsigned short int windowW = 425;
unsigned short int windowH = 621;
unsigned short int pieceInitPosX = 10;
unsigned short int pieceInitPosY = 10;

int main()
{
	Window window(windowW, windowH, 100, 150);
	Rect BG(window, windowW, windowH, 0, 0, "Images/BG.png");
	Rect rect(window, 30, 30, pieceInitPosX, pieceInitPosY, "2.png" );

	while (!window.isClosed()) 
	{
		BG.draw();
		rect.draw();	
		window.event();
		window.clear();
		
	}
	

    return 0;
}

