#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

#define PositionOfB 320
#define TileHAndW 30

enum color {RED, BLACK, BLUE, YELLOW, ORANGE};

class SDLImplementation
{
public:
	SDLImplementation();
	~SDLImplementation();

	void Update();
	int Events();
	
	bool isClosed();

	void pollEvents();
	
private:
	/*I'm using p before the name of the pointers so I know they are pointers*/
	SDL_Texture *pTile = NULL, *pScreen = NULL; //tile of the piece and background
	SDL_Window *pWindow = NULL; //our window 
	SDL_Renderer *pRenderer = NULL;
	SDL_Rect BGround, Tile;

	bool closed = false;

	const int ScrW = 412;
	const int ScrH = 600;



	bool Init();
	void CreateRender();
	void LoadText();
	void DestroyWindow();
};

