#include "stdafx.h"
#include "Window.h"
#include "SDL_image.h"


Window::Window(int width, int height, int posX, int posY):
windowW(width), windowH(height), windowPosX(posX), windowPosY(posY)
{
		closed = !init();
	
}


Window::~Window()
{
	SDL_DestroyRenderer(pRender);
	SDL_DestroyWindow(pWindow);
	IMG_Quit();
	SDL_Quit();
}

bool Window::isClosed()
{
	return closed;
}

void Window::event()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			closed = true;
			break;
		default:
			break;
		}
	}
}

void Window::clear() const
{
	SDL_RenderPresent(pRender);
	
	SDL_SetRenderDrawColor(pRender, 0, 0, 200, 255);
	SDL_RenderClear(pRender);
	
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 || SDL_Init(SDL_INIT_AUDIO) != 0 )
	{
		std::cerr << "Failed to initialize SDL!   ";
			return false;
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "Failed to initialize SDL_IMAGE!   ";
		return false;
	}
	pWindow = SDL_CreateWindow("Tetris BootCamp",
		windowPosX,
		windowPosY,
		windowW, windowH, SDL_WINDOW_SHOWN);
		
	if (pWindow == nullptr)
	{
			std::cerr << "Failed to create window!   ";
				return false;
	}
	pRender = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	return true;
}

void Window::freeTexture(SDL_Texture * txture)
{
	if (txture != nullptr)
	{
		SDL_DestroyTexture(txture);
		txture = nullptr;
		
	}
}
