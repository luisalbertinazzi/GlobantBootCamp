#pragma once
#include "SDL.h"
#include <iostream>
/*MANAGES THE WINDOW and ONLY THE WINDOW*/
class Window
{
public:
	Window( int widht, int height, int windowPosX, int windowPosY);
	~Window();
	bool isClosed();
	void event();
	void clear() const ;

private:// private methods
	bool init();
	void freeTexture(SDL_Texture *txture);

private:
	int windowW;
	int windowH;

	int windowPosX;
	int windowPosY;
	bool closed = false;
	SDL_Window *pWindow = nullptr;

protected:
	SDL_Renderer *pRender = nullptr; 
};

