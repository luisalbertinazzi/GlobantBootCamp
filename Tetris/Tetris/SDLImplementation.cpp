#include "stdafx.h"
#include "SDLImplementation.h"




SDLImplementation::SDLImplementation()
{
	closed = !Init();
}

SDLImplementation::~SDLImplementation()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

bool SDLImplementation::isClosed()
{
	return closed;
}

void SDLImplementation::pollEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			closed = true;
			break;
		default:
			break;
		}
	}
}

bool SDLImplementation::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) //initialization of the SDL, we have to make sure it works so I put a little msg in case something is wrong
	{
		std::cerr << "There was an error! (Hubo un error) SDL_Error: ", SDL_GetError();
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "There was an error with IMG initialization! (Hubo un error) ";
	}

	pWindow = SDL_CreateWindow("BootCamp Tetris",
		PositionOfB,
		(PositionOfB - 100),
		ScrW, ScrH,
		0);

	if (pWindow == nullptr)
	{
		std::cerr << "Failed to create the window! (Hubo un error) ";
		return false;
	}

	CreateRender();



	pScreen = IMG_LoadTexture(pRenderer, "Img/BG.png");

	BGround.x = 0;
	BGround.y = 0;
	BGround.w = ScrW;
	BGround.h = ScrH;
	SDL_RenderCopy(pRenderer, pScreen, NULL, &BGround);

	SDL_RenderPresent(pRenderer);


	return true;
}

void SDLImplementation::CreateRender()
{
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (pRenderer == nullptr)
	{
		std::cerr << "Failed to create renderer! (Hubo un error) ";
	}
}

void SDLImplementation::LoadText()
{ 
 	pTile = IMG_LoadTexture(pRenderer, "Img/1.png"); //this is a set for the texture of the tile
	BGround.x = 0;
	BGround.y = 0;
	BGround.w = 30;
	BGround.h = 29;
}

void SDLImplementation::DestroyWindow()
{
	SDL_DestroyTexture(pScreen);
	SDL_DestroyTexture(pTile);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}

void SDLImplementation::Update()
{

}

int SDLImplementation::Events()
{
	SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				SDL_DestroyWindow(pWindow);
				exit(3);
				break;

			case SDL_KEYDOWN:
				return event.key.keysym.sym;

			default:
				break;
			}
		}
	
	return -1;
}
